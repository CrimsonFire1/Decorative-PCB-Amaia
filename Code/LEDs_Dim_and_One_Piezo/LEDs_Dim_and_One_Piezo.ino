int led_brightness = 0;
bool increasing = true;

const int BUTTON = 2;

const int LED_DIM_A = 3;
const int LED_DIM_B = 5;
const int LED_DIM_C = 6;

const int LED_X = 4;
const int LED_Y = 7;
const int LED_Z = 8;

const int PIEZO_A = 9;
const int PIEZO_B = 10;

void setup()
{
  pinMode(BUTTON, INPUT);
  
  pinMode(LED_DIM_A, OUTPUT);
  pinMode(LED_DIM_B, OUTPUT);
  pinMode(LED_DIM_C, OUTPUT);
  
  pinMode(LED_X, OUTPUT);
  pinMode(LED_Y, OUTPUT);
  pinMode(LED_Z, OUTPUT);
  
  pinMode(PIEZO_A, OUTPUT);
  pinMode(PIEZO_B, OUTPUT);
  
  digitalWrite(LED_X, HIGH);
  digitalWrite(LED_Y, HIGH);
  digitalWrite(LED_Z, HIGH);
  
  Serial.begin(9600);
}

void loop()
{
  analogWrite(LED_DIM_A, led_brightness);
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
  
  if (digitalRead(BUTTON) == HIGH) {
    delay(50);
    if (digitalRead(BUTTON) == HIGH) {
      Serial.println("here");
      playMusic();
    }
  }
  
  delay(5);
}

void playMusic() {
  digitalWrite(LED_DIM_A, HIGH);
  digitalWrite(LED_DIM_B, HIGH);
  digitalWrite(LED_DIM_C, HIGH);
  
  tone(PIEZO_A, 440);
  delay(1000);
  noTone(PIEZO_A);
  return;
}