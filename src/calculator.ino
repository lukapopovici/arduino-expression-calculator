//define button that triggers eval
#define EVAL 13

#include <LiquidCrystal_I2C.h>
#include <string.h>
#include "postfix.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int rows = 4;
const int cols = 4;

//mapping the keys of the keypad to characters
char keymap[rows][cols] = {
  {'1', '5', '9', '*'},
  {'2', '6', '0', '/'},
  {'3', '7', '+', '('},
  {'4', '8', '-', ')'}
};

//row and column pins
byte rPins[rows] = {2, 3, 4, 5};
byte cPins[cols] = {6, 7, 8, 9};

Stiva stv;
Stiva Op;

String s = "";

void setup() {
  //initializing stacks for the evalutaion functions
  Init(stv);
  Init(Op);
  //init functions for the lcd
  lcd.init();
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(0, 0);

  Serial.begin(9600);
  //setting every button as digital-high
  pinMode(EVAL, INPUT_PULLUP);
  for (int i = 0; i < rows; i++) {
    pinMode(rPins[i], INPUT_PULLUP);
  }
  for (int i = 0; i < cols; i++) {
    pinMode(cPins[i], OUTPUT);
    digitalWrite(cPins[i], HIGH);
  }
}



void loop() {
  char key = polling();

  if (key != ' ') {
    s.concat(key);
    lcd.clear();
    print_S(s);
  }
  if (!digitalRead(EVAL)) {
    //obtain and display postfix form of infix form
    String form = postfix(stv, s);
    print_S("Postfix form:");
    print_S(form);
    //calculate and display the result
    print_S("Result:");
    s = postfixeval(Op, form);
    print_S(s);
  }
}

//getting the value of the key pressed w/ polling
char polling() {
  char key = ' ';

  for (int i = 0; i < cols; i++) {
    //activate a column
    digitalWrite(cPins[i], LOW);

    for (int j = 0; j < rows; j++) {
      // check if any row is digital low (the coresponding button has been pressed)
      if (digitalRead(rPins[j]) == LOW) {
        delay(100);
        // debounce delay
        if (digitalRead(rPins[j]) == LOW) {
          key = keymap[j][i];
          break;
        }
      }
    }

    //deactivate column
    digitalWrite(cPins[i], HIGH);

    //exit the loop if keypress detected
    if (key != ' ') {
      break;
    }
  }

  return key;
}

//print function for the lcd to
void print_S(String s) {
  lcd.clear();
  int len = s.length();
  if (len <= 32) {
    lcd.print(s);
    Serial.println(s);
    if (len >= 16) {
      lcd.setCursor(0, 1);
      lcd.print(s.substring(16));
    }
  }
  else {
    lcd.clear();
    lcd.print("Character limit!");
    delay(400);
    lcd.clear();
    s = s.substring(0, s.length() - 1);
    print_S(s);
  }
  delay(1000);
}
