
const int BAUD = 115200

void setup() {
  Serial.begin(BAUD); // to computer
  Serial1.begin(BAUD); // to XBEE1
  Serial2.begin(BAUD); // to XBEE2
}

void loop() {
  
  if (Serial1.available()) { 
    Serial.write(Serial.read());
  }

  if (Serial2.available()) {
    Serial.write(Serial2.read());
  }
}
