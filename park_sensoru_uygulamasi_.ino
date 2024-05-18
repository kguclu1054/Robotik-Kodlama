#include <HCSR04.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>

#define OLED_RESET 4

Adafruit_SSD1306 display(OLED_RESET);


int trigPin = 9;
int echoPin = 10;

int kirmizi = 2;
int yesil = 3;
int sari = 4;
int mavi = 5;
int beyaz = 6;
const int buzzer=13;

long sure; // Süre değişkeni
int uzaklik; // Uzaklık değişkeni

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); // Buradaki hatayı düzelttim
  pinMode(kirmizi,OUTPUT);
  pinMode(yesil,OUTPUT);
  pinMode(sari,OUTPUT);
  pinMode(mavi,OUTPUT);
  pinMode(beyaz,OUTPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);

  // OLED ekranın başlatılması
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  // Ekran temizleniyor
  display.clearDisplay();

  // Yazı renk ve boyut ayarları
  display.setTextColor(WHITE);
  display.setTextSize(1.5);
  
}

void loop() {
  display.clearDisplay();
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  sure = pulseIn(echoPin, HIGH); // Fonksiyon adını düzelttim
  uzaklik = (sure / 2) / 29.154;

  Serial.print("Mesafe: "); // Yazım hatası düzeltildi
  Serial.print(uzaklik);
  Serial.println(" cm"); // Virgül ekledim
    
  if(uzaklik<=5){
    digitalWrite(kirmizi,HIGH);
    digitalWrite(buzzer,HIGH);
    delay(2500);
    digitalWrite(kirmizi,LOW);
    digitalWrite(buzzer,LOW);
    delay(1);
    digitalWrite(yesil,LOW);
    digitalWrite(sari,LOW);
    digitalWrite(mavi,LOW);
    digitalWrite(beyaz,LOW);
  }

  else if(uzaklik<=8){
    digitalWrite(yesil,HIGH);
    digitalWrite(buzzer,HIGH);
    delay(30);
    digitalWrite(yesil,LOW);
    digitalWrite(buzzer,LOW);
    delay(30);
    digitalWrite(kirmizi,LOW);
    digitalWrite(sari,LOW);
    digitalWrite(mavi,LOW);
    digitalWrite(beyaz,LOW);
  }

  else if(uzaklik<=12){
    digitalWrite(sari,HIGH);
    digitalWrite(buzzer,HIGH);
    delay(100);
    digitalWrite(sari,LOW);
    digitalWrite(buzzer,LOW);
    delay(100);
    digitalWrite(kirmizi,LOW);
    digitalWrite(yesil,LOW);
    digitalWrite(mavi,LOW);
    digitalWrite(beyaz,LOW);
  }

  else if(uzaklik<=15){
    digitalWrite(mavi,HIGH);
    digitalWrite(buzzer,HIGH);
    delay(300);
    digitalWrite(mavi,LOW);
    digitalWrite(buzzer,LOW);
    delay(300);
    digitalWrite(kirmizi,LOW);
    digitalWrite(yesil,LOW);
    digitalWrite(sari,LOW);
    digitalWrite(beyaz,LOW);
  }

  else if(uzaklik<=18){
    digitalWrite(beyaz,HIGH);
    digitalWrite(buzzer,HIGH);
    delay(500);
    digitalWrite(beyaz,LOW);
    digitalWrite(buzzer,LOW);
    delay(500);,
    digitalWrite(kirmizi,LOW);
    digitalWrite(yesil,LOW);
    digitalWrite(sari,LOW);
    digitalWrite(mavi,LOW);
    
  }
  else{
    digitalWrite(kirmizi,LOW);
    digitalWrite(yesil,LOW);
    digitalWrite(sari,LOW);
    digitalWrite(mavi,LOW);
    digitalWrite(beyaz,LOW);
  }

  delay(100);

   // İsimlerin yazdırılması
  display.setCursor(0, 0);
  display.println("uzaklik:");
  display.setCursor(0, 10);
  display.println(uzaklik);
  display.setCursor(25, 10);
  display.println("cm");

  // Ekranın güncellenmesi
  display.display();
  delay(100);
}
