
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <AFMotor.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int trigfront = A0;     // chân trig của HC-SR04 đằng trước
const int echofront = A1;// chân echo của HC-SR04 đằng trước
const int trigside = A2;     // chân trig của HC-SR04 phía bên
const int echoside = A3; // chân echo của HC-SR04 phía bên

AF_DCMotor motor1(1); // khai báo động cơ
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void setup() {
  Serial.begin(9600);            // giao tiếp Serial với baudrate 9600
  Serial.println("Start!");
  pinMode(13, INPUT);  // nút nhấn start
  pinMode(trigfront, OUTPUT);  // chân trig sẽ phát tín hiệu
  pinMode(echofront, INPUT);// chân echo sẽ nhận tín hiệu
  pinMode(trigside, OUTPUT);
  pinMode(echoside, INPUT);
  lcd.init();
  lcd.begin(16, 2); // iInit the LCD for 16 chars 2 lines
  lcd.backlight(); // Turn on the backligt (try lcd.noBaklight() to turn it off)
  lcd.setCursor(0, 0); //First line
  lcd.print("MRZAIZAI2K");
  lcd.setCursor(0, 1); //First line
  lcd.print("START!");

  // turn on motor
  motor1.run(RELEASE); /////không cho động cơ chạy lúc đầu
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  delay(1000);
}
//////////////dừng/////////////////////////////////////////////////////////////////////////////////////////////////////
void dung() {
  lcd.setCursor(11, 0 ); //First line
  lcd.print("DUNG");
  motor1.run(RELEASE); /////không cho động cơ chạy lúc đầu
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
//////////////tien/////////////////////////////////////////////////////////////////////////////////////////////////////
void tien() {
  lcd.setCursor(11, 0 ); //First line
  lcd.print("TIEN");
  int i = 50; 
  motor1.setSpeed(i);     // chọn tốc độ tùy vào project của bạn
  motor2.setSpeed(i);
  motor3.setSpeed(i + 20);
  motor4.setSpeed(i + 30);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

//////////////lui/////////////////////////////////////////////////////////////////////////////////////////////////////
void lui() {
  lcd.setCursor(11, 0); //First line
  lcd.print(" LUI");
  int    i = 50;
  motor1.setSpeed(i);      // chọn tốc độ tùy vào project của bạn
  motor2.setSpeed(i);
  motor3.setSpeed(i + 20);
  motor4.setSpeed(i + 30);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

//////////////RE TRAI/////////////////////////////////////////////////////////////////////////////////////////////////////
void retrai() {
  lcd.setCursor(11, 0); //First line
  lcd.print("TRAI");
  int i = 150;
  motor1.setSpeed(i);      // chọn tốc độ tùy vào project của bạn
  motor2.setSpeed(i);
  motor3.setSpeed(i + 20);
  motor4.setSpeed(i + 30);
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);

}

//////////////RE phai/////////////////////////////////////////////////////////////////////////////////////////////////////
void rephai() {
  lcd.setCursor(11, 0); //First line
  lcd.print("PHAI");
  int i = 150;
  motor1.setSpeed(i);      // chọn tốc độ tùy vào project của bạn
  motor2.setSpeed(i);
  motor3.setSpeed(i + 20);
  motor4.setSpeed(i + 30);
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);

}
/////////đo khoảng cách trước//////////////////////////////////////////////////////////////////////////////////////////
int distancefront() {
  int distancefront;
  unsigned long durationfront;
  digitalWrite(trigfront, 0);  // tắt chân trig
  delayMicroseconds(2);
  digitalWrite(trigfront, 1);  // phát xung từ chân trig
  delayMicroseconds(5);   // xung có độ dài 5 microSeconds
  digitalWrite(trigfront, 0);  // tắt chân trig
  durationfront = pulseIn(echofront, HIGH);
  // Tính khoảng cách đến vật.
  distancefront = int(durationfront / 2 / 29.412);
  return distancefront;

}
//////đo khoảng cách bên/////////////////////////////////////////////////////////////////////////////////////////////////
int distanceside() {
  unsigned long durationside; // biến đo thời gian
  int distanceside;
  /* Phát xung từ chân trig */

  digitalWrite(trigside, 0);  // tắt chân trig
  delayMicroseconds(2);
  digitalWrite(trigside, 1);  // phát xung từ chân trig
  delayMicroseconds(5);   // xung có độ dài 5 microSeconds
  digitalWrite(trigside, 0);

  durationside = pulseIn(echoside, HIGH);
  // Tính khoảng cách đến vật.
  distanceside = int(durationside / 2 / 29.412);
  return distanceside;
}
void loop() {/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  int f, s, state = 0;
  int a = 30;
  f = distancefront();
  s = distanceside();
  Serial.print("distancefront = ");
  Serial.print(f);
  Serial.println("cm\n");
  Serial.print("distanceside = ");
  Serial.print(s);
  Serial.println("cm\n");
  lcd.clear();
  lcd.setCursor(0, 0); //First line
  lcd.print("TRANG THAI");
  lcd.setCursor(0, 1); //First line
  lcd.print("FR: ");
  lcd.print(f);
  lcd.setCursor(8, 1);
  lcd.print("SI: ");
  lcd.print(s);

  if (digitalRead(13) == 0) {
    state = 0;
    if (( f < a) && (s < a))
    { state = 1;//////re trai////
    }
    if (( f < a) && (s > a))
    { state = 2;/////rẽ phải////
    }
    if (( f > a) && (s < a))
    { state = 3;/////đi thẳng/////
    }
    if (( f > a) && (s > a))
    { state = 4;////đi thẳng////
    }
    switch (state) {
      case 1://////re trai////
        retrai();
        delay(120);
        break;
      case 2://///rẽ phải////
        rephai();
        delay(125);
        break;
      case 3://///đi thẳng/////
        tien();
        delay(100);
        break;
      case 4:////đi thẳng//
        tien();
        delay(150);
        break;
    }
    delay(50);
  }
  else {
    dung();
    delay(500);
  }
}
