const int blue = 0;
const int yellow = 1;
const int red = 2;
const int green = 3;

const int pinSpeaker = 4;
const int pinButton[] = {5, 6, 7, 8};
const int pinLed[] = {9, 10, 11, 12};

const float sound[] = {659.255, 554.365, 440.000, 329.628};

int count = 0;
int values[] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
int speedLevel = 1200;

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
    values[i] = -1;
  }
  fnBlue(1000);
  fnYellow(1000);
  fnRed(1000);
  fnGreen(1000);
  delay(2000);
}

void lose() {
  Serial.println("Oh no...");
  speedLevel = speedLevel + 200;
  reset();
}

void win() {
  Serial.println("Very good my master!");
  speedLevel = speedLevel - 200;
  reset();
}

void showLeds() {
  for (int i = 0; i < count; i++) {
    if (values[i] == 0) {
      fnBlue(speedLevel);
    }
    if (values[i] == 1) {
      fnYellow(speedLevel);
    }
    if (values[i] == 2) {
      fnRed(speedLevel);
    }
    if (values[i] == 3) {
      fnGreen(speedLevel);
    }
    delay(200);
  }
}

void readButtons() {
  int pos = 0;
  while (true) {
    delay(50);
    if (values[pos] == blue) {
      //Serial.println("blue");
      if (digitalRead(pinButton[yellow]) == LOW || digitalRead(pinButton[red]) == LOW || digitalRead(pinButton[green]) == LOW) {
        lose();
      }
      if (digitalRead(pinButton[blue]) == LOW) {
        while (true) {
          digitalWrite(pinLed[blue], HIGH);
          if (digitalRead(pinButton[blue]) == HIGH) {
            digitalWrite(pinLed[blue], LOW);
            break;
          }
        }
        pos++;
        continue;
      }
    } else if (values[pos] == yellow) {
      //Serial.println("yellow");
      if (digitalRead(pinButton[blue]) == LOW || digitalRead(pinButton[red]) == LOW || digitalRead(pinButton[green]) == LOW) {
        lose();
      }
      if (digitalRead(pinButton[yellow]) == LOW) {
        while (true) {
          digitalWrite(pinLed[yellow], HIGH);
          if (digitalRead(pinButton[yellow]) == HIGH) {
            digitalWrite(pinLed[yellow], LOW);
            break;
          }
        }
        pos++;
        continue;
      }
    } else if (values[pos] == red) {
      //Serial.println("red");
      if (digitalRead(pinButton[blue]) == LOW || digitalRead(pinButton[yellow]) == LOW || digitalRead(pinButton[green]) == LOW) {
        lose();
      }
      if (digitalRead(pinButton[red]) == LOW) {
        while (true) {
          digitalWrite(pinLed[red], HIGH);
          if (digitalRead(pinButton[red]) == HIGH) {
            digitalWrite(pinLed[red], LOW);
            break;
          }
        }
        pos++;
        continue;
      }
    } else if (values[pos] == green) {
      //Serial.println("green");
      if (digitalRead(pinButton[blue]) == LOW || digitalRead(pinButton[yellow]) == LOW || digitalRead(pinButton[red]) == LOW) {
        lose();
      }
      if (digitalRead(pinButton[green]) == LOW) {
        while (true) {
          digitalWrite(pinLed[green], HIGH);
          if (digitalRead(pinButton[green]) == HIGH) {
            digitalWrite(pinLed[green], LOW);
            break;
          }
        }
        pos++;
        continue;
      }
    }
    if (pos == count) {
      return;
    }
  }
}

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
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
    speedLevel = 1200;
    reset();
  }
  values[count] = random(4);
  count++;
  showLeds();
  readButtons();
  if (count == 20) {
    win();
  }
  delay(500);
}
