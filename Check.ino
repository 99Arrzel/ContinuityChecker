
// Compatible with the Arduino IDE 1.0
// Library version:1.1

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x27 for a 16 chars and 2 line display
int pinIns [] = {6,7,8,9,10,11,12,13};
int values [] = {0,0,0,0,0,0,0,0};
String result = "";
void setPins(){  
  pinMode(0, INPUT);
  pinMode(1, INPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  //Setting inputs
  Serial.println("Setting pins inputs");
  for(int i = 0; i < 7; i++){
    pinMode(pinIns[i], INPUT_PULLUP);
    Serial.print(String(pinIns[i]) + ", ");
  }
}
void checkIfGrounded(){
  for(int i = 0; i < 8; i++){
    if(digitalRead(pinIns[i])){ //If true then is disconected
      values[i] = 0;
      Serial.println("Disconnected pin " + String(pinIns[i]));
    }
    else{
      Serial.println("Connected pin " + String(pinIns[i]));
      values[i] = i+1;
      //Check cross
      //if(i == 1){
        //pinMode(pinIns[7], INPUT); //In cross the second cable should be the 6th, 
        //if(digitalRead(3) == false){ //If there's no current on the 6th, then it's crossing
          //pinMode(pinIns[7], INPUT); //We reset pinmode value
          //We set value for values
          //values[1] = 6;
          //values[5] = 2; 
          //}      
      //}  
    }
  }
  Serial.println("Working");
}


void setup()
{
  Serial.begin(9600);
  setPins();  
  lcd.init(); // initialize the lcd
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Entrada 12345678");
}

void loop()
{   
  checkIfGrounded();
  //Setting result based on values array
  result = "";
  for(int i = 0; i < 8; i++){
   result.concat(String(values[i]));
   Serial.println("Concatening"); 
  }
  // Print a message to the LCD.
  lcd.setCursor(0, 1);
  lcd.print("Salida  " + result);
  delay(1000);
}
