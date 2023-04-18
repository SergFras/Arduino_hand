#include <Servo.h>

#define led 8
#define pinHumb 6
#define pinU 4
#define pinHumbV 2
#define pinLast 3
#define pinSred 5

Servo humb;
Servo uk;
Servo humbV;
Servo last;
Servo sred;

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(12, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);

  Serial.begin(115200);
  humb.attach(pinHumb);
  uk.attach(pinU);
  humbV.attach(pinHumbV);
  last.attach(pinLast);
  sred.attach(pinSred);

  nul();
  delay(3000);
}

void kul(){
  humb.write(0); // Машинка на большой
  uk.write(180); // Средний
  humbV.write(0); // Указательный
  last.write(180); // Последние 
  sred.write(0); // Большой
  }

void nul(){
  humb.write(100); // Машинка на большой
  uk.write(0); // Cредний
  humbV.write(180); // Указательный
  last.write(0); // Последние 
  sred.write(180); // Большой
  }

void ok(){
  humb.write(60); // Машинка на большой
  uk.write(0); // Средний
  humbV.write(0); // Указательный
  last.write(0); // Последние 
  sred.write(0); // Большой
  }

void victory(){
  humb.write(20); // Машинка на большой
  uk.write(0); // Средний
  humbV.write(180); // Указательный
  last.write(180); // Последние 
  sred.write(0); // Большой
  }

void f(){
  uk.write(0); // Большой
  humbV.write(0); // Указательный
  last.write(180); // Последние 
  sred.write(0); // 
  }

int data[7];
int i_data = 0;
int sum = 0;

void loop() {
  //int vall = 0;
  //int value = analogRead(0);
  //Serial.println(value);
  int vall = map(analogRead(1), 0, 1023,0,180);
  //Serial.println(vall);
  
  int btn1 = digitalRead(12);
  int btn2 = digitalRead(11);
  int btn3 = digitalRead(9);
  int btn4 = digitalRead(8  );
  int btn5 = digitalRead(10);

  if ((btn1 && btn2 && btn3 && btn4 && btn5 && false)){
    int n = 10;
    int value = analogRead(0);
    //Serial.println(value);
    
    data[i_data] = value;
    if(i_data <= n){
      sum += value;
      i_data++;
  
      if(i_data == n){
        Serial.println(sum/i_data);
      //Serial.println(sum);
    }
  
    if(i_data == n){
      if(sum/i_data > vall)
         kul();
      else
         nul();
    }
    }
    else{
      sum = 0;
      i_data = 0;
    }
    
    delay(100);
  }
  else{
      if(btn1 == 0) nul();
      if(btn2 == 0) kul();
      if(btn3 == 0) ok();
      if(btn4 == 0) victory();
      if(btn5 == 0) f();
    }
}
