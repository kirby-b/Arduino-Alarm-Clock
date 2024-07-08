// include the library code:
#include <LiquidCrystal.h>

#include <RTClib.h>

RTC_DS3231 rtc;

// Initialize the LCD library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

int buzzer = 13;// The pin of the active buzzer

char daysOfTheWeek[7][12] = {
  "Sunday",
  "Monday",
  "Tuesday",
  "Wednesday",
  "Thursday",
  "Friday",
  "Saturday"
};

// event from 13:50 to 14:10
uint8_t DAILY_EVENT_START_HH = 7; // event start time: hour
uint8_t DAILY_EVENT_START_MM = 30; // event start time: minute
uint8_t DAILY_EVENT_END_HH   = 8; // event end time: hour
uint8_t DAILY_EVENT_END_MM   = 0; // event end time: minute

void setup () {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT); // Initialize the buzzer pin as an output
  // SETUP RTC MODULE
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    while (1);
  }

  // Automatically sets the RTC to the date & time on PC this sketch was compiled
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  lcd.begin(16, 2);
  DateTime now = rtc.now();
  lcd.print(daysOfTheWeek[now.dayOfTheWeek()]);
  lcd.print(' ');
  lcd.print(now.day(), DEC);
  lcd.print('/');
  lcd.print(now.month(), DEC);
  lcd.print('/');
  lcd.print(now.year(), DEC);
}

void loop () {
  DateTime now = rtc.now();
  // Set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // Print the number of seconds since reset:
  lcd.print(now.hour(), DEC);
  lcd.print(':');
  lcd.print(now.minute(), DEC);
  lcd.print(':');
  lcd.println(now.second(), DEC);

  if (now.hour() == 0 && now.minute() == 0 && now.second() == 0){
    lcd.setCursor(0, 0);
    lcd.print(daysOfTheWeek[now.dayOfTheWeek()]);
    lcd.print(' ');
    lcd.print(now.day(), DEC);
    lcd.print('/');
    lcd.print(now.month(), DEC);
    lcd.print('/');
    lcd.print(now.year(), DEC);
  }

  if (now.hour() >= DAILY_EVENT_START_HH && now.minute() >= DAILY_EVENT_START_MM && now.hour() < DAILY_EVENT_END_HH && now.minute() < DAILY_EVENT_END_MM) {
    Serial.println("WAKE UP....GRAB A BRUSH AND PUT A LITTLE MAKE UP");
    digitalWrite(buzzer, HIGH);
  }
  else{
    digitalWrite(buzzer, LOW);
  }

  delay(1000); // delay 1 seconds
}