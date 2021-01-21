#include<LiquidCrystal.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(9, 10);

#define pir 4
#define buzpin 5

LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);

int flowunit = 3000;

void setup(){
   pinMode(pir, INPUT);
   pinMode(buzpin, OUTPUT);
   mySerial.begin(9600);
   Serial.begin(9600);
   lcd.begin(16, 4);        
   lcd.setCursor(0,0);
   lcd.print("DAWASCO METER");
   lcd.setCursor(0, 2);
   lcd.print("Luku ya Maji:");
}

void loop (){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("DAWASCO METER");
    lcd.setCursor(0, 2);
    lcd.print("Luku ya Maji:");

    flowunit--;
    lcd.setCursor(0, 3);
    lcd.print(flowunit);
    mySerial.print(__DATE__);
    mySerial.print(" : ");      
    mySerial.print(flowunit, DEC); 
    mySerial.println("mls");
    delay(2000);

    char key = Serial.read();
    
   if(digitalRead(pir)){
      digitalWrite(buzpin, HIGH);
      delay(1000);
      digitalWrite(buzpin, LOW);
      mySerial.print(__DATE__);
      mySerial.print(" : ");
      mySerial.println("Meter Opened");
      lcd.setCursor(0, 1);
      lcd.print("Meter Breach");
   }
   
   else if (key == 2) {
         flowunit += 1000;
         lcd.setCursor(0, 1);
         lcd.print("Voucher Added");
         delay(1000);
         lcd.setCursor(7, 1);
         
         if(flowunit<=2700){
          lcd.setCursor(0, 1);
          lcd.print("Low Unit");
          digitalWrite(buzpin, HIGH);
          delay(1000);
          digitalWrite(buzpin, LOW);
        }
        else{
          lcd.setCursor(0, 1);
          lcd.print(".");
        }
     }
   else{
      digitalWrite(buzpin, LOW);      
   }
}
