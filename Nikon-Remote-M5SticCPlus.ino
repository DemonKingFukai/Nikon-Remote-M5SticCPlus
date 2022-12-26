#include <M5StickCPlus.h>
#include <IRremote.h>
#include <IRremoteInt.h>

// Pin number for the IR LED
const int irLedPin = 9;

// Create an instance of the IRremote library
IRsend irsend;

void setup() {
  // Initialize the IR LED pin as an output
  pinMode(irLedPin, OUTPUT);
  // Initialize the M5StickC-Plus display
  M5.Lcd.begin();
  M5.Lcd.setTextSize(2); // set the text size to 2
  M5.Lcd.setCursor(10, 10); // set the cursor position
  M5.Lcd.setCursor(50, 10); // set the cursor position for the text
  M5.Lcd.print("Shutter"); // print the text "Shutter"
}

void loop() {
  // Send the IR data when the button is held down
  if (M5.BtnA.isPressed()) {
    // IR data
    uint16_t rawbuf[] = {1989, 27513, 408, 1569, 386, 3503, 408, 62013, 1985, 27517, 404, 1573, 382, 3506, 405};
    // Frequency of the IR data (in Hz)
    unsigned int frequency = 38000;
    // Duty cycle of the IR data (as a fraction of the period)
    unsigned int rawlen = 33; // duty cycle is a percentage, so multiply by 100
    // Send the IR data
    irsend.sendRaw(rawbuf, frequency, rawlen);
    // Wait 1 second before sending the data again
    delay(1000);
    // Draw a circle on the display to indicate that the IR data is being transmitted
    M5.Lcd.fillCircle(100, 100, 50, RED);
    // Wait 1 second before clearing the display
    delay(1000);
    // Clear the display
    M5.Lcd.fillScreen(BLACK);
  }
}
