const int ledPin=9;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
}

void loop() {
 int ldr_sensor_deger=analogRead(A0);
 Serial.println(ldr_sensor_deger);
 if(ldr_sensor_deger<30){
  digitalWrite(ledPin,HIGH);
 }else{
  digitalWrite(ledPin,LOW);
 }
 
 delay(500);

}
