
#include <Wire.h> // Library for I2C communication
#include <LiquidCrystal_I2C.h> // Library for LCD
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);
double Thermister(int RawADC){
  double Temp;
  Temp=log(((10240000/RawADC)-10000));
  Temp=1/(0.001129148+(0.000234125+(0.0000000876741*Temp*Temp))*Temp);
  Temp=Temp-273.15;
  return Temp;
  }
void setup() {
   pinMode(7,OUTPUT);//trig of ultra
  pinMode(8,INPUT);//echo of ultra
  pinMode(9,OUTPUT);//for buzzer
  pinMode(A0,INPUT);//voltage of solar panel
  pinMode(A1,INPUT);//voltage of battery
  pinMode(A3,OUTPUT);
  pinMode(3,OUTPUT);//to shift two wheel drive
  pinMode(2,OUTPUT);//bms
  Serial.begin(9600);
    lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(5,0);
  lcd.print("TEAM");
  lcd.setCursor(2,1);
  lcd.print("MERCENARIES");
  delay(2000);
 digitalWrite(3,LOW);
}

void loop() {
  lcd.clear();
   lcd.setCursor(0, 0);
  float svolt=0;
  float a[20];
  for(int i=0;i<20;i++){
    a[i]=analogRead(A0)/16.833333333;
    svolt+=a[i];
  }
  int svol=svolt/20;
  lcd.print("VOLT=");
  lcd.print(svol);
  
  
  Serial.println(svol);
  float bvolt=0;
  float b[20];
  for(int i=0;i<20;i++){
    b[i]=analogRead(A1)/16.8333333333;
    bvolt+=b[i];
  }
  int bvol=bvolt/100;
  //Serial.println(bvol);
  int bp=bvol*100/12;
  int per=map(bp,0,13,0,100);
  lcd.setCursor(2,1);
  lcd.print("BATTERY=");
  lcd.print(per);
  lcd.print("%");
  if(bp<10){
    digitalWrite(3,HIGH);
  }
  if(bvol>12){
    digitalWrite(2,LOW);
  }
  lcd.setCursor(9,0);
  lcd.print("TEMP=");
  lcd.print(Thermister(analogRead(A2)));
   digitalWrite(7,LOW);
   float currenttime=micros();
      digitalWrite(7,HIGH);
      float duration=pulseIn(8,HIGH);
      float dist=(duration*0.0181)-0.66;
      Serial.println(dist);
      if(dist<11.5){
        tone(9,1000);
      }
      else{
        noTone(9);
      }
   
 
}
