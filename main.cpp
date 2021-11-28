#include<Arduino.h>

unsigned long previousMillis = 0;
unsigned long previousMillisIR1 = 0;  
unsigned long previousMillisIR2 = 0;  
unsigned long previousMillisIR3 = 0;       
const long sec = 1000;
const long IR_time = 3000;   
const int green_time = 10;

int flag1 = 0;
int flag_inc1 = 0;

int flag2 = 0;
int flag_inc2 = 0;

int flag3 = 0;
int flag_inc3 = 0;

const int IR1 = 7;
const int IR2 = 6;
const int IR3 = 5;

const int LEDG1 = 12;
const int LEDR1 = 13;   

const int LEDG2 = 10;
const int LEDR2 = 11;   

const int LEDG3 = 8;
const int LEDR3 = 9;   


int red1=0;
int red1_temp=0;
int green1=10;

int red2=0;
int red2_temp=0;
int green2=0;

int red3=0;
int red3_temp=0;
int green3=0;

void setup() {

  Serial.begin(9600);
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  pinMode(LEDG1, OUTPUT);
  pinMode(LEDR1, OUTPUT);
  pinMode(LEDG2, OUTPUT);
  pinMode(LEDR2, OUTPUT);
  pinMode(LEDG3, OUTPUT);
  pinMode(LEDR3, OUTPUT);
}

void loop() {

    unsigned long currentMillis = millis();
    int IRstatus1 = digitalRead(IR1);
    int IRstatus2 = digitalRead(IR2);
    int IRstatus3 = digitalRead(IR2);
    
    //Checking IR 1
    if(IRstatus1 == 0 && green1 != 0){
      if(flag1 == 0){
        Serial.println("Current time save of IR 1");
        previousMillisIR1 = currentMillis;
        flag1 = 1;
      }
      if((previousMillisIR1 + IR_time) <= currentMillis){
        if(flag_inc1 == 0){
          green1= green1 + 3;
          Serial.println("Green 1 Increment");
          flag_inc1 = 1;
          flag1 = 0;
        }
      }
      else
        flag_inc1 = 0;
    }
    else
      flag1 = 0;

    //Checking IR 2
    if(IRstatus2 == 0 && green2 != 0){
      if(flag2 == 0){
        Serial.println("Current time save of IR 2");
        previousMillisIR2 = currentMillis;
        flag2 = 1;
      }
      if((previousMillisIR2 + IR_time) <= currentMillis){
        if(flag_inc2 == 0){
          green2= green2 + 3;
          Serial.println("Green 2 Increment");
          flag_inc2 = 1;
          flag2 = 0;
        }
      }
      else
        flag_inc2 = 0;
    }
    else
      flag2 = 0;

    // Checking IR 3
    if(IRstatus3 == 0 && green3 != 0){
      if(flag3 == 0){
        Serial.println("Current time save of IR 3");
        previousMillisIR3 = currentMillis;
        flag3 = 1;
      }
      if((previousMillisIR3 + IR_time) <= currentMillis){
        if(flag_inc3 == 0){
          green3= green3 + 3;
          Serial.println("Green 3 Increment");
          flag_inc3 = 1;
          flag3 = 0;
        }
      }
      else
        flag_inc3 = 0;
    }
    else
      flag3 = 0;


    if (currentMillis - previousMillis >= sec) {
      previousMillis = currentMillis;

      if(green1>0){
          digitalWrite(LEDG1,HIGH);
          digitalWrite(LEDG2,LOW);
          digitalWrite(LEDG3,LOW);

          digitalWrite(LEDR1,LOW);
          digitalWrite(LEDR2,HIGH);
          digitalWrite(LEDR3,HIGH);

          --green1;
          ++red1_temp;
          Serial.print("Green 1 = ");
          Serial.println(green1);
          if(green1==0){
              red1 = red1_temp;
              green2 = green_time;
          }
      }
      if(green2>0){
          digitalWrite(LEDG1,LOW);
          digitalWrite(LEDG2,HIGH);
          digitalWrite(LEDG3,LOW);

          digitalWrite(LEDR1,HIGH);
          digitalWrite(LEDR2,LOW);
          digitalWrite(LEDR3,HIGH);

          --green2;
          Serial.print("Green 2 = ");
          Serial.println(green2);
          ++red2_temp;
          if(green2==0){
              red2 = red2_temp;
              green3 = green_time;
          }
      }
      if(green3>0){
          digitalWrite(LEDG1,LOW);
          digitalWrite(LEDG2,LOW);
          digitalWrite(LEDG3,HIGH);

          digitalWrite(LEDR1,HIGH);
          digitalWrite(LEDR2,HIGH);
          digitalWrite(LEDR3,LOW);

          --green3;
          ++red3_temp;
          Serial.print("Green 3 = ");
          Serial.println(green3);
          if(green3==0){
              red3 = red3_temp;
              green1 = green_time;
          }
      }
      
      // if(red1>0){
      // digitalWrite(LEDR1,HIGH);
      // digitalWrite(LEDR2,LOW);
      // digitalWrite(LEDR3,HIGH);
      // --red1;
      // }
      // if(red2>0){
      //   digitalWrite(LEDR1,HIGH);
      //   digitalWrite(LEDR2,HIGH);
      //   digitalWrite(LEDR3,LOW);
      //   --red2;
      // }
      // if(red3>0){
      //   digitalWrite(LEDR1,LOW);
      //   digitalWrite(LEDR2,HIGH);
      //   digitalWrite(LEDR3,HIGH);
      //   --red3;
      // }
  }
}
