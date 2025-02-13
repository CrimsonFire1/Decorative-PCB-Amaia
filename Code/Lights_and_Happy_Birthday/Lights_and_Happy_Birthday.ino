// LEDs will dim. If button is pressed, Happy Birthday will play.

#include <Arduino.h>
#include <BuzzerMelody.h>

// File for Happy Birthday melody
#include "HappyBirthday.h"

// Global Variables for dimmming LEDs
int led_brightness = 0;
bool increasing = true;

// Pin for button
const int BUTTON = 2;

// Pins for dimming LEDs
const int LED_DIM_A = 3;
const int LED_DIM_B = 5;
const int LED_DIM_C = 6;

// Pins for normal LEDs
const int LED_X = 4;
const int LED_Y = 7;
const int LED_Z = 8;

// Pins for piezos
const int PIEZO_A = 9;
const int PIEZO_B = 10; // not in use

// Sets melody for piezo
BuzzerMelody buzzerMelody(PIEZO_A, NUM_OF_NOTES, melody);

void setup()
{
  // Sets pin mode for all digital pins
  pinMode(BUTTON, INPUT);
  pinMode(LED_DIM_A, OUTPUT); // LED dim A cannot be used in conjunction with piezo due to timer issues
  pinMode(LED_DIM_B, OUTPUT);
  pinMode(LED_DIM_C, OUTPUT);
  pinMode(LED_X, OUTPUT);
  pinMode(LED_Y, OUTPUT);
  pinMode(LED_Z, OUTPUT);
  
  // Starts with normal LEDs on
  digitalWrite(LED_DIM_A, HIGH);
  digitalWrite(LED_X, HIGH);
  digitalWrite(LED_Y, HIGH);
  digitalWrite(LED_Z, HIGH);
}

void loop()
{
  dim_leds();  
  
  if (check_button()) {
    buzzerMelody.play();
  }
  
  buzzerMelody.loop();
  delay(5);
}

// Returns true if button is pressed
bool check_button() {
  if (digitalRead(BUTTON) == HIGH) {
    delay(50);
    if (digitalRead(BUTTON) == HIGH) {
      return true;
    }
  }
  return false;
}

// Dims and brightens dimming LEDs
void dim_leds() {
  // analogWrite(LED_DIM_A, led_brightness);
  analogWrite(LED_DIM_B, led_brightness);
  analogWrite(LED_DIM_C, led_brightness);

  if (increasing) {
    ++led_brightness;
  }
  else {
    --led_brightness;
  }
  
  if (led_brightness > 255) {
    increasing = false;
    led_brightness = 255;
  } else if (led_brightness < 0) {
    increasing = true;
    led_brightness = 0;
  }
}

// Turns on all LEDs
void leds_on() {
  digitalWrite(LED_X, HIGH);
  digitalWrite(LED_Y, HIGH);
  digitalWrite(LED_Z, HIGH);
  digitalWrite(LED_DIM_A, HIGH);
  digitalWrite(LED_DIM_B, HIGH);
  digitalWrite(LED_DIM_C, HIGH);
}

// Turns off all LEDs
void leds_off() {
  digitalWrite(LED_X, LOW);
  digitalWrite(LED_Y, LOW);
  digitalWrite(LED_Z, LOW);
  digitalWrite(LED_DIM_A, LOW);
  digitalWrite(LED_DIM_B, LOW);
  digitalWrite(LED_DIM_C, LOW);
}