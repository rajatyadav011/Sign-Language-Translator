#include <LiquidCrystal.h>
#include <string.h>

// Initialize the LCD with the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Define flex sensor pins
const int flexSensor1 = A0;
const int flexSensor2 = A1;
const int flexSensor3 = A2;
const int flexSensor4 = A3;
const int flexSensor5 = A4;

// Threshold values for flex sensors
const int threshold1 = 500;
const int threshold2 = 500;
const int threshold3 = 500;
const int threshold4 = 500;
const int threshold5 = 500;

// Store detected signs
char detectedSigns[17] = "";

void setup() {
  lcd.begin(16, 2); // Set up LCD columns and rows
  lcd.print("Sign Language");
  lcd.setCursor(0, 1);
  lcd.print("Translator");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Read flex sensor values
  int flex1 = analogRead(flexSensor1);
  int flex2 = analogRead(flexSensor2);
  int flex3 = analogRead(flexSensor3);
  int flex4 = analogRead(flexSensor4);
  int flex5 = analogRead(flexSensor5);

  // Detect letter based on flex sensor readings
  char letter = detectLetter(flex1, flex2, flex3, flex4, flex5);

  if (letter != ' ') {
    int len = strlen(detectedSigns);
    if (len < 16) {
      detectedSigns[len] = letter;
      detectedSigns[len + 1] = '\0';
    }
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Signs: ");
  lcd.setCursor(0, 1);

  lcd.print(detectedSigns);

  delay(500);
}

char detectLetter(int flex1, int flex2, int flex3, int flex4, int flex5) {
  if (flex1 > threshold1 && flex2 < threshold2 && flex3 < threshold3 && flex4 < threshold4 && flex5 < threshold5) {
    return 'A';
  } else if (flex1 < threshold1 && flex2 > threshold2 && flex3 < threshold3 && flex4 < threshold4 && flex5 < threshold5) {
    return 'B';
  } else if (flex1 < threshold1 && flex2 < threshold2 && flex3 > threshold3 && flex4 < threshold4 && flex5 < threshold5) {
    return 'C';
  } else if (flex1 < threshold1 && flex2 < threshold2 && flex3 < threshold3 && flex4 > threshold4 && flex5 < threshold5) {
    return 'D';
  } else if (flex1 < threshold1 && flex2 < threshold2 && flex3 < threshold3 && flex4 < threshold4 && flex5 > threshold5) {
    return 'E';
  } else {
    return ' ';
  }
}
