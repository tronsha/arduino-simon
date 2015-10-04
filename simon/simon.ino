int pinSpeaker = 4;

int pinButtonA = 5;
int pinButtonB = 6;
int pinButtonC = 7;
int pinButtonD = 8;

int pinLedA = 9;
int pinLedB = 10;
int pinLedC = 11;
int pinLedD = 12;

float blueSound = 659.255;
float yellowSound = 554.365;
float redSound = 440.000;
float greenSound = 329.628;

void setup() {
  pinMode(pinButtonA, INPUT_PULLUP);
  pinMode(pinButtonB, INPUT_PULLUP);
  pinMode(pinButtonC, INPUT_PULLUP);
  pinMode(pinButtonD, INPUT_PULLUP);
  pinMode(pinLedA, OUTPUT);
  pinMode(pinLedB, OUTPUT);
  pinMode(pinLedC, OUTPUT);
  pinMode(pinLedD, OUTPUT);
  digitalWrite(pinLedA, HIGH);
  tone(pinSpeaker, blueSound, 1000);
  delay(1000);
  noTone(pinSpeaker);
  digitalWrite(pinLedA, LOW);
  digitalWrite(pinLedB, HIGH);
  tone(pinSpeaker, yellowSound, 1000);
  delay(1000);
  noTone(pinSpeaker);
  digitalWrite(pinLedB, LOW);
  digitalWrite(pinLedC, HIGH);
  tone(pinSpeaker, redSound, 1000);
  delay(1000);
  noTone(pinSpeaker);
  digitalWrite(pinLedC, LOW);
  digitalWrite(pinLedD, HIGH);
  tone(pinSpeaker, greenSound, 1000);
  delay(1000);
  noTone(pinSpeaker);
  digitalWrite(pinLedD, LOW);
}

void loop() {

}

