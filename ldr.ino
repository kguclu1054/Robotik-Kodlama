void setup() {
  Serial.begin(9600);

}

void loop() {
 int LDRDeger = analogRead(A0);
 Serial.print("Işık Şiddeti");
 Serial.println(LDRDeger);
 delay(500);
 }
