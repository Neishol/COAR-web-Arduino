#define anInput     A0                    
#define co2Zero     45                        
#include  <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
  
                      
  Serial.begin(9600);                        
  lcd.begin(16, 2);
}

void loop() {
  lcd.setCursor(0, 0);
int co2now[10];                              
int co2raw = 0;                               
int co2comp = 0;                             
int co2ppm = 0;                              
int zzz = 0;   
                             
  for (int x = 0;x<10;x++){                   
    co2now[x]=analogRead(A0);
    delay(200);
  }

for (int x = 0;x<10;x++){                     
    zzz=zzz + co2now[x];
    
  }
  co2raw = zzz /10;                           
  co2comp = co2raw - co2Zero;                
  co2ppm = map(co2comp,0,1023,400,5000);      

  lcd.print("CO2: ");
   lcd.print(co2ppm);
   lcd.println(" ppm    "); 
                     
  Serial.print(co2ppm);                      
  Serial.print(" PPM");                      
 
}
