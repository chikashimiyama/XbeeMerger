const int BAUD = 115200;
const int PORT0 = 0;
const int PORT1 = 1;

// simple USART merger
// it just checks hardware serial 2 and 3 and forwards them to Serial port
// the MSB is the ID that indicates the source

void setup() {
  Serial.begin(BAUD); // to computer
  Serial2.begin(BAUD); // to XBEE1
  Serial3.begin(BAUD); // to XBEE2
}

void loop() {
  
  while (Serial2.available()) { 
    Serial.write(Serial2.read());
  }
  
  
  while (Serial3.available()) {
    uint8_t val = Serial3.read();
    val |= 128; // identifier
    Serial.write(val);
  }

  delay(5);
}