#include <Servo.h>
#include <math.h>

Servo lServo;
Servo rServo;

// Arm dimensions (adjust to your actual hardware)
float l1 = 90.0; // Length of first link in mm
float l2 = 110.0; // Length of second link in mm

// Current target coordinates (starting "neutral" point)
float x = 485; 
float y = -15; 

// Boundaries for safe operation
float xmin = -800;
float xmax = 800;
float ymin = -800;
float ymax = 800;

#define leftButton 12
#define rightButton 13
#define upButton 10
#define downButton 11

#define leftServoPin 8
#define rightServoPin 9

void setup() {
  lServo.attach(leftServoPin);
  rServo.attach(rightServoPin);

  pinMode(leftButton, INPUT_PULLUP);
  pinMode(rightButton, INPUT_PULLUP);
  pinMode(upButton, INPUT_PULLUP);
  pinMode(downButton, INPUT_PULLUP);

  lServo.write(90); // Neutral position
  rServo.write(90);
  delay(2000);

  Serial.begin(9600);
}

void loop() {
  bool moved = false;

  if (digitalRead(leftButton) == LOW) {
    x -= 50; // move left
    moved = true;
    delay(300);
  }
  if (digitalRead(rightButton) == LOW) {
    x += 50; // move right
    moved = true;
    delay(300);
  }
  if (digitalRead(upButton) == LOW) {
    y += 50; // move up
    moved = true;
    delay(300);
  }
  if (digitalRead(downButton) == LOW) {
    y -= 50; // move down
    moved = true;
    delay(300);
  }

  // Constrain within bounds
  x = constrain(x, xmin, xmax);
  y = constrain(y, ymin, ymax);

  if (moved) {
    calculateAndMove(x, y);
  }
}

void calculateAndMove(float xc, float yc) {
  float d = sqrt(xc * xc + yc * yc);

  // Check if the target is reachable
  // if (d > (l1 + l2)) {
  //   Serial.println("Target out of reach.");
  //   return;
  // }

  // Law of cosines
  float cosAngle2 = (xc*xc + yc*yc - l1*l1 - l2*l2) / (2 * l1 * l2);
  cosAngle2 = constrain(cosAngle2, -1.0, 1.0); // Safety

  float angle2 = acos(cosAngle2);
  float angle1 = atan2(yc, xc) - atan2(l2 * sin(angle2), l1 + l2 * cos(angle2));

  // Convert to degrees
  float servoLeftAngle = degrees(angle1);
  float servoRightAngle = degrees(angle2);

  Serial.print("X: "); Serial.print(xc);
  Serial.print(", Y: "); Serial.print(yc);
  Serial.print(" | Theta1: "); Serial.print(servoLeftAngle);
  Serial.print(", Theta2: "); Serial.println(servoRightAngle);

  // Map angles to servo range if needed
  lServo.write(servoRightAngle + 90);  // Offset if your servo zero is not perfectly aligned
  rServo.write(servoLeftAngle + 90);
}