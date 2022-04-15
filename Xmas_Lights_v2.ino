volatile int mode = 1; // 0 = off, 1 = white, 2 = colored, 3 = flashing

void toggle(){
  if(digitalRead(3) == HIGH){
  if(mode == 3){
    mode = 0;
  }
  else{
    mode++;
  }
  delay(500);
 }
}

void setup() {
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(2, INPUT);
  attachInterrupt(digitalPinToInterrupt(3), toggle, HIGH);
}

void loop() {
 switch(mode){
    case 0:
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
      break;
    case 1:
      digitalWrite(12, LOW);
      digitalWrite(11, HIGH);
      break;
    case 2:
      digitalWrite(11, LOW);
      digitalWrite(12, HIGH);
      break;
    case 3:
      digitalWrite(11, LOW);
      digitalWrite(12, LOW);
      digitalWrite(11, HIGH);
      delay(1000);
      digitalWrite(11, LOW);
      digitalWrite(12, HIGH);
      delay(1000);
      digitalWrite(12, LOW);
      break;
  }
}
