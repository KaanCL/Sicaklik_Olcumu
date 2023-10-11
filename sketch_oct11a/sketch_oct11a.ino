int lm35Pin = A0;             // Sıcaklık sensörünün analog pin bağlantısı
int ledPin = 8;                // LED'in bağlı olduğu dijital pin
#define buzzerPin 9            // Buzzer'ın bağlı olduğu dijital pin
int bekletmeSuresi = 50;       // LED ve Buzzer yanma süresi
int okunanADC = 0;             // Analog değer okuma değişkeni
float gerilimSicaklik = 0;     // Gerilim değeri sıcaklık ölçümü
float sicaklikDegeri = 0;      // Sıcaklık değeri
bool alarmDurumu = false;      // Alarm durumu

void setup() 
{
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  okunanADC = analogRead(lm35Pin);
  gerilimSicaklik = (okunanADC / 1023.0) * 5000;
  sicaklikDegeri = gerilimSicaklik / 10.0; 
  Serial.println(sicaklikDegeri);
  
  if (sicaklikDegeri >= 25) { // Sıcaklık 25 dereceyi geçtiğinde
    if (!alarmDurumu) {
      digitalWrite(ledPin, HIGH);
      digitalWrite(buzzerPin, HIGH);
      alarmDurumu = true;
    }
  } else {
    if (alarmDurumu) {
      digitalWrite(ledPin, LOW);
      digitalWrite(buzzerPin, LOW);
      alarmDurumu = false;
    }
  }
}