struct light {
  byte id;
  byte led;
  byte button;
  float frequency;
};

const light blue = {0, 9, 5, 659.255};
const light yellow = {1, 10, 6, 554.365};
const light red = {2, 11, 7, 440.000};
const light green = {3, 12, 8, 329.628};

const light lights[] = {blue, yellow, red, green};

const int pinSpeaker = 4;

int count = 0;
byte values[100];

int speedLevel = 1200;

void outputLight(byte id) {
  digitalWrite(lights[id].led, HIGH);
  tone(pinSpeaker, lights[id].frequency, speedLevel);
  delay(speedLevel);
  noTone(pinSpeaker);
  digitalWrite(lights[id].led, LOW);
}

void outputLights() {
  for (int i = 0; i < count; i++) {
    outputLight(values[i]);
    delay(200);
  }
}

void allLedOn () {
  digitalWrite(lights[0].led, HIGH);
  digitalWrite(lights[1].led, HIGH);
  digitalWrite(lights[2].led, HIGH);
  digitalWrite(lights[3].led, HIGH);
}

void allLedOff () {
  digitalWrite(lights[0].led, LOW);
  digitalWrite(lights[1].led, LOW);
  digitalWrite(lights[2].led, LOW);
  digitalWrite(lights[3].led, LOW);
}

void reset() {
  count = 0;
  for (int i = 0; i < 100; i++) {
    values[i] = -1;
  }
}

void lose() {
  Serial.println("Oh no...");
  reset();
}

void win() {
  Serial.println("Very good my master!");
  reset();
}

void readButtons() {
  int pos = 0;
  while (true) {
    delay(50);
    if (values[pos] == blue.id) {
      if (digitalRead(yellow.button) == LOW || digitalRead(red.button) == LOW || digitalRead(green.button) == LOW) {
        lose();
      }
      if (digitalRead(blue.button) == LOW) {
        while (true) {
          digitalWrite(blue.led, HIGH);
          if (digitalRead(blue.button) == HIGH) {
            digitalWrite(blue.led, LOW);
            break;
          }
        }
        pos++;
        continue;
      }
    } else if (values[pos] == yellow.id) {
      if (digitalRead(blue.button) == LOW || digitalRead(red.button) == LOW || digitalRead(green.button) == LOW) {
        lose();
      }
      if (digitalRead(yellow.button) == LOW) {
        while (true) {
          digitalWrite(yellow.led, HIGH);
          if (digitalRead(yellow.button) == HIGH) {
            digitalWrite(yellow.led, LOW);
            break;
          }
        }
        pos++;
        continue;
      }
    } else if (values[pos] == red.id) {
      if (digitalRead(blue.button) == LOW || digitalRead(yellow.button) == LOW || digitalRead(green.button) == LOW) {
        lose();
      }
      if (digitalRead(red.button) == LOW) {
        while (true) {
          digitalWrite(red.led, HIGH);
          if (digitalRead(red.button) == HIGH) {
            digitalWrite(red.led, LOW);
            break;
          }
        }
        pos++;
        continue;
      }
    } else if (values[pos] == green.id) {
      if (digitalRead(blue.button) == LOW || digitalRead(yellow.button) == LOW || digitalRead(red.button) == LOW) {
        lose();
      }
      if (digitalRead(green.button) == LOW) {
        while (true) {
          digitalWrite(green.led, HIGH);
          if (digitalRead(green.button) == HIGH) {
            digitalWrite(green.led, LOW);
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
  pinMode(lights[0].button, INPUT_PULLUP);
  pinMode(lights[1].button, INPUT_PULLUP);
  pinMode(lights[2].button, INPUT_PULLUP);
  pinMode(lights[3].button, INPUT_PULLUP);
  pinMode(lights[0].led, OUTPUT);
  pinMode(lights[1].led, OUTPUT);
  pinMode(lights[2].led, OUTPUT);
  pinMode(lights[3].led, OUTPUT);
  reset();
}

void loop() {
  values[count] = random(4);
  count++;
  outputLights();
  readButtons();
  if (count == 100) {
    win();
  }
  delay(500);
}
