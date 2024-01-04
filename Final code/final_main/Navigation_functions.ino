void move_forward()
{
  analogWrite(Rm, rm);     //average speed
  analogWrite(Lm, lm);     //average speed
  digitalWrite(In1, LOW);
  digitalWrite(In3, LOW);
  digitalWrite(In2, HIGH);
  digitalWrite(In4, HIGH);
}


void turn_right()
{
  analogWrite(Rm, rm);          //average speed
  analogWrite(Lm, lm + 10);     //average speed
  digitalWrite(In1, HIGH);
  digitalWrite(In3, LOW);
  digitalWrite(In2, LOW);
  digitalWrite(In4, HIGH);

  R_sensor = digitalRead(R_ir);
  L_sensor = digitalRead(L_ir);
  RR_sensor = digitalRead(RR_ir);
  LL_sensor = digitalRead(LL_ir);
}

void turn_left()
{
  analogWrite(Rm, rm + 25);      //average speed
  analogWrite(Lm, lm);          //average speed
  digitalWrite(In1, LOW);
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  digitalWrite(In2, HIGH);

  R_sensor = digitalRead(R_ir);
  L_sensor = digitalRead(L_ir);
  RR_sensor = digitalRead(RR_ir);
  LL_sensor = digitalRead(LL_ir);
}


void left_branch()
{

  analogWrite(Rm, rm + 20 );    //average speed
  analogWrite(Lm, lm - 20 ) ;     //average speed
  digitalWrite(In1, LOW);
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  digitalWrite(In2, HIGH);

  R_sensor = digitalRead(R_ir);
  L_sensor = digitalRead(L_ir);
  RR_sensor = digitalRead(RR_ir);
  LL_sensor = digitalRead(LL_ir);

  if (R_sensor == 0 && L_sensor == 0 && RR_sensor == 0 && LL_sensor == 0)
  {
    left = false;
    dir = 1;
  }
}


void right_branch()
{
  analogWrite(Rm, rm - 20 );     //average speed
  analogWrite(Lm, lm + 20 );     //average speed
  digitalWrite(In1, HIGH);
  digitalWrite(In3, LOW);
  digitalWrite(In2, LOW);
  digitalWrite(In4, HIGH);

  R_sensor = digitalRead(R_ir);
  L_sensor = digitalRead(L_ir);
  RR_sensor = digitalRead(RR_ir);
  LL_sensor = digitalRead(LL_ir);

  if (R_sensor == 0 && L_sensor == 0 && RR_sensor == 0 && LL_sensor == 0  )
  {
    right = false;
    dir = 2;
  }
}
void remember()
{
  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);
  digitalWrite(In3, LOW);
  digitalWrite(In4, LOW);
  delay(200);

  if (dir == 1)
  {
    start_time = millis();
    leftt = true;
  }
  else if (dir == 2)
  {
    start_time = millis();
    rightt = true;
  }
  else if (dir == 0)
  {
    start_time = millis();
    leftt = true;
  }
}

void return_right()
{
  analogWrite(Rm, rm );    //average speed
  analogWrite(Lm, lmm );     //average speed
  if (millis() - start_time <= 700)
  {
    digitalWrite(In1, HIGH);
    digitalWrite(In3, LOW);
    digitalWrite(In2, LOW);
    digitalWrite(In4, HIGH);

    R_sensor = digitalRead(R_ir);
    L_sensor = digitalRead(L_ir);
    RR_sensor = digitalRead(RR_ir);
    LL_sensor = digitalRead(LL_ir);
  }
  else
  {
    dir = 2;
    rightt = false;
  }
}

void return_left()
{
  analogWrite(Rm, rmm );    //average speed
  analogWrite(Lm, lm );     //average speed
  if (millis() - start_time <= 700)
  {
    digitalWrite(In1, LOW);
    digitalWrite(In3, HIGH);
    digitalWrite(In2, HIGH);
    digitalWrite(In4, LOW);

    R_sensor = digitalRead(R_ir);
    L_sensor = digitalRead(L_ir);
    RR_sensor = digitalRead(RR_ir);
    LL_sensor = digitalRead(LL_ir);
  }
  else
  {
    dir = 1;
    leftt = false;
  }
}
