void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int analogVal = analogRead(A1); // read the analog input on pin A0
  int binVal = map(analogVal, 0, 1023, 0, 15); // map the analog value to a 4-bit binary value (0-15)
  digitalWrite(2, bitRead(binVal, 0)); // output the 4-bit binary value to four digital outputs (pins 2-5)
  digitalWrite(3, bitRead(binVal, 1));
  digitalWrite(4, bitRead(binVal, 2));
  digitalWrite(5, bitRead(binVal, 3));
  Serial.println(binVal); // print the binary value to the Serial Monitor for debugging
  delay(100); // wait for 100 ms before taking the next reading
}