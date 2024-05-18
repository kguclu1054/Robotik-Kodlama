int ledPin=3;
int sensorPin=7;
boolean led_durum=false;
void setup() {
  Serial.begin(9600);
 pinMode(ledPin,OUTPUT);
 pinMode(sensorPin,INPUT);

}

void loop() {
  int sensor_durum=digitalRead(sensorPin);
  if(sensor_durum==0){
    if(!led_durum){
      digitalWrite(ledPin,HIGH);
      led_durum=true;
    }else if(led_durum){
      digitalWrite(ledPin,LOW);
      led_durum=false;
    }
  }
  Serial.println(sensorPin);
}
