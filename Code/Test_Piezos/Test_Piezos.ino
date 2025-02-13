// Pressing the button will change which piezo is playing.

// Global Variable to select piezo
bool play_piezo_a = true;

// Pins for piezos
const int BUTTON = 2;
const int PIEZO_A = 9;
const int PIEZO_B = 10;

void setup()
{
  // Sets pin mode for all digital pins
  pinMode(BUTTON, INPUT);
  pinMode(PIEZO_A, OUTPUT);
  pinMode(PIEZO_B, OUTPUT);
}

void loop()
{
  if (check_button()) {
    change_piezo();
  }
  
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

void change_piezo() {
  play_piezo_a = !play_piezo_a;
  if (play_piezo_a) {
    tone(PIEZO_A, 440);
  }
  else {
    tone(PIEZO_B, 440);
  }
}