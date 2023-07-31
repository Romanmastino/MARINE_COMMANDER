#include "GyverTimer.h"
#include <SoftwareSerial.h>
#include <EEPROM.h>
#include "defines.h"



///EMERGENCY 
GTimer BUZZER_PEEP(MS, 1000);
int BUZZState = HIGH;
 
// Parameter variables
int target_rudder_position;
int current_rudder_position;
int positionError;

//SET MAX AND MIN POTENTIOMETER
int rudder_max_left;
int rudder_max_right;
int rudder_middle_position;
int CRP_L; // scaled 30-60 current rudder position left side from middle position
int CRP_R; // scaled 60-90 current rudder position right side from middle position

 




//Debug Serial
GTimer Serial_debug_interval(MS, 100);               // создать миллисекундный таймер
 
//INPUTS

  //POTENTIOMETER FILTER
    int sensorValue = 0;    //initialization of sensor variable, equivalent to EMA Y
    float EMA_a = 0.2;      //initialization of EMA alpha
    int EMA_S = 0;          //initialization of EMA S

     // POTENTIOMETER TIME
     GTimer read_analog_rudder_interval(MS, read_potentiometer_interval_ms);
     GTimer read_analog_buttons_interval(MS, read_buttons_interval_ms);

  //BUTTONS 
   bool leftbuttonState;
   bool rightbuttonState;
   bool middlebuttonState;
   bool setupbuttonState;
      //EEPROM
      bool left_max_eeprom;
      bool right_max_eeprom;
      bool middle_pos_eeprom;
      //TIME
      unsigned long leftbuttonstartTime;
      unsigned long rightbuttonstartTime;
      unsigned long middlebuttonstartTime;
      ///SETUP BUTTON CONFIRMATION
      bool setupButtonPressConfirmation = true;


//communication
const unsigned long MAX_MESSAGE_LENGHT = 12;



// MOTOR CONTROL
int motor_turning_speed = 40; // 40-
int softPWM;
bool StopPause = false;
unsigned long last_move_right;
unsigned long last_move_left;
      //TIME
      GTimer SoftStopPWM(MS, decelerationTime);  // 
      GTimer SoftStartPWM(MS, decelerationTime);
 
void setup()
{

 EEPROM.get(0, rudder_max_left); 
 EEPROM.get(10, rudder_max_right);  
 EEPROM.get(20, rudder_middle_position);



//////PID///

  //////

    Serial.begin(57600);           //setup of Serial module, 115200 bits/second
    EMA_S = analogRead(POTENTIOMETER_PIN_IN);  //set EMA S for t=1

pinMode(MOTOR_PWM_PIN, OUTPUT); //PWM  
pinMode(MOTOR_RIGHT_DIRECTION_ENABLE_PIN, OUTPUT); //Right
pinMode(MOTOR_LEFT_DIRECTION_ENABLE_PIN, OUTPUT); //Left
pinMode(BUZZER_PIN_OUT, OUTPUT); 
//st

Serial.println("READING EEPROM VALUES:");
//if(rudder_max_right - rudder_max_left < 5)
//error mode
Serial.print("MAX LEFT: ");Serial.print(rudder_max_left);
Serial.print(" MIDDLE: ");Serial.print(rudder_middle_position);
Serial.print(" MAX RIGHT: ");Serial.println(rudder_max_right);


digitalWrite(BUZZER_PIN_OUT, HIGH);
delay(100);
digitalWrite(BUZZER_PIN_OUT, LOW);

target_rudder_position = 60;

}
 
void loop(){

   //emergencyOFF();

    serial_control();
    check_inputs();
    calibration();

    if(setupbuttonState != 1) //Turn ON rudder control when setup mode is OFF.
    {
      manual_rudder_control_mode();
      fly_by_wire_Mode(); 
    }
    else
    stop(); 




    //debug
    if (Serial_debug_interval.isReady())
    {
     // Serial.print(" CRP: ");Serial.print(current_rudder_position);Serial.print(" TRP: ");Serial.println(target_rudder_position);
      //Serial.print(" Motor speed: ");Serial.println(softstopPWM);
     // Serial.print("positionError "); Serial.println(positionError); 
     
    }
                                             
}
