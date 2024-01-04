//section A

#include<SoftwareSerial.h>
#include<Servo.h>

SoftwareSerial bluetooth(A5, A4); //rx and tx

#define Rm 11 //enA short for right motor
#define Lm  5 //enB short for right motor
#define In1 A0 //right motor backward
#define In2 9 //right motor forward
#define In3 7 //left motor backward
#define In4 6 //left motor forward

#define R_ir 12
#define RR_ir 8
#define L_ir 13
#define LL_ir 4
#define M_ir 2

#define rm 90
#define lm 100

#define rmm 220
#define lmm 220

#define shootingtime 1000

Servo shoot;

int R_sensor;
int L_sensor;
int RR_sensor;
int LL_sensor;
int M_sensor;

int current_time;
int start_time;

int dir = 0;

int r = 0;
int g = 0;
int y = 0;

bool red_shoot = false;
bool green_shoot = false;
bool police_chase = false;

bool left = false;
bool right = false;

bool leftt = false;
bool rightt = false;

char recieve = '\0';

/////////////////////////////////////////////////////////////////////

void setup() {

  //section B

  shoot.attach(10);
  shoot.write(90);

  bluetooth.begin(9600);
  Serial.begin(9600);

  pinMode(Rm, OUTPUT);
  pinMode(Lm, OUTPUT);
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);

  pinMode(R_ir, INPUT);
  pinMode(L_ir, INPUT);
  pinMode(RR_ir, INPUT);
  pinMode(LL_ir, INPUT);
  pinMode(M_ir, INPUT);

  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);
  digitalWrite(In3, LOW);
  digitalWrite(In4, LOW);

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

void loop() {

  //section C

  shoot.write(90);

  current_time = millis();

  R_sensor = digitalRead(R_ir);
  L_sensor = digitalRead(L_ir);
  RR_sensor = digitalRead(RR_ir);
  LL_sensor = digitalRead(LL_ir);
  M_sensor = digitalRead(M_ir);

  //read from serial
  while (Serial.available() )
  {
    recieve = Serial.read();
  }

  ///////////////////////////////////////////////////////////////////////////////////////////////////////

  //section D

  // move forward
  if (R_sensor == 0 && RR_sensor == 0 && L_sensor == 0 && LL_sensor == 0 && police_chase == false)
  {
    move_forward();
  }

  //turn left
  while (RR_sensor == 0 && R_sensor == 0 && L_sensor == 1 && LL_sensor == 0 && police_chase == false)
  {
    turn_left();
  }

  //turn right
  while (RR_sensor == 0 && R_sensor == 1 && L_sensor == 0 && LL_sensor == 0 && police_chase == false)
  {
    turn_right();
  }

  //left branch
  if (RR_sensor == 0 && R_sensor == 0 && L_sensor == 1 && LL_sensor == 1)
  {
    left = true;

    while (left == true)
    {
      left_branch();
    }
  }

  //right branch
  if (RR_sensor == 1 && R_sensor == 1 && L_sensor == 0 && LL_sensor == 0)
  {
    right = true;

    while (right == true)
    {
      right_branch();
    }
  }

  /////////////////////////////////////////////////////////////////////////////////




  //section E


  //red shooting
  if (recieve == 'r')
  {
    r++;
    if (r == 1)
    {
      red_shoot = true;
    }

    while (red_shoot == true)
    {

      red_shooting();
    }
  }


  //green shooting
  if (recieve == 'g')
  {
    g++;
    if (g == 3)
    {
      green_shoot = true;
    }

    while (green_shoot == true)
    {

      green_shooting();
    }
  }



  //remember direction
  if (R_sensor == 1 && L_sensor == 1 && M_sensor == 0 && RR_sensor == 1 && LL_sensor == 1 )
  {
    remember();
  }

  //returning from T branch and turning right
  while (rightt == true)
  {
    return_right();
  }

  //returning from T branch and turning left
  while (leftt == true)
  {
    return_left();
  }

  ////////////////////////////////////////////////////////////////////////////////

  //section F

  if (recieve == 'y')
  {
    y++;
    recieve = '\0';
  }
  if (y == 2) {
    police_chase = true;
  }
  if (y > 10)
  {
    police_chase = false;
  }



  // move forward max
  if (R_sensor == 0 && RR_sensor == 0 && L_sensor == 0 && LL_sensor == 0 && police_chase == true)
  {
    max_forward();
  }

  //turn left max
  while (RR_sensor == 0 && R_sensor == 0 && L_sensor == 1 && LL_sensor == 0 && police_chase == true)
  {
    max_left();
  }

  //turn right max
  while (RR_sensor == 0 && R_sensor == 1 && L_sensor == 0 && LL_sensor == 0 && police_chase == true)
  {
    max_right();
  }

}
