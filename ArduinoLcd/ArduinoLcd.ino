#include <LiquidCrystal.h> 
int Contrast=80;
int cnt=6;
char spliter=",";
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  
int led=8;
String inString = "";
int x;
int r1;
int c1;
//int g1;
String r="";
String cp="";
//String g="";
 void setup()
 {
  Serial.begin(9600);
    pinMode(led,OUTPUT);
    pinMode(cnt,OUTPUT);
    analogWrite(cnt,Contrast);
     lcd.begin(16, 2);
  } 
     void loop()
 { 
   
     
    
       
 
     
while (!Serial.available()) {} // wait for data to arrive
  // serial read section
   //lcd.clear();
while (Serial.available()){ // this will be skipped if no data present, leading to
                             // the code sitting in the delay function below
  
    delay(100);  //delay to allow buffer to fill 
    
    
      String c = Serial.readString();  //gets one byte from serial buffer
      inString = c;
      r1=inString.indexOf(',');
      r=inString.substring(0,r1);
      c1=inString.indexOf(',',r1+1);
      cp=inString.substring(3,6);
      
      //gpu stats(in future)
      //g1=inString.indexOf(',',c1+1);
      //g=inString.substring(c1+1,g1+1);
      
      x=r.toInt();









     lcd.setCursor(0, 0);
     lcd.print("Ram usage:"+r+"%");
     lcd.setCursor(0, 1);
     lcd.print("Cpu usage:"+cp+"%");
    
    // if (x>80){
     // digitalWrite(led,HIGH);
     //}
     //else if(x<80){
     // digitalWrite(led,LOW);
      
    // }
      
      delay(100);
      
      
}    
  }
     
 
