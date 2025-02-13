/*
 *	Music: Nintendo - Super Mario Bros Theme
 *
 *	Melody 0 | Main Melody
 *	
*/

#include <Arduino.h>
#include "notes.h"

const Note melody[] PROGMEM = {
	{ NOTE_G4, 300 },
  { NOTE_G4, 100 },
  { NOTE_A4, 400 },
  { NOTE_G4, 400 },
  { NOTE_C5, 400 },
  { NOTE_B4, 800 },
  { NOTE_G4, 300 },
  { NOTE_G4, 100 },
  { NOTE_A4, 400 },
  { NOTE_G4, 400 },
  { NOTE_D5, 400 },
  { NOTE_C5, 800 },
  { NOTE_G4, 300 },
  { NOTE_G4, 100 },
  { NOTE_G5, 400 },
  { NOTE_E5, 400 },
  { NOTE_C5, 400 },
  { NOTE_B4, 400 },
  { NOTE_A4, 800 },
  { NOTE_REST, 800 },
  { NOTE_F5, 300 },
  { NOTE_F5, 100 },
  { NOTE_E5, 400 },
  { NOTE_C5, 400 },
  { NOTE_D5, 400 },
  { NOTE_C5, 1200 },
};
const uint16_t NUM_OF_NOTES = sizeof(melody)/sizeof(melody[0]);
