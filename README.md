# arduino-expression-calculator
## What is this repository?
 This repository contains Arduino code for a calculator that accepts mathematical expressions entered through a 4x4 matrix keypad. The calculator converts the infix expression into postfix form using the [Shutting Yard Algorithm](https://en.wikipedia.org/wiki/Shunting_yard_algorithm),and displays both the postfix form and the result on a 2x16 Crystal LCD.
 
The conversion to postfix form and the evaluation of the expression are performed using a dynamically allocated stack.
<br>
<br>
See it in action [here.](https://www.youtube.com/watch?v=7AbINdaolRA)
## How it works
https://github.com/lukapopovici/arduino-expression-calculator/assets/128390767/f7aba3a1-7dc6-440c-8fa5-fa7029238d5f
<p>To use the calculator, the user starts by entering the expression (up to 33 characters) on the keypad connected to digital pins 2 through 9. The LCD displays the entered expression in real-time as the user presses each key.</p>
<p>Pressing the button connected to digital pin 13 triggers the conversion and evaluation of the entered expression.</p>
<p>Once triggered, the infix expression disappears from the LCD and is replaced by the postfix form. Shortly after, the postfix form is replaced by the evaluated result of the expression, which can be used for further operations.</p>
<p>In order to remove anything, the Arduino must be manually reset.</p>

## How I listen for keypresses
<p>I get input from the keypad using "polling". This means that I constantly check if a button has been pressed by checking if the coresponding pins both read digital low. I begin by setting the row pins to the *INPUT_PULLUP* mode (set them as input pins with the pull up resistors activated), so they'll read low only if the button is pressed and will otherwise read as digital high, and set the column pins to digital high. In the loop, I will go trough the columns, setting them as LOW, and checking if any row pin's input reads low as well (if the corresponding button has been pressed). Once the polling function detects that a button's been pressed, it returns the corresponding character from the keypad's map to add to the expression's string.</p>

## The LCD

The 2x16 LCD I use is attached via an i2c interface. To interact with it, I made use of the [LiquidCrystal_I2C.h library](https://www.arduino.cc/reference/en/libraries/liquidcrystal-i2c/). Documentation about it alongside a program that helps find the i2c adress of a device connected to an Arduino can be found [here](https://lastminuteengineers.com/i2c-lcd-arduino-tutorial/).

## Handling longer expressions (33+ characters)

https://github.com/lukapopovici/arduino-expression-calculator/assets/128390767/5c3fd067-4808-4528-83e2-3b05888e0577

<p>When the user attempts to write characters after the LCD's limit has been reached, the LCD will display an error message and return to displaying the expression. The character that triggered the error will not be added to it.</p>
<p>This is done by constantly checking the length of the expression.</p>
