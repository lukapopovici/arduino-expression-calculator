# arduino-expression-calculator
## What is this repository?
<p> This it the Arduino code for a calculator that takes a mathematical expression written on a 4x4 matrix keypad in the infix form and displays the postfix form and the result of the expression on a 2x16 Crystal LCD. </p>

The conversion to the postfix form of the original expression and it's following evaluation are done using the [Shutting Yard Algorithm](https://en.wikipedia.org/wiki/Shunting_yard_algorithm),using a dinamically allocated stack.

## How it works
https://github.com/lukapopovici/arduino-expression-calculator/assets/128390767/f7aba3a1-7dc6-440c-8fa5-fa7029238d5f
<p>The user needs to start writing the expression(smaller than 33 characters) on the keypad connected to the digital pins 2 trough 9.</p>
<p>Then, the button coonected tot he digital pin 13 needs to be pressed to trigger the conversion and evaluation.</p>


## Handling longer expressions (33+ characters)


https://github.com/lukapopovici/arduino-expression-calculator/assets/128390767/5c3fd067-4808-4528-83e2-3b05888e0577



<p>When the user attempts to write characters after the LCD's limit has been reached, the LCD will display an error message and return to displaying the expression. The character that triggered the error will not be added to it.</p>
