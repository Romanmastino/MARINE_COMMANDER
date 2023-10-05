#ifndef defines.h
#define defines.h

//INPUTS
        
    #define UP_PIN 37  //BOWTHRUSTER LEFT / PCB 32
    #define DOWN_PIN 35  //BOWTHRUSTER RIGHT / PCB 33
    #define EAST_PIN 36 //LEFT ENGINE FORWARD / PCB 34
    #define WEST_PIN 34 //RIGHT ENGINE FORWARD / PCB 35
    #define SOUTH_PIN 41 //LEFT ENGINE BACKWARD / PCB 36
    #define NORTH_PIN 40 //RIGHT ENGINE BACKWARD / PCB  37
    #define R1_PIN 42 //STERNTHRUSTER LEFT / PCB 38
    #define R2_PIN 45 //STERNTHRUSTER RIGHT / PCB 39
    #define R0_PIN 46 //GREEN / PCB 40


//OUTPUTS

    #define BOWTHRUSTER_LEFT_PIN ? // PCB contact between oval 1 and 2
    #define BOWTHRUSTER_RIGHT_PIN ? // PCB contact between oval 1 and 3
    
    #define LEFT_ENGINE_FORWARD_PIN ? // PCB contact from potentiometer P1 square 6 (PCB square 3 VCC input, square 4 GND input for potentiometer P1, P2 )
    #define LEFT_ENGINE_REVERSE_PIN ? // PCB contact from potentiometer P2 square 6 (PCB square 3 VCC input, square 4 GND input for potentiometer P1, P2 )
    #define LEFT_ENGINE_NEUTRAL_SWITCH_PIN ? // PCB contact between square 1 and 2/X
    
    #define RIGHT_ENGINE_FORWARD_PIN ? // PCB contact from potentiometer P3 square 12 (PCB square 9 VCC input, square 10 GND input for potentiometer P1, P2 )
    #define RIGHT_ENGINE_REVERSE_PIN ? // PCB contact from potentiometer P4 square 12 (PCB square 9 VCC input, square 10 GND input for potentiometer P1, P2 )
    #define RIGHT_ENGINE_NEUTRAL_SWITCH_PIN ? // PCB contact between square 7 and 8/X
    
    #define STERNTHRUSTER_LEFT_PIN ? // PCB contact between oval 4 and 5
    #define STERNTHRUSTER_RIGHT_PIN ? // PCB contact between oval 4 and 6

    #define TAKE_CMD_LEFT_ENG_PIN ?// PCB red letters on white background contact between 1 and 2/3
    #define TAKE_CMD_RIGHT_ENG_PIN ?// PCB red letters on white background contact between 6 and 7/8

    #define ANCHOR_UP_PIN ? // PCB contact between oval 7 and 8
    #define ANCHOR_DOWN_PIN ? // PCB contact between oval 7 and 9

    #define HORN_PIN ? // PCB red letters on white background contact between 4 and 5
    #define BUZZER_PIN ? // PCB red letters on white background 11 and 12





    #endif
    
