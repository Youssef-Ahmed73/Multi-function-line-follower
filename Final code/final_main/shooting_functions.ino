void red_shooting()
{
  //stop
  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);
  digitalWrite(In3, LOW);
  digitalWrite(In4, LOW);

  //shoot
  shoot.write(10);
  delay(shootingtime);
  shoot.write(90);

  //turn 180 degree
  analogWrite(Rm, rm + 60 );     //average speed
  analogWrite(Lm, lm + 50 );     //average speed
  digitalWrite(In1, LOW);
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  digitalWrite(In2, HIGH);

  R_sensor = digitalRead(R_ir);
  L_sensor = digitalRead(L_ir);
  RR_sensor = digitalRead(RR_ir);
  LL_sensor = digitalRead(LL_ir);
  M_sensor = digitalRead(M_ir);

  delay (500);

  //180 degree finished
  if ( M_sensor == 1 )
  {
    r++;
    red_shoot = false;
  }
}



void green_shooting()
{
  //stop
  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);
  digitalWrite(In3, LOW);
  digitalWrite(In4, LOW);

  //shoot
  shoot.write(170);
  delay(shootingtime);
  shoot.write(90);

  //turn 180 degree
  analogWrite(Rm, rm + 50 );     //average speed
  analogWrite(Lm, lm + 60 );     //average speed
  digitalWrite(In1, HIGH);
  digitalWrite(In3, LOW);
  digitalWrite(In4, HIGH);
  digitalWrite(In2, LOW);

  R_sensor = digitalRead(R_ir);
  L_sensor = digitalRead(L_ir);
  RR_sensor = digitalRead(RR_ir);
  LL_sensor = digitalRead(LL_ir);
  M_sensor = digitalRead(M_ir);

  delay (500);

  //180 degree finished
  if ( M_sensor == 1 )
  {
    g++;
    green_shoot = false;
  }
}
