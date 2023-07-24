#ifndef defines.h
#define defines.h

//INPUT SIGNALS
    
    //BUTTONS PINOUT
    #define LEFT_BUTTON_PIN_IN A0
    #define RIGHT_BUTTON_PIN_IN A1
    #define MIDDLE_BUTTON_PIN_IN A2
    #define SETUP_BUTTON_PIN_IN A6

    //POTENTIOMETER PINOUT
    #define POTENTIOMETER_PIN_IN A3

    //BUZZER PINOUT
    #define BUZZER_PIN_OUT 4 //BUZZER D0 controllino
    
    //TIME INTERVALS
    #define read_potentiometer_interval_ms 20 //20ms interval between potentiometer reading
    #define read_buttons_interval_ms 30 // 30ms interval between buttons reading

///MOTOR PARAMETERS
     //PINOUTS
     #define MOTOR_PWM_PIN 9
     #define MOTOR_RIGHT_DIRECTION_ENABLE_PIN 7
     #define MOTOR_LEFT_DIRECTION_ENABLE_PIN 8
    
    //SOFT STOP
     
      #define STOPTIME 1000 // PAUSE IN MS BETWEEN DIRECTION CHANGE, TO TURN OFF PUT 0 
      #define stop STOP        //TURN OFF SOFT STOP
      //#define stop STOPPWM   //TURN ON SOFT STOP
      #if !defined(stop)
      #error
      #endif
      #define decelerationTime 2 //If soft stop is ON, interval between PWM output: 255..2ms..254..2ms..253..

    //SOFT START RIGHT DIRECTION
      //#define turn_right TURN_RIGHT_SOFT_START  //TURN ON SOFT START
      #define turn_right TURN_RIGHT_NORMAL_START  //TURN OFF SOFT START
      #if !defined(turn_right)
      #error
      #endif

    //SOFT START LEFT DIRECTION
      //#define turn_left TURN_LEFT_SOFT_START  //TURN ON SOFT START
      #define turn_left TURN_LEFT_NORMAL_START  //TURN OFF SOFT START
      #if !defined(turn_left)
      #error
      #endif
    
//CONTROLS
#define positionTolerance 1 // +/-1 degree. 


#endif