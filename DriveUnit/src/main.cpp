#include <Arduino.h>

// PWM出力ピン
const int servoPin1 = PA7_ALT0; // 使用するピンを指定（例: PA7）
const int servoPin2 = PA6_ALT0; // 使用するピンを指定（例: PA8）
const int servoPin3 = PA4_ALT0; // 使用するピンを指定（例: PA9）
const int servoPin4 = PA3_ALT0; // 使用するピンを指定（例: PA10）

void SetSpeed(int speed)
{
  // PWM信号のデューティ比を設定（0〜255）
  int pulseL = map(speed, 0, 180, 700, 2300);
  int pulseR = map(speed, 0, 180, 2300, 700);
  digitalWrite(servoPin1, HIGH);
  digitalWrite(servoPin2, HIGH);
  delayMicroseconds(pulseL);
  digitalWrite(servoPin1, LOW);
  digitalWrite(servoPin2, LOW);
  digitalWrite(servoPin3, HIGH);
  digitalWrite(servoPin4, HIGH);
  delayMicroseconds(pulseR);
  digitalWrite(servoPin3, LOW);
  digitalWrite(servoPin4, LOW);
  delay(20);
}

void setup()
{
  // PWM信号の出力ピンを設定
  pinMode(servoPin1, OUTPUT);
  pinMode(servoPin2, OUTPUT);
  pinMode(servoPin3, OUTPUT);
  pinMode(servoPin4, OUTPUT);
}

void loop()
{
  SetSpeed(80);
}