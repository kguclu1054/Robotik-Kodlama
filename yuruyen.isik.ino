const int sure =1000;
void setup() {
for(int ledPin=2; ledPin<12; ledPin++){
 pinMode(ledPin,OUTPUT); 
 }

}

void loop() {
for(int ledPin=3; ledPin<11; ledPin++){
  digitalWrite(ledPin,HIGH);
  delay(sure);
  digitalWrite(ledPin,LOW); 
}
for(int ledPin=10; 2<ledPin; ledPin--){
  digitalWrite(ledPin,HIGH);
  delay(sure);
  digitalWrite(ledPin,LOW); 
 }
}
