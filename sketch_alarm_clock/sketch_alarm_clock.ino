void setup() 
{
    // Initialize RTC pins, LCD screen pins, and Buzzer pins
}

void loop() {
    // Checks time and sets off buzzer if it reads a certain time. 
    // Will also display time on the screen
    // It would be a good idea to also implement use of a remote for setting time
}


// Code from the lcd example
// // include the library code:
// #include <LiquidCrystal.h>

// // initialize the library with the numbers of the interface pins
// LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// void setup() {
//   // set up the LCD's number of columns and rows:
//   lcd.begin(16, 2);
//   // Print a message to the LCD.
//   lcd.print("Hello, World!");
// }

// void loop() {
//   // set the cursor to column 0, line 1
//   // (note: line 1 is the second row, since counting begins with 0):
//   lcd.setCursor(0, 1);
//   // print the number of seconds since reset:
//   lcd.print(millis() / 1000);
// }


// Code from active buzzer example
// int buzzer = 12;//the pin of the active buzzer
// void setup()
// {
//   pinMode(buzzer, OUTPUT); //initialize the buzzer pin as an output
// }
// void loop()
// {
//   int sound_duration = 500;
//   for (int i = 0; i < 20; i++)
//   {
//     //use the if function to gradually shorten the interval of the sound
//     if (i < 5)
//     {
//       sound_duration = 500;
//     } else if (i < 10)
//     {
//       sound_duration = 300;
//     } else if (i < 20)
//     {
//       sound_duration = 100;
//     }
//     //activate the active buzzer
//     digitalWrite(buzzer, HIGH);
//     delay(sound_duration);//wait for sound_duration ms
//     //deactivate the active buzzer
//     digitalWrite(buzzer, LOW);
//     delay(sound_duration);//wait for sound_duration ms
//   }
//   //activate the active buzzer
//   digitalWrite(buzzer, HIGH);
//   delay(5000);//keep playing sound for 5 seconds.
// }