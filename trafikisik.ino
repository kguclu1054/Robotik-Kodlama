const int aracKirmizi= 10;
const int aracSari= 9;
const int aracYesil= 8;
const int yayaKirmizi= 7;
const int yayaYesil= 6;

void setup() {
   pinMode(aracKirmizi,OUTPUT);
   pinMode(aracSari,OUTPUT);
   pinMode(aracYesil,OUTPUT);
   pinMode(yayaKirmizi,OUTPUT);
   pinMode(yayaYesil,OUTPUT);
}

void loop() {
  digitalWrite(yayaYesil,HIGH);
  digitalWrite(aracKirmizi,HIGH);
  delay(5000);
  digitalWrite(yayaYesil,LOW);
  digitalWrite(yayaKirmizi,HIGH);
  delay(1000);
  digitalWrite(yayaKirmizi,LOW);
  delay(1000);
  digitalWrite(yayaKirmizi,HIGH);
  delay(1000);
  digitalWrite(yayaKirmizi,LOW);
  delay(1000);
  digitalWrite(yayaKirmizi,HIGH);
  delay(3000);
  digitalWrite(aracKirmizi,LOW);
  digitalWrite(aracYesil,HIGH);
  delay(10000);
  digitalWrite(aracYesil,LOW);
  digitalWrite(aracSari,HIGH);
  delay(3000);
  digitalWrite(aracSari,LOW);
  digitalWrite(yayaKirmizi,LOW);
}
