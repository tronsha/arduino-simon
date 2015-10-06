int blue = 0;
int yellow = 1;
int red = 2;
int green = 3;

int pinSpeaker = 4;
int pinButton[] = {5, 6, 7, 8};
int pinLed[] = {9, 10, 11, 12};

float sound[] = {659.255, 554.365, 440.000, 329.628};

int count = 0;
int values[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void fnBlue(int t) {
  digitalWrite(pinLed[blue], HIGH);
  tone(pinSpeaker, sound[blue], t);
  delay(t);
  noTone(pinSpeaker);
  digitalWrite(pinLed[blue], LOW);
}

void fnYellow(int t) {
  digitalWrite(pinLed[yellow], HIGH);
  tone(pinSpeaker, sound[yellow], t);
  delay(t);
  noTone(pinSpeaker);
  digitalWrite(pinLed[yellow], LOW);
}

void fnRed(int t) {
  digitalWrite(pinLed[red], HIGH);
  tone(pinSpeaker, sound[red], t);
  delay(t);
  noTone(pinSpeaker);
  digitalWrite(pinLed[red], LOW);
}

void fnGreen(int t) {
  digitalWrite(pinLed[green], HIGH);
  tone(pinSpeaker, sound[green], t);
  delay(t);
  noTone(pinSpeaker);
  digitalWrite(pinLed[green], LOW);
}

void reset() {
  count = 0;
  for (int i = 0; i < 20; i++) {
    values[i] = 0;
  }
  fnBlue(1000);
  fnYellow(1000);
  fnRed(1000);
  fnGreen(1000);
}

void setup() {
  pinMode(pinButton[blue], INPUT_PULLUP);
  pinMode(pinButton[yellow], INPUT_PULLUP);
  pinMode(pinButton[red], INPUT_PULLUP);
  pinMode(pinButton[green], INPUT_PULLUP);
  pinMode(pinLed[blue], OUTPUT);
  pinMode(pinLed[yellow], OUTPUT);
  pinMode(pinLed[red], OUTPUT);
  pinMode(pinLed[green], OUTPUT);
  reset();
}

void loop() {
  if (digitalRead(pinButton[blue]) == LOW && digitalRead(pinButton[yellow]) == LOW && digitalRead(pinButton[red]) == LOW && digitalRead(pinButton[green]) == LOW) {
    reset();
  }
  delay(500);
}
