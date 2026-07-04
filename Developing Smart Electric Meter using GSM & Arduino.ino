#include <PZEM004Tv30.h>
#include<SoftwareSerial.h>
//pin configaration
#define PZEM_RX 12 
#define PZEM_TX 11
//SIM INSTALL
SoftwareSerial pzemserial(PZEM_RX,PZEM_TX);
PZEM004Tv30 pzem(pzemserial);
#define SIM800_TX 12 
#define SIM800_RX 10
SoftwareSerial sim800l(SIM800_TX,SIM800_RX);
unsigned long lastSMSTime=0;
const unsigned long smsInterval=300000;

void sendAT(String command) {
  sim800l.println(command);
  delay(1000);
  while(sim800l.available()) {
    Serial.write(sim800l.read());
  }
}

void sendSMS(String phoneNumber, String message) {
  sim800l.println("AT+CMGS=\"" + phoneNumber + "\"");
  delay(1000);
  sim800l.println(message);
  delay(1000);
  sim800l.write(26);
  delay(1000);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pzemserial.begin(9600);
  sim800l.begin(9600);
  delay(1000);

  sendAT("AT");
  sendAT("AT+CMGF=1");
}

void loop() {
  // put your main code here, to run repeatedly:
  float voltage=pzem.voltage();
  float current=pzem.current();
  float energy=pzem.energy();
  float frequency=pzem.frequency();

  if (isnan(voltage)|| isnan(current) || isnan(energy)|| isnan(frequency)){
    Serial.println("Error");
    return;
  }

  if(millis()-lastSMSTime>=smsInterval){
    lastSMSTime=millis();
    String message="Energy Meter\n";
    message+="Voltage:"+String(voltage)+"V\n";
    message+="Current:"+String(current)+"A\n";
    message+="Energy:"+String(energy)+"kWh\n";
    message+="Frequency:"+String(frequency)+"Hz\n";

    sendSMS("+88016788046382", message);
    delay(2000);
  }
}