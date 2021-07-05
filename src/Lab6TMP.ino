/*
 * Project Lab6TMP
 * Description: Using tmp36 the oled display displays the temperature reading.
 * Author: Vikash Kaushik
 * Date: 7/3/21
 */
#include "oled-wing-adafruit.h"
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);
OledWingAdafruit display;
// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
  // sets up the OLED display and sets input as tmp36
  pinMode(A4, INPUT);
  display.setup();
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.display();  // cause the display to be updated

  Serial.begin(9600); 
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // reads the tmp36 in a loop
  display.loop();  // this needs to be called each time loop is run
  uint64_t reading = analogRead(A4);
  double voltage = (reading * 3.3) / 4095.0;
  double temperature = (voltage - 0.5) * 100;
  display.clearDisplay();
  display.setCursor(0,0);
  display.print(temperature); // prints temp in C
  display.println(" C");
  display.print((temperature)*(9/5)+32); // prints temp in F
  display.println(" F");
  display.display();  // cause the display to be updated
  Serial.println(temperature); 
  Serial.println((temperature)*(9/5)+32); 
}
