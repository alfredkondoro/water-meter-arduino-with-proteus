#include<LiquidCrystal.h>
#include<Keypad.h>
const byte ROWS = 4; 
const byte COLS = 3; 
char keys[ROWS][COLS] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'},
    {'*','0','#'}
};

byte rowPins[ROWS] = {10, 9, 8, 7}; 
byte colPins[COLS] = {13, 12, 11}; 

#define pir 4
#define buzpin 5

LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

int flowunit = 3000;

void setup(){
   pinMode(pir, INPUT);
   pinMode(buzpin, OUTPUT);
   Serial.begin(9600);
   lcd.begin(16, 4);        
   lcd.setCursor(0,0);
   lcd.print("DAWASCO METER");
   lcd.setCursor(0, 2);
   lcd.print("Luku ya Maji:");
}

void loop (){
  
    flowunit--;
    
    lcd.setCursor(0, 3);
    lcd.print(flowunit);
    Serial.print(__DATE__);
    Serial.print(" : ");      
    Serial.print(flowunit, DEC); 
    Serial.println("mls");

    char key = keypad.getKey() ;
      if (key) {
       flowunit += 1000;
       lcd.setCursor(0, 1);
       lcd.print("Ingizo: ");
       lcd.setCursor(7, 1);
       lcd.print("57589");
       delay(2000);
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
    if(digitalRead(pir)){
    digitalWrite(buzpin, HIGH);
    delay(1000);
    digitalWrite(buzpin, LOW);
    Serial.print(__DATE__);
    Serial.print(" : ");
    Serial.println("Meter Opened");
    lcd.setCursor(0, 1);
    lcd.print("Meter Breach");
   }
   else{
    digitalWrite(buzpin, LOW);
   }
}
