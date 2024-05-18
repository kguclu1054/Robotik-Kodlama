int kledPin=3;
int yledPin=2;
int TCRT5000=8;

void setup() {
  Serial.begin(9600);
  pinMode(TCRT5000,INPUT);
  pinMode(kledPin,OUTPUT);
  pinMode(yledPin,OUTPUT);

}

void loop() {
 int bilgi_d =digitalRead(TCRT5000);
 int bilgi_a =analogRead(A0);

 Serial.println(bilgi_a);

 if(bilgi_d==1){
  digitalWrite(yledPin,HIGH);
  digitalWrite(kledPin,LOW);
  delay(100);
 }else{
  digitalWrite(yledPin,LOW);
  digitalWrite(kledPin,HIGH);
  delay(100);
 }

}
