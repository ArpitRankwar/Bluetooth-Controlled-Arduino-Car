#include <SoftwareSerial.h>

SoftwareSerial BT(0, 1); 
String readvoice;

void setup() {
   
 BT.begin(9600);
 Serial.begin(9600);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);

}

void loop() {
  float check=255/9;
  while (BT.available())
  {  
  char c = BT.read(); 
  readvoice += c; 
  } 
  //Serial.println(readvoice);
  if (readvoice.length() > 0) 
  {
    Serial.println(readvoice);

  if(readvoice == "F")
  {
    //Serial.println("FOR");

    digitalWrite(3, HIGH);
    digitalWrite (7, HIGH);
    digitalWrite(5,LOW);
    digitalWrite(9,LOW);
  }

  if(readvoice == "B")
  {
    //Serial.println("back");
    digitalWrite(3, LOW);
    digitalWrite(7, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(9,HIGH);
  }

  if (readvoice == "R")
  {
   // Serial.println("left");
    digitalWrite (3,HIGH);
    digitalWrite (5,LOW);
    digitalWrite (7,LOW);
    digitalWrite (9,LOW);
      digitalWrite(3, HIGH);
    digitalWrite (9, HIGH);
    digitalWrite(7,LOW);
    digitalWrite(5,LOW);
    
  
  }

 if ( readvoice == "L")
 {
  //Serial.println("right");
   digitalWrite (3, LOW);
   digitalWrite (5, HIGH);
   digitalWrite (7, LOW);
   digitalWrite (9, LOW);
      digitalWrite(7, HIGH);
    digitalWrite (5, HIGH);
    digitalWrite(3,LOW);
    digitalWrite(9,LOW);
 }
 if (readvoice == "S")
 {
  digitalWrite(3, LOW);
    digitalWrite (5, LOW);
    digitalWrite(7,LOW);
    digitalWrite(9,LOW);
 }
 if(readvoice=="1"){
  analogWrite(10,85);
  analogWrite(11,85);
 }
 if(readvoice=="2"){
  analogWrite(10,170);
  analogWrite(11,170);
 }
 if(readvoice=="3"){
  analogWrite(10,255);
  analogWrite(11,255);
 }
 

  }
  
 readvoice="";

 

}
 
