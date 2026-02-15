#define ROT_RPWM 6
#define ROT_LPWM 7

#define LIFT_RPWM 4
#define LIFT_LPWM 5

#define COIL_ENA 9
#define COIL_IN1 33
#define COIL_IN2 35

#define HOR_ENA 8
#define HOR_IN1 25
#define HOR_IN2 27

void setup() {

  pinMode(ROT_RPWM, OUTPUT);
  pinMode(ROT_LPWM, OUTPUT);
  pinMode(LIFT_RPWM, OUTPUT);
  pinMode(LIFT_LPWM, OUTPUT);

  pinMode(COIL_ENA, OUTPUT);
  pinMode(COIL_IN1, OUTPUT);
  pinMode(COIL_IN2, OUTPUT);

  pinMode(HOR_ENA, OUTPUT);
  pinMode(HOR_IN1, OUTPUT);
  pinMode(HOR_IN2, OUTPUT);
}

void loop() {

  analogWrite(LIFT_RPWM, 200);
  analogWrite(LIFT_LPWM, 0);
  delay(4000);

  stopLift();
  delay(1000);

  analogWrite(ROT_RPWM, 200);
  analogWrite(ROT_LPWM, 0);
  delay(2000);

  stopRotation();
  delay(1000);

  digitalWrite(HOR_IN1, HIGH);
  digitalWrite(HOR_IN2, LOW);
  analogWrite(HOR_ENA, 180);
  delay(1500);

  stopHorizontal();
  delay(1000);

  digitalWrite(COIL_IN1, HIGH);
  digitalWrite(COIL_IN2, LOW);
  analogWrite(COIL_ENA, 200);
  delay(2000);

  stopCoil();
  delay(3000);

  digitalWrite(COIL_IN1, LOW);
  digitalWrite(COIL_IN2, HIGH);
  analogWrite(COIL_ENA, 200);
  delay(2000);

  stopCoil();

  analogWrite(LIFT_RPWM, 0);
  analogWrite(LIFT_LPWM, 200);
  delay(4000);

  stopLift();

  while(true);
}

void stopLift() {
  analogWrite(LIFT_RPWM, 0);
  analogWrite(LIFT_LPWM, 0);
}

void stopRotation() {
  analogWrite(ROT_RPWM, 0);
  analogWrite(ROT_LPWM, 0);
}

void stopHorizontal() {
  digitalWrite(HOR_IN1, LOW);
  digitalWrite(HOR_IN2, LOW);
  analogWrite(HOR_ENA, 0);
}

void stopCoil() {
  digitalWrite(COIL_IN1, LOW);
  digitalWrite(COIL_IN2, LOW);
  analogWrite(COIL_ENA, 0);
}
