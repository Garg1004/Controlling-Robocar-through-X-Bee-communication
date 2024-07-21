int ir1 = A0;
int ir2 = A1;
int pin = 4;
int count = 0, l, r;
unsigned long value = 0 ;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(pin, INPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}
void forward() {
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  delay(10);
}
void left() {
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  delay(10);
}

void right() {
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  delay(10);
}
void stop() {
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);

}

long st = millis(), endt;
int flag = 0;

void loop() {

  if (Serial.read() == 'M' || flag == 1 )
  {

    if (digitalRead(pin) > 0)
    {
      value = pulseIn(pin, HIGH);
      Serial.print("Value =");
      Serial.println(value);
      if (value > 1500 && value < 2000)
        Serial.println("Gantry 1 Crossed");

      if (value > 2500 && value < 3000)
        Serial.println("Gantry 2 Crossed");

      if (value > 500 && value < 1000)
      {
        Serial.println("Gantry 3 Crossed");
        stop();
        delay(1000);
      }
    }

    flag = 1;

    l = digitalRead(ir1);
    r = digitalRead(ir2);
    if (l == 1 && r == 1)
      forward();

    if (l == 0 && r == 1)
      left();

    if (l == 1 && r == 0)
      right();

    if (l == 0 && r == 0)
    {
      // forward();
      endt = millis();

      if (endt - st > 500)
      {
        count++;

        Serial.print("Count = ");
        Serial.println(count);

        //       Serial.print("Time = ");
        //       Serial.println(endt - st);
        st = millis();
      }

      if (count == 1)
        forward();
      Serial.print("forward :");
      Serial.println(count);
      if (count == 2)
      {
        right();
        delay(500);
        Serial.print("left :");
        Serial.println( count);
      }
      if (count == 3)
        forward();
      Serial.print(count);
      if (count == 4)
      {
        forward();

        Serial.print(count);
        Serial.println("left");

      }
      if (count == 5)
      {
        right();
        delay(1000);
        Serial.print(count);
        Serial.println("right");

      }
      if (count > 5)
      {
        stop();
        Serial.print("Stop");
        flag = 0;
      }
    }


  }
}
  void ultrasonic(){
  digitalWrite(trigpin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigpin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigpin, LOW);
    duration = pulseIn(echopin, HIGH);
    dcm = duration * 0.034 / 2;
    if (dcm <= 30)
      stop();
  }
}
