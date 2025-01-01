#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>


enum control {
  Left,
  Right,
  Up,
  Down,
};

// Số lượng pin cần sử dụng
const int n = 6;

// Mảng ở dưới là số thứ tự pin nối các chân in1,in2,... với thứ tự như sau:
// in1, in2, in3, in4, enA(cần pin có dấu ngã), enB(cần pin có dấu ngã)
const int pins[n] = {7, 6, 5, 4, 3, 9};
/* 
Nếu bị chỉnh lộn thì đổi cái mảng 2 chiều với tên các cột như sau:
in1, in2, in3, in4, enA, enB
*/
const int truthTable[][n] = {
  {LOW, HIGH, HIGH, LOW, 0, 255}, // Left
  {HIGH, LOW, LOW, HIGH, 255, 0}, // Right
  {HIGH, LOW, HIGH, LOW, 255, 255}, //Up
  {LOW, HIGH, LOW, HIGH, 255, 255} // Down
};

void setup() {
  Serial.begin(9600);
  Dabble.begin(9600, 0, 1);
}

void loop() {
  Dabble.processInput();
  if (GamePad.isUpPressed())
  {
    move(Up);
  }

  if (GamePad.isDownPressed())
  {
    move(Down);
  }

  if (GamePad.isLeftPressed())
  {
    move(Left);
  }

  if (GamePad.isRightPressed())
  {
    move(Right);
  }

  if (GamePad.isSquarePressed())
  {
    Serial.print("Square");
  }

  if (GamePad.isCirclePressed())
  {
    Serial.print("Circle");
  }

  if (GamePad.isCrossPressed())
  {
    Serial.print("Cross");
  }

  if (GamePad.isTrianglePressed())
  {
    Serial.print("Triangle");
  }

  if (GamePad.isStartPressed())
  {
    Serial.print("Start");
  }

  if (GamePad.isSelectPressed())
  {
    Serial.print("Select");
  }
}

void move(int action) {
  for (int i = 0; i < n; i++) {
    if (truthTable[action][i] == HIGH || truthTable[action][i] == LOW) {
      digitalWrite(pins[i], truthTable[action][i]);
    }
    else {
      analogWrite(pins[i], truthTable[action][i]);
    }
  }
}
