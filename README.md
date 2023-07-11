# arduino-expression-calculator
## What is this repository?
<p> This it the Arduino code for a calculator that takes a mathematical expression written on a 4x4 matrix keypad in the infix form and displays the postfix form and the result of the expression on a 2x16 Crystal LCD. </p>

The conversion to the postfix form of the original expression and it's following evaluation are done using the [Shutting Yard Algorithm](https://en.wikipedia.org/wiki/Shunting_yard_algorithm),using a dinamically allocated stack.
<br>
<br>
See it in action [here.](https://www.youtube.com/watch?v=7AbINdaolRA)
## How it works
https://github.com/lukapopovici/arduino-expression-calculator/assets/128390767/f7aba3a1-7dc6-440c-8fa5-fa7029238d5f
<p>The user needs to start writing the expression(smaller than 33 characters) on the keypad connected to the digital pins 2 trough 9.The expression will be displayed on the LCD and it will keep being updated with each keypress.</p>
<p>Then, the button connected separately to the digital pin 13 needs to be pressed to trigger the conversion and evaluation.</p>
<p>On the LCD, the expression(in the infix form) will dissapear and will be replaced by the postfix form.Shortly after, the postfix form will be replaced by the result of the expression,that can then be used for other operations.</p>
<p>In order to remove anything, the Arduino must be manually reset.</p>

## How I listen for keypresses
<p>I get input from the keypad using "polling". This means that I constantly check if a button has been pressed by checking if the coresponding pins both read digital low. I begin by setting the row pins to the *INPUT_PULLUP* mode (set them as input pins with the pull up resistors activated), so they'll read low only if the button is pressed and will otherwise read as digital high, and set the column pins to digital high. In the loop, I will go trough the columns, setting them as LOW, and checking if any row pin's input reads low as well (if the corresponding button has been pressed). Once the polling function detects that a button's been pressed, it returns the corresponding character from the keypad's map to add to the expression's string.</p>



## Handling longer expressions (33+ characters)

https://github.com/lukapopovici/arduino-expression-calculator/assets/128390767/5c3fd067-4808-4528-83e2-3b05888e0577

<p>When the user attempts to write characters after the LCD's limit has been reached, the LCD will display an error message and return to displaying the expression. The character that triggered the error will not be added to it.</p>
<p>This is done by constantly checking the length of the expression.</p>
