#include <LiquidCrystal.h>
#include <Keypad.h>

String readString ;
bool ledon=0;
const String pass= "1234";
const int ledPin = 13;
//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
LiquidCrystal lcd(8,9,4,5,6,7);

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B' },
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {36, 34, 32, 30}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {28, 26, 24, 22}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  lcd.begin(16, 2); // set up the LCD's number of columns and rows:
  lcd.setCursor(0, 0);
  lcd.print("Password Based");
  lcd.setCursor(0, 1);
  lcd.print("Circuit Breaker");
  delay(2500);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("By: NH JUEL");
  lcd.setCursor(0, 1);
  lcd.print("Roll: 1504038");
  delay(2500);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Dept. of ETE");
  lcd.setCursor(0, 1);
  lcd.print("RUET");
  delay(1500);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Starting.....");
  delay(2000);
  lcd.clear();
  
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Pass (");
  if(!ledon)
  {
    lcd.print("to on):");
  }
  else
  {
    lcd.print("to off):");
  }
  char key = keypad.getKey();
  lcd.setCursor(0, 1);
  if (key != NO_KEY){
    if(key=='B')
    {
      readString="";
      lcd.clear();
    }
    else if(key=='A')
    {
      if(readString == pass)
      {
        if(ledon==1)
        {
          lcd.clear();
          lcd.setCursor(0, 1);
          lcd.print("already ON");
          readString="";
          delay(1000);
          lcd.clear();
        }
        else
        {
          lcd.clear();
          lcd.setCursor(0, 1);
          lcd.print("LED ON");
          digitalWrite(ledPin, LOW);
          readString="";
          ledon=1;
          delay(1000);
          lcd.clear();
        }
      }
      else
      {
        lcd.clear();
        lcd.setCursor(0, 1);
        lcd.print("Wrong Password");
        delay(1000);
        lcd.clear();
        readString="";
      }
    }
    else if(key=='C')
    {
        if(readString == pass)
        {
          if(ledon==0)
          {
            lcd.clear();
            lcd.setCursor(0, 1);
            lcd.print("already OFF");
            readString="";
            delay(1000);
            lcd.clear();
          }
          else
          {
            lcd.clear();
            lcd.setCursor(0, 1);
            lcd.print("LED OFF");
            digitalWrite(ledPin, HIGH);
            readString="";
            ledon=0;
            delay(1000);
            lcd.clear();
          }
        }
      else
      {
        lcd.clear();
        lcd.setCursor(0, 1);
        lcd.print("Wrong Password");
        delay(1000);
        lcd.clear();
        readString="";
      }
    }
    else
    {
      char c =  key;
      readString += c;
      
     // Serial.println(key);
     // lcd.println(key);
      Serial.println(readString);
      lcd.print(readString);
    }
  }
}

