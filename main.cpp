#include<Arduino.h>

unsigned long previousMillis = 0;       
const long interval = 1000;   

const int LEDG1 = 12;
const int LEDR1 = 13;   

const int LEDG2 = 10;
const int LEDR2 = 11;   

const int LEDG3 = 8;
const int LEDR3 = 9;   

int red1=0;
int green1=6;

int red2=0;
int green2=0;

int red3=0;
int green3=0;

void setup() {

  pinMode(LEDG1, OUTPUT);
  pinMode(LEDR1, OUTPUT);
  pinMode(LEDG2, OUTPUT);
  pinMode(LEDR2, OUTPUT);
  pinMode(LEDG3, OUTPUT);
  pinMode(LEDR3, OUTPUT);
}

void loop() {

    unsigned long currentMillis = millis();
	
	
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;

      if(green1>0){
          digitalWrite(LEDG1,HIGH);
          digitalWrite(LEDG2,LOW);
          digitalWrite(LEDG3,LOW);

          digitalWrite(LEDR1,LOW);
          digitalWrite(LEDR2,HIGH);
          digitalWrite(LEDR3,HIGH);
          --green1;
          if(green1==0){
              red1 = 12;
              green2 = 6;
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
          if(green2==0){
              red2 = 12;
              green3 = 6;
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
          if(green3==0){
              red3 = 12;
              green1 = 6;
          }
      }
      
    //   if(red1>0){
    //   digitalWrite(LEDR1,HIGH);
    //   digitalWrite(LEDR2,LOW);
    //   digitalWrite(LEDR3,HIGH);
    //   --red1;
    //   }
    //   if(red2>0){
    //     digitalWrite(LEDR1,HIGH);
    //     digitalWrite(LEDR2,HIGH);
    //     digitalWrite(LEDR3,LOW);
    //     --red2;
    //   }
    //   if(red3>0){
    //     digitalWrite(LEDR1,LOW);
    //     digitalWrite(LEDR2,HIGH);
    //     digitalWrite(LEDR3,HIGH);
    //     --red3;
    //   }



  }
}
