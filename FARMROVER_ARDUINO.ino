//farm rover
//ARDUINO

//#include <Arduino.h>

//#include <avr/wdt.h> //reset arduino

//#include <EEPROM.h>// EEPROM pre-installed library

#include <AFMotor.h>
//int pwm;
char direction;

const int ARRAY_SIZE = 200;
// Define the array to store values associated with functions
int functionValues[ARRAY_SIZE];
int currentIndex = 0;


AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);





void setup() {
  Serial.begin(115200);
  motor1.setSpeed(255);
  motor1.run(RELEASE);
  motor2.setSpeed(255);
  motor2.run(RELEASE);
  motor3.setSpeed(255);
  motor3.run(RELEASE);
  motor4.setSpeed(255);
  motor4.run(RELEASE);
  Serial.print("\nMotor works");
}

void loop() {
  //delay(100);

  int arrayLength = sizeof(functionValues) / sizeof(functionValues[0]);
  if (Serial.available() > 0) { 
    direction = Serial.read(); 
    Serial.print(direction);
    switch (direction) {
      case '0':  
        //brake();
        brake();
        Serial.print("STOP");
        functionValues[currentIndex++] = 0;
        break;
      case '1':  
        forward();
        Serial.print("FORWARD");
        functionValues[currentIndex++] = 1;
        break;
      case '2':  
        backward();
        Serial.print("BACK");
        functionValues[currentIndex++] = 2;
        break;
      case '3':  
        left();
        Serial.print("LEFT");
        functionValues[currentIndex++] = 3;
        break;
      case '4':
        right();
        Serial.print("RIGHT");
        functionValues[currentIndex++] = 4;
        break;
      case '5':
        Serial.print("anticlockwise");
        anticlockw();
        functionValues[currentIndex++] = 5;
        break;
      case '6':
        Serial.print("clockwise");
        clockw();
        functionValues[currentIndex++] = 6;
        break;
      case '7':
        Serial.print("repeat path");
        /*
        Serial.write('A'); // For example, 'A' to indicate array data follows
        // Send array data
        for (int i = 0; i < arrayLength; i++) {
          Serial.write((byte*)&functionValues[i], sizeof(functionValues[i]));
        }*/
        for (int i = 0; i < currentIndex; i++) {
          //delay(100);
          Serial.write(functionValues[i]);
          Serial.print(" ");
        }
        for (int i = 0; i < currentIndex; i++) {
          switch (functionValues[i]) {
            case 0:  
              //brake();
              brake();
              //Serial.print("STOP");
              //functionValues[currentIndex++] = 0;
              break;
            case 1:  
              forward();
              //Serial.print("FORWARD");
              //functionValues[currentIndex++] = 1;
              break;
            case 2:  
              backward();
              //Serial.print("BACK");
              //functionValues[currentIndex++] = 2;
              break;
            case 3:  
              left();
              //Serial.print("LEFT");
              //functionValues[currentIndex++] = 3;
              break;
            case 4:
              right();
              //Serial.print("RIGHT");
              //functionValues[currentIndex++] = 4;
              break;
            case 5:
              //Serial.print("anticlockwise");
              anticlockw();
              //functionValues[currentIndex++] = 5;
              break;
            case 6:
              //Serial.print("clockwise");
              clockw();
              //functionValues[currentIndex++] = 6; 
          }
        }
        break;
      case '8':
        Serial.print("reset path");
        for (int i = 0; i < ARRAY_SIZE; i++) {
          functionValues[i] = 0;
        }
        // Reset currentIndex to 0
        currentIndex = 0;
        for (int i = 0; i < currentIndex; i++) {
          Serial.print(functionValues[i]);
          Serial.print(" ");
        }
        Serial.println();
        break;
    }
  } 
}


void brake()
{
  Serial.print("\nBRAKE");
  motor1.run(RELEASE);
  motor2.run(RELEASE);  
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}


void forward()
{      
  Serial.print("\nFORWARD");
  
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);

  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);

  delay(750);
  Serial.print("\nBRAKE");
  motor1.run(RELEASE);
  motor2.run(RELEASE);  
  motor3.run(RELEASE);
  motor4.run(RELEASE);

}

void backward()
{      
  Serial.print("\nBACKWARD");
  
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);

  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);

  
  delay(750);
  Serial.print("\nBRAKE");
  motor1.run(RELEASE);
  motor2.run(RELEASE);  
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}


void left()
{      
  Serial.print("\nLEFT");
  
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);

  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);

  
  delay(750);
  Serial.print("\nBRAKE");
  motor1.run(RELEASE);
  motor2.run(RELEASE);  
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}


void right()
{      
  Serial.print("\nRIGHT");
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);

  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);

  
  delay(750);
  Serial.print("\nBRAKE");
  motor1.run(RELEASE);
  motor2.run(RELEASE);  
  motor3.run(RELEASE);
  motor4.run(RELEASE);
} 



void clockw()
{      
  Serial.print("\nCLOCKWISE");
  
  motor1.setSpeed(155);
  motor2.setSpeed(155);
  motor3.setSpeed(155);
  motor4.setSpeed(155);

  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  
  delay(800);
  Serial.print("\nBRAKE");
  motor1.run(RELEASE);
  motor2.run(RELEASE);  
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void anticlockw()
{     
  Serial.print("\nANTICLOCKWISE");
  
  motor1.setSpeed(155);
  motor2.setSpeed(155);
  motor3.setSpeed(155);
  motor4.setSpeed(155);

  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  
  delay(800);
  Serial.print("\nBRAKE");
  motor1.run(RELEASE);
  motor2.run(RELEASE);  
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
/*
void resetArduino() {
  wdt_enable(WDTO_15MS); // Enable watchdog timer with 15ms timeout
  while (1) {} // Wait for the watchdog timer to trigger a reset
}
*/

/*
void go_Forward() {
  
  movement_Inst_Fwd();

  current_Time0 = millis();
  int i = seq_Array[(seq - 1)];
  switch (i) {
    case 2:
      total_Lft_Time[lft_Counter + 1] = (current_Time0 - current_Time1);
      lft_Counter++;
      break;

    case 3:
      total_Rgt_Time[rgt_Counter + 1] = (current_Time0 - current_Time2);
      rgt_Counter++;
      break;

    case 4:
      total_Bwd_Time[bwd_Counter + 1] = (current_Time0 - current_Time3);
      bwd_Counter++;
      break;

    case 5:
      total_Stp_Time[stp_Counter + 1] = (current_Time0 - current_Time4);
      stp_Counter++;
      break;
  }

  seq_Array[seq] = 1;
  seq++;
}

void go_Left() {

  movement_Inst_Lft();

  current_Time1 = millis();
  int i = seq_Array[(seq - 1)];
  switch (i) {
    case 1:
      total_Fwd_Time[fwd_Counter + 1] = (current_Time1 - current_Time0);
      fwd_Counter++;
      break;

    case 3:
      total_Rgt_Time[rgt_Counter + 1] = (current_Time1 - current_Time2);
      rgt_Counter++;
      break;

    case 4:
      total_Bwd_Time[bwd_Counter + 1] = (current_Time1 - current_Time3);
      bwd_Counter++;
      break;

    case 5:
      total_Stp_Time[stp_Counter + 1] = (current_Time1 - current_Time4);
      stp_Counter++;
      break;
  }

  seq_Array[seq] = 2;
  seq++;
}

void go_Right() {

  movement_Inst_Rgt();

  current_Time2 = millis();
  int i = seq_Array[(seq - 1)];
  switch (i) {
    case 1:
      total_Fwd_Time[fwd_Counter + 1] = (current_Time2 - current_Time0);
      fwd_Counter++;
      break;

    case 2:
      total_Lft_Time[lft_Counter + 1] = (current_Time2 - current_Time1);
      lft_Counter++;
      break;

    case 4:
      total_Bwd_Time[bwd_Counter + 1] = (current_Time2 - current_Time3);
      bwd_Counter++;
      break;

    case 5:
      total_Stp_Time[stp_Counter + 1] = (current_Time2 - current_Time4);
      stp_Counter++;
      break;
  }

  seq_Array[seq] = 3;
  seq++;
}

void go_Backward() {
  
  movement_Inst_Bwd();

  current_Time3 = millis();
  int i = seq_Array[(seq - 1)];
  switch (i) {
    case 1:
      total_Fwd_Time[fwd_Counter + 1] = (current_Time3 - current_Time0);
      fwd_Counter++;
      break;

    case 2:
      total_Lft_Time[lft_Counter + 1] = (current_Time3 - current_Time1);
      lft_Counter++;
      break;

    case 3:
      total_Rgt_Time[rgt_Counter + 1] = (current_Time3 - current_Time2);
      rgt_Counter++;
      break;

    case 5:
      total_Stp_Time[stp_Counter + 1] = (current_Time3 - current_Time4);
      stp_Counter++;
      break;
  }

  seq_Array[seq] = 4;
  seq++;
}

void go_Stop() {

  movement_Inst_Stp();

  current_Time4 = millis();
  int i = seq_Array[(seq - 1)];
  switch (i) {
    case 1:
      total_Fwd_Time[fwd_Counter + 1] = (current_Time4 - current_Time0);
      fwd_Counter++;
      break;

    case 2:
      total_Lft_Time[lft_Counter + 1] = (current_Time4 - current_Time1);
      lft_Counter++;
      break;

    case 3:
      total_Rgt_Time[rgt_Counter + 1] = (current_Time4 - current_Time2);
      rgt_Counter++;
      break;

    case 4:
      total_Bwd_Time[bwd_Counter + 1] = (current_Time4 - current_Time3);
      bwd_Counter++;
      break;
  }

  seq_Array[seq] = 5;
  seq++;
}

void go_In_Seq(void) {
  value = 0;
  for (int i = 0; i < (seq + 1); i++) {
    int value1 = 0;
    value1 = seq_Array[i];
    switch (value1) {
      case 1:
        static int j = 0;
        go_Forward_Seq(j);
        j++;
        break;
      case 2:
        static int k = 0;
        go_Left_Seq(k);
        k++;
        break;
      case 3:
        static int l = 0;
        go_Right_Seq(l);
        l++;
        break;
      case 4:
        static int m = 0;
        go_Backward_Seq(m);
        m++;
        break;
      case 5:
        static int n = 0;
        go_Stop_Seq(n);
        n++;
        break;
      default:
        j = 0; k = 0; l = 0; m = 0; n = 0;
    }
  }
  go_Stop();
}

/*
void del_From_Local_Mem() {
  //set the movement counters to their default values
  fwd_Counter = -1;
  lft_Counter = -1;
  rgt_Counter = -1;
  bwd_Counter = - 1;
  stp_Counter = - 1;

  //set the total movement time to its default value
  for (int i = 0; i < 10; i++) {
    total_Fwd_Time[i] = 0;
    total_Lft_Time[i] = 0;
    total_Rgt_Time[i] = 0;
    total_Bwd_Time[i] = 0;
    total_Stp_Time[i] = 0;
  }

  // Reset the sequence array(stored movement instructions)
  for (int i = 0; i < 50; i++) {
    seq_Array[i] = 0;
  }

  seq = 0;
  value = 0;
}


void write_To_Permt_Mem(){
  // total number of movement is stored in a random address i.e, 100
  EEPROM.write(100,seq);
    
  //writing the movement sequence
  for(int i=0; i<seq; i++){ 
  EEPROM.write(2*i,seq_Array[i]);
  }

  //storing the time bw two successive movements
  for(int i=1; i<seq+1; i++){           
  if(seq_Array[i-1]==1){
    static byte a=0;
    EEPROM.write(2*i-1,(total_Fwd_Time[a])/1000);// Note: One location can store maximum value of 255, hence the time is divided by 1000 here. And then multiplied by 1000 while retreiving the data from EEPROM location
    a++;
    }
  else if(seq_Array[i-1]==2){
    static byte b=0;
    EEPROM.write(2*i-1,(total_Lft_Time[b])/1000);
    b++;
    }
  else if(seq_Array[i-1]==3){
    static byte c=0;
    EEPROM.write(2*i-1,(total_Rgt_Time[c])/1000);
    c++;
    }
  else if(seq_Array[i-1]==4){
    static byte d=0;
    EEPROM.write(2*i-1,(total_Bwd_Time[d])/1000);  
    d++;
    }
  else if(seq_Array[i-1]==5){
    static byte e=0;
    EEPROM.write(2*i-1,(total_Stp_Time[e])/1000);  
    e++;
    }             
  }
 } 
*/
 
/**********************************************************************************************************
     This function reads the stored sequence from the EEPROM(permanent memory)
************************************************************************************************************/
/*
void Read_Permt_Mem(){
  // Read from permanent memory
   byte x = EEPROM.read(100);
   for(int i=0; i<x+1; i++){
    byte r = EEPROM.read(2*i);
    switch(r){
      case 1:
        movement_Inst_Fwd();
        break;
      case 2:
        movement_Inst_Lft();
        break;
      case 3:
        movement_Inst_Rgt();
        break;
      case 4:
        movement_Inst_Bwd();
        break; 
      case 5:
        movement_Inst_Stp();
        break;                          
      }
     delay((EEPROM.read(i+1))*1000);    // multiplied by thousand because the original time was divided by 1000 while storing in EEPROM.
    }
  }
 
 */
/**********************************************************************************************************
     These function moves the car in a direction for the time specified/stored in the total_x_time array
************************************************************************************************************/
/*
void go_Forward_Seq(int j) {
  //go in forward direction sequence
  movement_Inst_Fwd();//
  delay(total_Fwd_Time[j]);
}

void go_Left_Seq(int k) {
  //go in Left direction sequence
  movement_Inst_Lft();
  delay(total_Lft_Time[k]);
}

void go_Right_Seq(int l) {
  //go in right direction sequence
  movement_Inst_Rgt();
  delay(total_Rgt_Time[l]);
}

void go_Backward_Seq(int m) {
  //go in backward direction sequence
  movement_Inst_Bwd();
  delay(total_Bwd_Time[m]);
}

void go_Stop_Seq(int n) {
  //go in Stop sequence
  movement_Inst_Stp();
  delay(total_Stp_Time[n]);
}

// * These movement instruction are repeated several times in the code
 
void movement_Inst_Fwd(void){
  Serial.println("Going_Forward");
  
  // forward movement instructions
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD); 
  delay(500);
} 
  
void movement_Inst_Lft(void){
  Serial.println("Going_Left");
  
  // Left movement instructions
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  delay(500);
  }
  
void movement_Inst_Rgt(void){
  Serial.println("Going_Right");  
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  delay(500);
    
  }
  
void movement_Inst_Bwd(void){
  Serial.println("Going_Backward"); 
    
  // Bwd movement instructions
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  delay(500);
  }
  
void movement_Inst_Stp(void){  
  Serial.println("Stopping");    
  
  // Stp movement instructions
  motor1.run(RELEASE);
  motor2.run(RELEASE);  
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  delay(500);
  }
  




void brake()
{
  Serial.print("\nBRAKE");
  motor1.run(RELEASE);
  motor2.run(RELEASE);  
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}


void forward()
{      
  Serial.print("\nFORWARD");
  
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);

  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void backward()
{      
  Serial.print("\nBACKWARD");
  
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);

  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}


void left()
{      
  Serial.print("\nLEFT");
  
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);

  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
}


void right()
{      
  Serial.print("\nRIGHT");
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);

  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
} 



void clockw()
{      
  Serial.print("\nCLOCKWISE");
  
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);

  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void anticlockw()
{     
  Serial.print("\nANTICLOCKWISE");
  
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);

  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}
*/

