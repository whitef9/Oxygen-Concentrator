#define debug 1

#define Button 13
#define Pump 12
#define Solenoid_1 11
#define Solenoid_2 10
#define Solenoid_3 9
#define Solenoid_4 8
#define Solenoid_5 7
#define Solenoid_6 6
#define Solenoid_7 5

int on_off = 0;
int button_depressed = 0;
int current_sol_config = 1;
unsigned long current_sol_config_start_millis = 0;
void sol_config_1();
void sol_config_2();
void sol_config_3();
void sol_config_4();
void sol_config_5();
void sol_config_6();
void sol_config_7();



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Button,INPUT);
  pinMode(Pump,OUTPUT);
  pinMode(Solenoid_1,OUTPUT);
  pinMode(Solenoid_2,OUTPUT);
  pinMode(Solenoid_3,OUTPUT);
  pinMode(Solenoid_4,OUTPUT);
  pinMode(Solenoid_5,OUTPUT);
  pinMode(Solenoid_6,OUTPUT);
  pinMode(Solenoid_7,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (!digitalRead(Button) and !button_depressed)
  {
    if (debug)
    {
      Serial.println("Button Pressed"); 
    }
    
    button_depressed = 1;
    if (!on_off)
    {
      on_off = 1;
      sol_config_7();
      current_sol_config = 1;
      current_sol_config_start_millis = millis();
      digitalWrite(Pump, HIGH);
      
    }
    else
    {
      on_off = 0;
      digitalWrite(Pump,LOW);
      sol_config_8();
      delay(100);
      sol_config_1();
    }
    
  }
  else if (digitalRead(Button))
  {
    button_depressed = 0;
  }


  if (on_off)
  {
     if (current_sol_config == 1)
     {
        if (millis() - current_sol_config_start_millis > 2000)
        {
          if (debug)
          {
            Serial.println("1 Transition");
          }
          sol_config_2();
          current_sol_config = 2;
          current_sol_config_start_millis = millis();
          digitalWrite(Pump,HIGH);
        }        
     }
     else if (current_sol_config == 2)
     {
        if (millis() - current_sol_config_start_millis > 2000)
        {
          if (debug)
          {
            Serial.println("2 Transition");
          }
          sol_config_3();
          current_sol_config = -3;
          current_sol_config_start_millis = millis();
        }
     }
     else if (current_sol_config == -3)
     {
        if (millis() - current_sol_config_start_millis > 2000)
        {
          if (debug)
          {
            Serial.println("-3 Transition");
          }
          sol_config_1();
          digitalWrite(Pump,LOW);
          delay(10);
          current_sol_config = 3;
          current_sol_config_start_millis = millis();
        }
     }
     else if (current_sol_config == 3)
     {
        if (millis() - current_sol_config_start_millis > 2000)
        {
          if (debug)
          {
            Serial.println("3 Transition");
          }
          sol_config_4();
          current_sol_config = 4;
          current_sol_config_start_millis = millis();
          digitalWrite(Pump,HIGH);
        }
     }
     else if (current_sol_config == 4)
     {
        if (millis() - current_sol_config_start_millis > 2000)
        {
          if (debug)
          {
            Serial.println("4 Transition");
          }
          sol_config_5();
          current_sol_config = 5;
          current_sol_config_start_millis = millis();
        }
     }
     else if (current_sol_config == 5)
     {
        if (millis() - current_sol_config_start_millis > 2000)
        {
          if (debug)
          {
            Serial.println("5 Transition");
          }
          sol_config_6();
          current_sol_config = -6;
          current_sol_config_start_millis = millis();
        }
     }
     else if (current_sol_config == -6)
     {
        if (millis() - current_sol_config_start_millis > 2000)
        {
          if (debug)
          {
            Serial.println("-6 Transition");
          }
          sol_config_1();
          digitalWrite(Pump,LOW);
          delay(10);
          current_sol_config = 6;
          current_sol_config_start_millis = millis();
        }
     }
     else if (current_sol_config == 6)
     {
        if (millis() - current_sol_config_start_millis > 2000)
        {
          if (debug)
          {
            Serial.println("6 Transition");
          }
          sol_config_7();
          current_sol_config = 1;
          current_sol_config_start_millis = millis();
          digitalWrite(Pump, HIGH);
        }
     }
  }
  
    
}



void sol_config_1()
{
  digitalWrite(Solenoid_1,LOW);
  digitalWrite(Solenoid_2,LOW);
  digitalWrite(Solenoid_3,LOW);
  digitalWrite(Solenoid_4,LOW);
  digitalWrite(Solenoid_5,LOW);
  digitalWrite(Solenoid_6,LOW);
  digitalWrite(Solenoid_7,LOW);
}

void sol_config_2()
{
  digitalWrite(Solenoid_1,LOW);
  digitalWrite(Solenoid_2,HIGH);
  digitalWrite(Solenoid_3,HIGH);
  digitalWrite(Solenoid_4,LOW);
  digitalWrite(Solenoid_5,HIGH);
  digitalWrite(Solenoid_6,HIGH);
  digitalWrite(Solenoid_7,LOW);
}

void sol_config_3()
{
  digitalWrite(Solenoid_1,LOW);
  digitalWrite(Solenoid_2,LOW);
  digitalWrite(Solenoid_3,LOW);
  digitalWrite(Solenoid_4,LOW);
  digitalWrite(Solenoid_5,LOW);
  digitalWrite(Solenoid_6,HIGH);
  digitalWrite(Solenoid_7,LOW);
}

void sol_config_4()
{
  digitalWrite(Solenoid_1,HIGH);
  digitalWrite(Solenoid_2,HIGH);
  digitalWrite(Solenoid_3,LOW);
  digitalWrite(Solenoid_4,LOW);
  digitalWrite(Solenoid_5,LOW);
  digitalWrite(Solenoid_6,LOW);
  digitalWrite(Solenoid_7,HIGH);
}

void sol_config_5()
{
  digitalWrite(Solenoid_1,LOW);
  digitalWrite(Solenoid_2,HIGH);
  digitalWrite(Solenoid_3,HIGH);
  digitalWrite(Solenoid_4,HIGH);
  digitalWrite(Solenoid_5,LOW);
  digitalWrite(Solenoid_6,LOW);
  digitalWrite(Solenoid_7,HIGH);
}

void sol_config_6()
{
  digitalWrite(Solenoid_1,LOW);
  digitalWrite(Solenoid_2,LOW);
  digitalWrite(Solenoid_3,LOW);
  digitalWrite(Solenoid_4,LOW);
  digitalWrite(Solenoid_5,LOW);
  digitalWrite(Solenoid_6,LOW);
  digitalWrite(Solenoid_7,HIGH);
}

void sol_config_7()
{
  digitalWrite(Solenoid_1,HIGH);
  digitalWrite(Solenoid_2,LOW);
  digitalWrite(Solenoid_3,HIGH);
  digitalWrite(Solenoid_4,LOW);
  digitalWrite(Solenoid_5,LOW);
  digitalWrite(Solenoid_6,HIGH);
  digitalWrite(Solenoid_7,LOW);
}

void sol_config_8()
{
  digitalWrite(Solenoid_1,HIGH);
  digitalWrite(Solenoid_2,HIGH);
  digitalWrite(Solenoid_3,HIGH);
  digitalWrite(Solenoid_4,HIGH);
  digitalWrite(Solenoid_5,HIGH);
  digitalWrite(Solenoid_6,HIGH);
  digitalWrite(Solenoid_7,HIGH);
}
