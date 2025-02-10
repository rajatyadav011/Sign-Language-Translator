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
  if (flex1 > threshold1 && flex2 < threshold2 && flex3 < threshold3 && flex4 < threshold4 && flex5 < threshold5) return 'A';
  if (flex1 > threshold1 && flex2 > threshold2 && flex3 < threshold3 && flex4 < threshold4 && flex5 < threshold5) return 'B';
  if (flex1 > threshold1 && flex2 > threshold2 && flex3 > threshold3 && flex4 < threshold4 && flex5 < threshold5) return 'C';
  if (flex1 > threshold1 && flex2 > threshold2 && flex3 > threshold3 && flex4 > threshold4 && flex5 < threshold5) return 'D';
  if (flex1 > threshold1 && flex2 > threshold2 && flex3 > threshold3 && flex4 > threshold4 && flex5 > threshold5) return 'E';
  if (flex1 < threshold1 && flex2 < threshold2 && flex3 < threshold3 && flex4 < threshold4 && flex5 > threshold5) return 'F';
  if (flex1 < threshold1 && flex2 > threshold2 && flex3 < threshold3 && flex4 > threshold4 && flex5 > threshold5) return 'G';
  if (flex1 > threshold1 && flex2 < threshold2 && flex3 > threshold3 && flex4 < threshold4 && flex5 > threshold5) return 'H';
  if (flex1 < threshold1 && flex2 > threshold2 && flex3 > threshold3 && flex4 > threshold4 && flex5 > threshold5) return 'I';
  if (flex1 > threshold1 && flex2 < threshold2 && flex3 < threshold3 && flex4 > threshold4 && flex5 > threshold5) return 'J';
  if (flex1 > threshold1 && flex2 > threshold2 && flex3 < threshold3 && flex4 > threshold4 && flex5 > threshold5) return 'K';
  if (flex1 > threshold1 && flex2 > threshold2 && flex3 > threshold3 && flex4 > threshold4 && flex5 > threshold5) return 'L';
  if (flex1 < threshold1 && flex2 < threshold2 && flex3 > threshold3 && flex4 > threshold4 && flex5 > threshold5) return 'M';
  if (flex1 < threshold1 && flex2 < threshold2 && flex3 < threshold3 && flex4 > threshold4 && flex5 > threshold5) return 'N';
  if (flex1 < threshold1 && flex2 < threshold2 && flex3 < threshold3 && flex4 < threshold4 && flex5 > threshold5) return 'O';
  if (flex1 > threshold1 && flex2 < threshold2 && flex3 < threshold3 && flex4 < threshold4 && flex5 > threshold5) return 'P';
  if (flex1 > threshold1 && flex2 > threshold2 && flex3 < threshold3 && flex4 < threshold4 && flex5 > threshold5) return 'Q';
  if (flex1 > threshold1 && flex2 > threshold2 && flex3 > threshold3 && flex4 < threshold4 && flex5 > threshold5) return 'R';
  if (flex1 > threshold1 && flex2 > threshold2 && flex3 > threshold3 && flex4 > threshold4 && flex5 > threshold5) return 'S';
  if (flex1 < threshold1 && flex2 > threshold2 && flex3 > threshold3 && flex4 > threshold4 && flex5 < threshold5) return 'T';
  if (flex1 < threshold1 && flex2 > threshold2 && flex3 < threshold3 && flex4 > threshold4 && flex5 < threshold5) return 'U';
  if (flex1 > threshold1 && flex2 < threshold2 && flex3 < threshold3 && flex4 > threshold4 && flex5 < threshold5) return 'V';
  if (flex1 > threshold1 && flex2 > threshold2 && flex3 < threshold3 && flex4 > threshold4 && flex5 < threshold5) return 'W';
  if (flex1 > threshold1 && flex2 > threshold2 && flex3 > threshold3 && flex4 > threshold4 && flex5 < threshold5) return 'X';
  if (flex1 > threshold1 && flex2 > threshold2 && flex3 > threshold3 && flex4 > threshold4 && flex5 > threshold5) return 'Y';
  if (flex1 < threshold1 && flex2 < threshold2 && flex3 < threshold3 && flex4 < threshold4 && flex5 < threshold5) return 'Z';
  if (flex1 < threshold1 && flex2 < threshold2 && flex3 < threshold3 && flex4 < threshold4 && flex5 < threshold5) return '0';
  if (flex1 > threshold1 && flex2 < threshold2 && flex3 < threshold3 && flex4 < threshold4 && flex5 < threshold5) return '1';
  if (flex1 > threshold1 && flex2 > threshold2 && flex3 < threshold3 && flex4 < threshold4 && flex5 < threshold5) return '2';
  if (flex1 > threshold1 && flex2 > threshold2 && flex3 < threshold3 && flex4 < threshold4 && flex5 < threshold5) return '3';
  if (flex1 > threshold1 && flex2 > threshold2 && flex3 < threshold3 && flex4 < threshold4 && flex5 < threshold5) return '4';
  if (flex1 > threshold1 && flex2 > threshold2 && flex3 < threshold3 && flex4 < threshold4 && flex5 < threshold5) return '5';
  if (flex1 > threshold1 && flex2 > threshold2 && flex3 < threshold3 && flex4 < threshold4 && flex5 < threshold5) return '6';
  if (flex1 > threshold1 && flex2 > threshold2 && flex3 < threshold3 && flex4 < threshold4 && flex5 < threshold5) return '7';
  if (flex1 > threshold1 && flex2 > threshold2 && flex3 < threshold3 && flex4 < threshold4 && flex5 < threshold5) return '8';
  if (flex1 > threshold1 && flex2 > threshold2 && flex3 < threshold3 && flex4 < threshold4 && flex5 < threshold5) return '9';
  return ' ';
}
