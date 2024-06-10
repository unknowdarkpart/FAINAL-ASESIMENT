#include <NewPing.h>
#include <Servo.h>

#define trig A0
#define echo A1
#define max 200
NewPing sonar(trig, echo, max);
Servo rr;

const int m1 = 4;
const int m2 = 5;
const int m3 = 10;
const int m4 = 11;
int distance = 100;

void setup() {
  rr.attach(9);
  rr.write(115);
  distance = ReadPing();
  delay(100);
  distance = ReadPing();
  delay(100);
  distance = ReadPing();
  delay(100);
  distance = ReadPing();
  delay(100);
  distance = ReadPing();
  delay(100);
}

void loop() {
  int destancer = 0;
  int destancel = 0;
  if (distance <= 20) {
    stop();
    delay(100);
    moveback();
    delay(100);
    stop();
    destancer = ReadPing();
    destancel = ReadPing();

    if (destancer <= destancel) {
      turnright();
    } else {
      turnleft();
    }
  } else {
    moveforward();
  }
}

int lookright() {
  rr.write(70);
  int distance = ReadPing();
  delay(100);
  rr.write(115);
  return distance;
}

int lookleft() {
  rr.write(170);
  int distance = ReadPing();
  delay(100);
  rr.write(115);
  return distance;
}

int ReadPing() {
  delay(100);
  int cm = sonar.ping_cm();
  if (cm == 0) {
    cm = 250;
  }
  return cm;
}

void moveforward() {
  digitalWrite(m1, LOW);
  digitalWrite(m2, HIGH);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);
}

void stop() {
  digitalWrite(m1, HIGH);
  digitalWrite(m2, HIGH);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, HIGH);
}

void moveback() {
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);
}

void turnright() {
  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
  digitalWrite(m3, LOW);
  digitalWrite(m4, HIGH);
  delay(100);
  moveforward();
}

void turnleft() {
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  digitalWrite(m3, LOW);
  digitalWrite(m4, LOW);
  delay(100);
  moveforward();
}
