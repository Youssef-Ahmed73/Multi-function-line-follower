void get_red()
{
  // Setting red filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);

  // Reading the output frequency
  redPW = pulseIn(sensorOut, LOW);

  // Printing the value on the serial monitor
  //  Serial.print("R= ");//printing name
  //  Serial.print(redPW);//printing RED color frequency
  // Serial.print("  ");


}


void get_green()
{
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);


  // Reading the output frequency
  greenPW = pulseIn(sensorOut, LOW);


  // Printing the value on the serial monitor
  // Serial.print("G= ");//printing name
  //  Serial.print(greenPW);//printing RED color frequency
  //  Serial.print("  ");


}


void get_blue()
{
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);


  // Reading the output frequency
  bluePW = pulseIn(sensorOut, LOW);


  // Printing the value on the serial monitor

  //  Serial.print("B= ");//printing name
  //  Serial.print(bluePW);//printing RED color frequency
  //Serial.println("  ");

}


void get_color()
{
  get_red();
  get_green();
  get_blue();

}
