#include <LiquidCrystal.h>

//PPM
#define         MQ_PIN                       (0)   
#define         RL_VALUE                     (10)    
#define         RO_CLEAN_AIR_FACTOR          (9.83)  

#define         CALIBARAION_SAMPLE_TIMES     (50)    
#define         CALIBRATION_SAMPLE_INTERVAL  (500)   
                                                     
#define         READ_SAMPLE_INTERVAL         (50)    
#define         READ_SAMPLE_TIMES            (5)     

#define         GAS_CO                       (1)

double iPPM_CO = 0.00;

float           COCurve[3]  =  {1.7,0.20,-0.66}; 

float           Ro           =  10;

//PPM

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);
  //PPM
  Serial.print("Calibrating...\n");                
  Ro = MQCalibration(MQ_PIN);                     
                                                                   
  Serial.print("Calibration is done...\n"); 
  Serial.print("Ro=");
  Serial.print(Ro);
  Serial.print("kohm");
  Serial.print("\n");
  //PPM
}

void loop() {
  lcd.setCursor(0,0);
  //PPM 
   iPPM_CO = MQGetGasPercentage(MQRead(MQ_PIN)/Ro,GAS_CO); 
   Serial.print("CO:"); 
   Serial.print(iPPM_CO);
   Serial.print( "ppm" );
   Serial.println("    ");
   delay(200);
   //PPM

  lcd.print("CO:"); 
  lcd.print(iPPM_CO);
  lcd.print( "ppm" );

}

float MQResistanceCalculation(int raw_adc)
{
  return ( ((float)RL_VALUE*(1023-raw_adc)/raw_adc));
}

float MQCalibration(int mq_pin)
{
  int i;
  float val=0;

  for (i=0;i<CALIBARAION_SAMPLE_TIMES;i++) {            
    val += MQResistanceCalculation(analogRead(mq_pin));
    delay(CALIBRATION_SAMPLE_INTERVAL);
  }
  val = val/CALIBARAION_SAMPLE_TIMES;                 

  val = val/RO_CLEAN_AIR_FACTOR;                       
                                                        

  return val; 
}

float MQRead(int mq_pin)
{
  int i;
  float rs=0;

  for (i=0;i<READ_SAMPLE_TIMES;i++) {
    rs += MQResistanceCalculation(analogRead(mq_pin));
    delay(READ_SAMPLE_INTERVAL);
  }

  rs = rs/READ_SAMPLE_TIMES;

  return rs;  
}

double MQGetGasPercentage(float rs_ro_ratio, int gas_id)
{
  if ( gas_id == GAS_CO ) {
     return MQGetPercentage(rs_ro_ratio,COCurve);
  }    

  return 0;
}

double  MQGetPercentage(float rs_ro_ratio, float *pcurve)
{
  return (pow(10,( ((log(rs_ro_ratio)-pcurve[1])/pcurve[2]) + pcurve[0])));
}
