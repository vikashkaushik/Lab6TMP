/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/Vikash/Downloads/Lab6TMP/src/Lab6TMP.ino"
/*
 * Project Lab6TMP
 * Description:
 * Author:
 * Date:
 */
#include "oled-wing-adafruit.h"
void setup();
void loop();
#line 8 "c:/Users/Vikash/Downloads/Lab6TMP/src/Lab6TMP.ino"
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);
OledWingAdafruit display;
// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
  // sets up the OLED display and sets input as tmp36
  pinMode(A4, INPUT);
  display.display();  // cause the display to be updated
  display.clearDisplay();
  display.setup();
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
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print(temperature); // prints temp
  display.println(" C");
  display.print(voltage*100); // prints temp in F
  display.println(" F");
  display.display();  // cause the display to be updated
  Serial.println(temperature); 
  Serial.println(voltage*100); 
}