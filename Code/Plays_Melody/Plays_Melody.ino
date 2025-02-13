// Plays melody on one piezo buzzer

#include <Arduino.h>
#include <BuzzerMelody.h>

// To change melody, change file below
#include "HappyBirthday.h"

// Pins for outputs
const int PIEZO_A = 9;

BuzzerMelody buzzerMelody(PIEZO_A, NUM_OF_NOTES, melody);

void setup() {
  buzzerMelody.play();
}

void loop() {
  buzzerMelody.loop();
}