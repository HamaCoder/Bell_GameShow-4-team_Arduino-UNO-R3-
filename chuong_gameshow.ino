/*
 * Nut{1, 2, 3, 4} -> D{2, 3, 4, 5}
 * Reset           -> D8
 * Error           -> D7
 * LED{G, R, B}    -> A{0, 1, 2}
 * 
 * 
 * SD card
 * miso - D12
 * mosi - D11
 * sck  - D13
 * cs   - D10
 * 
 * Loa  - D9
 * 
 * options = 1     -> Bat dau choi      (led off)
 * options = 2     -> Duoc phep bam     (led yellow)
 * options = 3     -> Tro ve mac dinh   (led off)
 * 
 */

#include <SD.h>
#include <TMRpcm.h>
//........
#define nut_1 2
#define nut_2 3
#define nut_3 4
#define nut_4 5
#define RESET 8
#define SetError 7

#define SD_ChipSelectPin 10
TMRpcm SD_export;

 int loi[] = {"T1.wav", "T2.wav", "T3.wav", "T4.wav"};
 int error_music[] = {"F1.wav", "F2.wav", "F3.wav", "F4.wav", "F5.wav", "F6.wav", "F7.wav", "F8.wav", "F9.wav"};
 byte led[] = {A0,A1,A2};
 byte count_led;
 int options;
 int khoa = 0;
 int saibet = 0;
 int saibet1 = 0;
 int analog_1 = analogRead(A0);
 int analog_2 = analogRead(A1);
 int analog_3 = analogRead(A2);
 
void setup() {
  Serial.begin(9600);

  SD_export.speakerPin = 9;

  if(!SD.begin(SD_ChipSelectPin)){
    Serial.println("SD fail");
    return;
  }
  else
    Serial.println("SD ready");

  delay(1000);
  SD_export.setVolume(6);
  SD_export.play("batdau.wav");

  analog_1 = map(analog_1, 0, 1023, 0, 255);
  analog_2 = map(analog_2, 0, 1023, 0, 255);
  analog_3 = map(analog_3, 0, 1023, 0, 255);

  count_led = sizeof(led);
  for(int i=0; i<count_led; i++){
    pinMode(led[i], OUTPUT);
    analogWrite(led[i], 0);
  }

  pinMode(nut_1, INPUT_PULLUP);
  pinMode(nut_2, INPUT_PULLUP);
  pinMode(nut_3, INPUT_PULLUP);
  pinMode(nut_4, INPUT_PULLUP);
  pinMode(RESET, INPUT_PULLUP);
  pinMode(SetError, INPUT_PULLUP);

  khoi_dong(2, 200);
  nhap_nhay(2, 200);

}

void loop() {
  


  if(digitalRead(RESET) == LOW){
    delay(50);
    
    saibet1++;
      if(saibet1==1 || saibet1==3){
//        SD_export.play("batdau.wav");
//        delay(500);
        saibet1++;
      }
      
//    nhap_nhay(3, 200);
    options++;
    khoa++;
    
     if(khoa==2){
       khoa=0;
       options=0;
     }
  }

  int Change_1 = digitalRead(nut_1);
  int Change_2 = digitalRead(nut_2);
  int Change_3 = digitalRead(nut_3);
  int Change_4 = digitalRead(nut_4);

  if(options == 0){
    
    off_led();
    saibet1=0;
      
    while(Change_1 == LOW){
        saibet++;
          if(saibet==1){
            Error();
            saibet++;
          }
          mau_hong_ne(1, 300);
            
      if(digitalRead(RESET)==LOW){
        Suscess();
        break;
      }
    }
    while(Change_2 == LOW){
          saibet++;
          if(saibet==1){
            Error();
            saibet++;
          }
          mau_tim_ne(1, 300);
            
      if(digitalRead(RESET)==LOW){
        Suscess();
        break;
      }
    }
    while(Change_3 == LOW){
          saibet++;
          if(saibet==1){
            Error();
            saibet++;
          }
          mau_xanhla_ne(1, 300);
            
      if(digitalRead(RESET)==LOW){
        Suscess();
        break;
      }
    }
    while(Change_4 == LOW){
          saibet++;
          if(saibet==1){
            Error();
            saibet++;
          }
          mau_cam_ne(1, 300);
            
      if(digitalRead(RESET)==LOW){
        Suscess();
        break;
      }
    }
  } else {
      mau_xanhduong();
  }
  
  if(options == 1){
    
    //...Chuông 1...
    while(Change_1==LOW){
      
      if(options==1){
        SD_export.play(loi[0]);
        delay(1000);
        options++;
      }
      
      if(digitalRead(SetError)==LOW){
        saibet++;
        if(saibet==1){
          Error();
          saibet++;
        }
      }

      if(saibet==2)
        Error_color();
      
      if(digitalRead(RESET)==LOW){
        Suscess();
        break;
      }
      else
        Group_1();
    }
  
    //...Chuông 2...
    while(Change_2==LOW){
      
      if(options==1){
        SD_export.play(loi[1]);
        delay(1000);
        options++;
      }
      
      if(digitalRead(SetError)==LOW){
        saibet++;
        if(saibet==1){
          Error();
          saibet++;
        }
      }

      if(saibet==2)
        Error_color();
      
      if(digitalRead(RESET)==LOW){
        Suscess();
        break;
      }
      else
        Group_2();
    }
  
    //...Chuông 3...
    while(Change_3==LOW){
      
      if(options==1){
        SD_export.play(loi[2]);
        delay(1000);
        options++;
      }
      
      if(digitalRead(SetError)==LOW){
        saibet++;
        if(saibet==1){
          Error();
          saibet++;
        }
      }

      if(saibet==2)
        Error_color();
      
      if(digitalRead(RESET)==LOW){
        Suscess();
        break;
      }
      else
        Group_3();
    }
  
    //...Chuông 4...
    while(Change_4==LOW){
      
      if(options==1){
        SD_export.play(loi[3]);
        delay(1000);
        options++;
      } 
      
      if(digitalRead(SetError)==LOW){
        saibet++;
        if(saibet==1){
          Error();
          saibet++;
        }
      }

      if(saibet==2)
        Error_color();
      
      if(digitalRead(RESET)==LOW){
        Suscess();
        break;
      }
      else
        Group_4();
    }
  }
}

void khoi_dong(int k,unsigned int toc_do){
  for(k=0; k<=sizeof(k); k++){
    for(int i=0; i<count_led; i++){
      analogWrite(led[i], 255);
      delay(toc_do);
    }
    
    for(int i=0; i<count_led; i+=1){
      analogWrite(led[i], 0);
      delay(toc_do);
    }
  }
}

void nhap_nhay(int i,unsigned int toc_do){
  for(i=0; i<=sizeof(i); i++){
    mau_hong();
    delay(toc_do);
    mau_xanhla();
    delay(toc_do);
    mau_tim();
    delay(toc_do);
    mau_cam();
    delay(toc_do);
  }
}

void mau_hong_ne(int i, unsigned int toc_do){
  for(i=0; i<=sizeof(i); i++){
    mau_hong();
    delay(toc_do);
    off_led();
    delay(toc_do);
  }
}

void mau_tim_ne(int i, unsigned int toc_do){
  for(i=0; i<=sizeof(i); i++){
    mau_tim();
    delay(toc_do);
    off_led();
    delay(toc_do);
  }
}

void mau_xanhla_ne(int i, unsigned int toc_do){
  for(i=0; i<=sizeof(i); i++){
    mau_xanhla();
    delay(toc_do);
    off_led();
    delay(toc_do);
  }
}

void mau_cam_ne(int i, unsigned int toc_do){
  for(i=0; i<=sizeof(i); i++){
    mau_cam();
    delay(toc_do);
    off_led();
    delay(toc_do);
  }
}

void mac_dinh(){
  for(int i=0; i<count_led; i++){
    analogWrite(led[i], 0);
  }
}

void reset_board(){
  asm volatile ( "jmp 0"); 
}

void Group_1(){ 
  mau_hong();
}
void Group_2(){
  mau_tim();
}

void Group_3(){
  mau_xanhla();
}

void Group_4(){
  mau_cam();
}

void off_led(){
  analogWrite(led[0], 0);
  analogWrite(led[1], 0);
  analogWrite(led[2], 0);
}

void mau_xanhla(){
  analogWrite(led[0], 0);
  analogWrite(led[1], 255);
  analogWrite(led[2], 0);
}

void mau_hong(){
  analogWrite(led[0], 255);
  analogWrite(led[1], 0);
  analogWrite(led[2], 0);
}

void mau_cam(){
  analogWrite(led[0], 255);
  analogWrite(led[1], 255);
  analogWrite(led[2], 0);
}

void mau_tim(){
  analogWrite(led[0], 255);
  analogWrite(led[1], 255);
  analogWrite(led[2], 255);
}

void mau_vang(){
  analogWrite(led[0], 255);
  analogWrite(led[1], 255);
  analogWrite(led[2], 0);
}

void mau_xanhduong(){
  analogWrite(led[0], 0);
  analogWrite(led[1], 0);
  analogWrite(led[2], 255);
}
void Suscess(){
  SD_export.play("batdau.wav");
  options = 0;
  saibet = 0;
  saibet1 = 0;
  mac_dinh();
}

void Error(){
  int henxuoi = random(9);
  SD_export.play(error_music[henxuoi]);
}

void Error_color(){
  analogWrite(led[0], 255);
  analogWrite(led[1], 0);
  analogWrite(led[2], 0);
  delay(500);
  off_led();
  delay(500);
}
