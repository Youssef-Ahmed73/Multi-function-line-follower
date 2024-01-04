#define S0 5
#define S1 6
#define S2 3
#define S3 4
#define sensorOut 2

int redPW;
int greenPW;
int bluePW;

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  // Setting frequency-scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  Serial.begin(9600);
}

void loop() {
  
  get_color();

  if (redPW >= 20 && redPW <= 40 && greenPW > 20 && greenPW <= 40 && bluePW >= 40   && bluePW <= 70)
  {

    Serial.println('y');
  }

  if (redPW >= 30 && redPW <= 45 && greenPW >= 90 && greenPW <= 115  && bluePW >= 75   && bluePW <= 95 )
  {

    Serial.println('r');
  }

  if (redPW >= 90 && redPW <= 120 && greenPW >= 10 && greenPW <= 70  && bluePW >= 30   && bluePW <= 100)
  {

    Serial.println('g');
  }

}
