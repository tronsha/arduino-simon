int pinSpeaker = 4;
int pinButtonA = 5;
int pinButtonB = 6;
int pinButtonC = 7;
int pinButtonD = 8;
int pinLedA = 9;
int pinLedB = 10;
int pinLedC = 11;
int pinLedD = 12;

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
  tone(pinSpeaker, 329.628, 1000);
  delay(1000);
  noTone(pinSpeaker);
  digitalWrite(pinLedA, LOW);
  digitalWrite(pinLedB, HIGH);
  tone(pinSpeaker, 440, 1000);
  delay(1000);
  noTone(pinSpeaker);
  digitalWrite(pinLedB, LOW);
  digitalWrite(pinLedC, HIGH);
  tone(pinSpeaker, 554.365, 1000);
  delay(1000);
  noTone(pinSpeaker);
  digitalWrite(pinLedC, LOW);
  digitalWrite(pinLedD, HIGH);
  tone(pinSpeaker, 659.255, 1000);
  delay(1000);
  noTone(pinSpeaker);
  digitalWrite(pinLedD, LOW);
}

void loop() {

}

