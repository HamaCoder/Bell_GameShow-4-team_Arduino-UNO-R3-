/*
 * nút_(1..4)    -->>    D(2..5)
 * led_(1..4)    -->>    D(6..9)
 * chuông        -->>    D12
 * 
 */

#define btn_1 2
#define btn_2 3
#define btn_3 4
#define btn_4 5

#define LED_1 6
#define LED_2 7
#define LED_3 8
#define LED_4 9

#define BELL 12

void setup() {
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
  pinMode(BELL,  OUTPUT);

  pinMode(btn_1, INPUT_PULLUP);
  pinMode(btn_2, INPUT_PULLUP);
  pinMode(btn_3, INPUT_PULLUP);
  pinMode(btn_4, INPUT_PULLUP);

}

void loop() {
  Start();
  
  while(digitalRead(btn_1)==0){
    Team_1(5000);
  }

  while(digitalRead(btn_2)==0){
    Team_2(5000);
  }

  while(digitalRead(btn_3)==0){
    Team_3(5000);
  }

  while(digitalRead(btn_4)==0){
    Team_4(5000);
  }

}


void Start(){
  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, LOW);
  digitalWrite(LED_3, LOW);
  digitalWrite(LED_4, LOW);
}

void Team_1(int Time){
  digitalWrite(LED_1, HIGH);
  digitalWrite(BELL, HIGH);
  delay(Time);
}

void Team_2(int Time){
  digitalWrite(LED_2, HIGH);
  digitalWrite(BELL, HIGH);
  delay(Time);
}

void Team_3(int Time){
  digitalWrite(LED_3, HIGH);
  digitalWrite(BELL, HIGH);
  delay(Time);
}

void Team_4(int Time){
  digitalWrite(LED_4, HIGH);
  digitalWrite(BELL, HIGH);
  delay(Time);
}
