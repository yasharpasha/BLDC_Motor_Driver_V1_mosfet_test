// MOSFET pin tanımları
#define A_H 3   // Faz A üst MOSFET (PWM)
#define A_L 2   // Faz A alt MOSFET
#define B_H 9   // Faz B üst MOSFET (PWM)
#define B_L 8   // Faz B alt MOSFET
#define C_H 10  // Faz C üst MOSFET (PWM)
#define C_L 12  // Faz C alt MOSFET

#define PHASE_A A1
#define PHASE_B A2
#define PHASE_C A3
int hiz =1000;
int pwmDuty = 10;  // PWM duty değeri (maks 255)

void setup() {
  // MOSFET pinlerini çıkış olarak ayarla
  pinMode(A_L, OUTPUT);
  pinMode(B_L, OUTPUT);
  pinMode(C_L, OUTPUT);

  pinMode(A_H, OUTPUT);
  pinMode(B_H, OUTPUT);
  pinMode(C_H, OUTPUT);

  digitalWrite(A_L, HIGH);
  analogWrite(A_H, 0);
  digitalWrite(B_L, HIGH);
  analogWrite(B_H, 0);
  digitalWrite(C_L, HIGH);
  analogWrite(C_H, 0);
}

void step1() {  // A+ B-
  analogWrite(A_H, pwmDuty);
  digitalWrite(B_L, HIGH);
  digitalWrite(A_L, HIGH);
  digitalWrite(C_L, LOW);
  analogWrite(B_H, 0);
  analogWrite(C_H, 0);
}

void step2() {  // A+ C-
  analogWrite(A_H, pwmDuty);
  digitalWrite(C_L, HIGH);
  digitalWrite(A_L, HIGH);
  digitalWrite(B_L, LOW);
  analogWrite(B_H, 0);
  analogWrite(C_H, 0);
}

void step3() {  // B+ C-
  analogWrite(B_H, pwmDuty);
  digitalWrite(C_L, HIGH);
  digitalWrite(A_L, LOW);
  digitalWrite(B_L, HIGH);
  analogWrite(A_H, 0);
  analogWrite(C_H, 0);
}

void step4() {  // B+ A-
  analogWrite(B_H, pwmDuty);
  digitalWrite(A_L, HIGH);
  digitalWrite(B_L, HIGH);
  digitalWrite(C_L, LOW);
  analogWrite(A_H, 0);
  analogWrite(C_H, 0);
}

void step5() {  // C+ A-
  analogWrite(C_H, pwmDuty);
  digitalWrite(A_L, HIGH);
  digitalWrite(B_L, LOW);
  digitalWrite(C_L, HIGH);
  analogWrite(A_H, 0);
  analogWrite(B_H, 0);
}

void step6() {  // C+ B-

  analogWrite(C_H, pwmDuty);
  digitalWrite(B_L, HIGH);
  digitalWrite(A_L, LOW);
  digitalWrite(C_L, HIGH);
  analogWrite(A_H, 0);
  analogWrite(B_H, 0);
}
// Motoru durdur
void disableAll() {
  digitalWrite(A_L, HIGH);
  analogWrite(A_H, 0);
  digitalWrite(B_L, HIGH);
  analogWrite(B_H, 0);
  digitalWrite(C_L, HIGH);
  analogWrite(C_H, 0);
}
void loop() {
  step6();
  delay(hiz);
  step5();
  delay(hiz);
  step4();
  delay(hiz);
  step3();
  delay(hiz);
  step2();
  delay(hiz);
  step1();
  delay(hiz);
  // Motoru durdur
}
