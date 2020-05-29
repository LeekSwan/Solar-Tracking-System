//Runs motors for. We use stepper motors for better accuracy and the fact that it can run both ways. 


int sequence_num = 0;   // a counter for the coil sequence
int revolutions; //each revolution is 5.625 degrees
int steps_per_rev = 64;  // the number of steps per revolution


void run_motora(int revolutions){
 while (revolutions > 0) {
    for (int i = 0; i < steps_per_rev; i++) {
      steppera();
      delayMicroseconds(1000);
    }
    revolutions--;
  }
}

void run_motorb(int revolutions){
  while (revolutions > 0) {
    for (int i = 0; i < steps_per_rev; i++) {
      stepperb();
      delayMicroseconds(1000);
    }
    revolutions--;
  }
}




void stepperb() {
  switch (sequence_num) {
    case 0:
      digitalWrite(IN1b, LOW);
      digitalWrite(IN2b, LOW);
      digitalWrite(IN3b, LOW);
      digitalWrite(IN4b, HIGH);
      break;
    case 1:
      digitalWrite(IN1b, LOW);
      digitalWrite(IN2b, LOW);
      digitalWrite(IN3b, HIGH);
      digitalWrite(IN4b, HIGH);
      break;
    case 2:
      digitalWrite(IN1b, LOW);
      digitalWrite(IN2b, LOW);
      digitalWrite(IN3b, HIGH);
      digitalWrite(IN4b, LOW);
      break;
    case 3:
      digitalWrite(IN1b, LOW);
      digitalWrite(IN2b, HIGH);
      digitalWrite(IN3b, HIGH);
      digitalWrite(IN4b, LOW);
      break;
    case 4:
      digitalWrite(IN1b, LOW);
      digitalWrite(IN2b, HIGH);
      digitalWrite(IN3b, LOW);
      digitalWrite(IN4b, LOW);
      break;
    case 5:
      digitalWrite(IN1b, HIGH);
      digitalWrite(IN2b, HIGH);
      digitalWrite(IN3b, LOW);
      digitalWrite(IN4b, LOW);
      break;
    case 6:
      digitalWrite(IN1b, HIGH);
      digitalWrite(IN2b, LOW);
      digitalWrite(IN3b, LOW);
      digitalWrite(IN4b, LOW);
      break;
    case 7:
      digitalWrite(IN1b, HIGH);
      digitalWrite(IN2b, LOW);
      digitalWrite(IN3b, LOW);
      digitalWrite(IN4b, HIGH);
      break;
    default:
      digitalWrite(IN1b, LOW);
      digitalWrite(IN2b, LOW);
      digitalWrite(IN3b, LOW);
      digitalWrite(IN4b, LOW);
      break;
  }
  if (sequence_num < 7) {
    sequence_num++;
  } else {
    sequence_num = 0;
  }
}




void steppera() {
  switch (sequence_num) {
    case 0:
      digitalWrite(IN1a, LOW);
      digitalWrite(IN2a, LOW);
      digitalWrite(IN3a, LOW);
      digitalWrite(IN4a, HIGH);
      break;
    case 1:
      digitalWrite(IN1a, LOW);
      digitalWrite(IN2a, LOW);
      digitalWrite(IN3a, HIGH);
      digitalWrite(IN4a, HIGH);
      break;
    case 2:
      digitalWrite(IN1a, LOW);
      digitalWrite(IN2a, LOW);
      digitalWrite(IN3a, HIGH);
      digitalWrite(IN4a, LOW);
      break;
    case 3:
      digitalWrite(IN1a, LOW);
      digitalWrite(IN2a, HIGH);
      digitalWrite(IN3a, HIGH);
      digitalWrite(IN4a, LOW);
      break;
    case 4:
      digitalWrite(IN1a, LOW);
      digitalWrite(IN2a, HIGH);
      digitalWrite(IN3a, LOW);
      digitalWrite(IN4a, LOW);
      break;
    case 5:
      digitalWrite(IN1a, HIGH);
      digitalWrite(IN2a, HIGH);
      digitalWrite(IN3a, LOW);
      digitalWrite(IN4a, LOW);
      break;
    case 6:
      digitalWrite(IN1a, HIGH);
      digitalWrite(IN2a, LOW);
      digitalWrite(IN3a, LOW);
      digitalWrite(IN4a, LOW);
      break;
    case 7:
      digitalWrite(IN1a, HIGH);
      digitalWrite(IN2a, LOW);
      digitalWrite(IN3a, LOW);
      digitalWrite(IN4a, HIGH);
      break;
    default:
      digitalWrite(IN1a, LOW);
      digitalWrite(IN2a, LOW);
      digitalWrite(IN3a, LOW);
      digitalWrite(IN4a, LOW);
      break;
  }
  if (sequence_num < 7) {
    sequence_num++;
  } else {
    sequence_num = 0;
  }
}