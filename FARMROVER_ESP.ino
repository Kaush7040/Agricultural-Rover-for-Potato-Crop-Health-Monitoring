//FARM ROVER
//esp
//#include <Blynk.h>



#define BLYNK_TEMPLATE_ID "TMPLgfevd_Wc"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "1vGK_Gpa7kst_TfzdUVOOhOT-ELiJs8P"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


char ssid2[] = "Kaush";
char pass2[] = "rfid1234";


const int ARRAY_SIZE = 200;
// Define the array to store values associated with functions
int functionValues[ARRAY_SIZE];
int currentIndex = 0;

// This function is called every time the Virtual Pin 0 state changes
BLYNK_WRITE(V0)
{
  int value = param.asInt();
  if (value!=1){
    Serial.write("0");
    Serial.print("\nBRAKE");
      /*motor1.run(RELEASE);
      motor2.run(RELEASE);
      motor3.run(RELEASE);*/
  }
}

BLYNK_WRITE(V1)
{
  int value = param.asInt();
  if (value!=2){
    Serial.write("1");
    Serial.print("\nFORWARD");
    /*motor1.run(RELEASE);
    motor2.run(FORWARD);
    motor3.run(BACKWARD);*/

  }
}

BLYNK_WRITE(V2)
{
  int value = param.asInt();
  if (value!=3){
    Serial.write("2");
    Serial.print("\nBACKWARD");
    /*motor1.run(RELEASE);
    motor2.run(BACKWARD);
    motor3.run(FORWARD);*/
  }
}

BLYNK_WRITE(V3)
{
  int value = param.asInt();
  if (value!=4){
    Serial.write("3");
    Serial.print("\nLEFT");
    /*motor1.run(FORWARD);
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);*/
  }
}

BLYNK_WRITE(V4)
{
  int value = param.asInt();
  if (value!=5){
    Serial.write("4");
    Serial.print("\nRIGHT");
    /*motor1.run(BACKWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);*/
  }
}


BLYNK_WRITE(V5)
{
  int value = param.asInt();
  if (value!=6){
    Serial.write("5");
    Serial.print("\nANTICLOCKWISE");
    /*motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);*/
  }
}


BLYNK_WRITE(V6)
{
  int value = param.asInt();
  if (value!=7){
    Serial.write("6");
    Serial.print("\nCLOCKWISE");
    /*motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);*/
  }
}

BLYNK_WRITE(V7)
{
  int value = param.asInt();
  if (value!=8){
    Serial.write("7");
    Serial.print("\nREPEAT");
    /*motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);*/
  }
}

BLYNK_WRITE(V8)
{
  int value = param.asInt();
  if (value!=9){
    Serial.write("8");
    Serial.print("\nRESET");
    /*motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);*/
  }
}

void setup()
{
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid2, pass2);
}

void loop(){
  Blynk.run();
}