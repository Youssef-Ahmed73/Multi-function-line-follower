void max_right()
{
  analogWrite(Rm, rmm);     //max speed
  analogWrite(Lm, lmm);     //max speed
  digitalWrite(In1, HIGH);
  digitalWrite(In3, LOW);
  digitalWrite(In2, LOW);
  digitalWrite(In4, HIGH);

  R_sensor = digitalRead(R_ir);
  L_sensor = digitalRead(L_ir);
  RR_sensor = digitalRead(RR_ir);
  LL_sensor = digitalRead(LL_ir);
}

void max_left()
{
  analogWrite(Rm, rmm);     //max speed
  analogWrite(Lm, lmm);     //max speed
  digitalWrite(In1, LOW);
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  digitalWrite(In2, HIGH);

  R_sensor = digitalRead(R_ir);
  L_sensor = digitalRead(L_ir);
  RR_sensor = digitalRead(RR_ir);
  LL_sensor = digitalRead(LL_ir);
}

void max_forward()
{
  analogWrite(Rm, rmm);     //average speed
  analogWrite(Lm, lmm);     //average speed
  digitalWrite(In1, LOW);
  digitalWrite(In3, LOW);
  digitalWrite(In2, HIGH);
  digitalWrite(In4, HIGH);
}
