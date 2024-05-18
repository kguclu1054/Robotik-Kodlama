#include <Wire.h>
#include <Adafruit_SSD1306.h>

int sensorPin=A0;
int sensorDeger=0;
float gerilim=0;
float sicaklik=0;

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

void setup() {
 display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
 display.display();

}

void loop() {
sensorDeger = analogRead(sensorPin);
  gerilim = (sensorDeger / 1024.0) /5.0; // Değeri düzeltmek için * ile çarpılmalıdır.
  sicaklik = gerilim * 100.0;

  display.clearDisplay(); // Ekranı temizle

  display.setTextSize(1);      // Yazı boyutunu ayarla
  display.setTextColor(SSD1306_WHITE); // Beyaz renk seç
  display.setCursor(0, 0);     // İlk satır, ilk sütun
  display.print("Sicaklik: "); // Yazıyı ekrana bas
  display.setCursor(0, 10);
  display.print(sicaklik);      // Sicaklik değerini ekrana bas
  display.println(" C");        // Derece işareti ekle ve yeni satıra geç

  display.display(); // Değişiklikleri ekrana gönder
  delay(1000);       // Bir saniye bekleyin (opsiyonel)
}
