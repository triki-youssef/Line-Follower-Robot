// Pin definitions
#define LEFT_SENSOR 3
#define RIGHT_SENSOR 2

#define ENA 5     // Left motor speed
#define ENB 6     // Right motor speed

#define IN1 8     // Left motor direction
#define IN2 9
#define IN3 10    // Right motor direction
#define IN4 11

int speed = 130;  // Half speed (range 0–255)

void setup() {
  pinMode(LEFT_SENSOR, INPUT);
  pinMode(RIGHT_SENSOR, INPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Stop motors initially
  stopMotors();
}

void loop() {
  int left = digitalRead(LEFT_SENSOR);
  int right = digitalRead(RIGHT_SENSOR);

  if (left == LOW && right == LOW) {
    // On the line: go forward
    forward();
  } else if (left == LOW && right == HIGH) {
    // Turn left
    turnLeft();
  } else if (left == HIGH && right == LOW) {
    // Turn right
    turnRight();
  } else {
    // Lost track: stop or search
    stopMotors();
  }
}

// Forward motion
void forward() {
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// Turn left: left motor backward, right motor forward
void turnLeft() {
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// Turn right: left motor forward, right motor backward
void turnRight() {
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// Stop both motors
void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
