#include <DHT.h>
#include <DHT_U.h>
#define DHTPIN A0 
#define DHTTYPE DHT22  
#include <LiquidCrystal.h>
DHT dht(DHTPIN, DHTTYPE);

float h;
float t;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup(){
  
Serial.begin(9600);
dht.begin(); 
lcd.begin(16,2);
  
  
  }

void loop(){
  
t = dht.readTemperature();
h = dht.readHumidity();
 
  Serial.print("TEMPERATURA: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print("HUMEDAD: ");
  Serial.print(h);
  Serial.println(" %t") ;
  delay(500);

lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print("*C");
  lcd.setCursor(0,1);
  lcd.print("Hum:  ");
  lcd.print(h);
  lcd.print("%");
  



}
