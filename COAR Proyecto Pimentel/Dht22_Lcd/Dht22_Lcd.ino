#include <DHT.h>
#include <DHT_U.h>
#include <LiquidCrystal.h>
#define DHTPIN 7
#define DHTTYPE DHT22

////4Dht11 + dht22
DHT dht(DHTPIN, DHTTYPE); 
//Variables
int chk;
float hum; 
float temp; 
////4


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


void setup() {
  Serial.begin(9600);

  ////4Dht11 + Dht22
  dht.begin();
  ////4

  

}

void loop() {
  lcd.setCursor(0,0);

  ///
  hum = dht.readHumidity();
  temp= dht.readTemperature();
    
  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print(" %, Temp: ");
  Serial.print(temp);
  Serial.println(" Celsius");
  
  ///3Dht11 + Dht22
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.println("*C    ");
  lcd.clear();
  lcd.print("Humidity: ");
  lcd.print(hum);
  lcd.print(" %");
}
