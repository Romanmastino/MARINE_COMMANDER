#include "defines.h"

bool BOWTHRLEFT;
bool BOWTHRRIGHT;
bool LEFTENGFWD;
bool RIGHTENGFWD;
bool LEFTENGREV;
bool RIGHTENGREV;
bool STERNTHRLEFT;
bool STERNTHRRIGHT;
bool HORN;
unsigned long debug_timer;


void setup() 

{

    pinMode(UP_PIN, INPUT);
    pinMode(DOWN_PIN, INPUT);
    pinMode(EAST_PIN, INPUT);
    pinMode(WEST_PIN, INPUT);
    pinMode(SOUTH_PIN, INPUT);
    pinMode(NORTH_PIN, INPUT);
    pinMode(R1_PIN, INPUT);
    pinMode(R2_PIN, INPUT);
    pinMode(R0_PIN, INPUT);


    pinMode(BOWTHRUSTER_LEFT_PIN, OUTPUT);
    pinMode(BOWTHRUSTER_RIGHT_PIN, OUTPUT);
    pinMode(LEFT_ENGINE_FORWARD_PIN, OUTPUT);
    pinMode(LEFT_ENGINE_REVERSE_PIN, OUTPUT);
    pinMode(LEFT_ENGINE_NEUTRAL_SWITCH_PIN, OUTPUT);
    pinMode(RIGHT_ENGINE_FORWARD_PIN, OUTPUT);
    pinMode(RIGHT_ENGINE_REVERSE_PIN, OUTPUT);
    pinMode(RIGHT_ENGINE_NEUTRAL_SWITCH_PIN, OUTPUT);
    pinMode(STERNTHRUSTER_LEFT_PIN, OUTPUT);
    pinMode(STERNTHRUSTER_RIGHT_PIN, OUTPUT);
    pinMode(HORN_PIN, OUTPUT);
    pinMode(HORN_PIN, OUTPUT);

}

void loop() {
readInputs();
debug();
}

void readInputs()
{
 BOWTHRLEFT = !digitalRead(UP_PIN);
 BOWTHRRIGHT = !digitalRead(DOWN_PIN);
 LEFTENGFWD = !digitalRead(EAST_PIN);
 RIGHTENGFWD = !digitalRead(WEST_PIN);
 LEFTENGREV = !digitalRead(SOUTH_PIN);
 RIGHTENGREV = !digitalRead(NORTH_PIN);
 STERNTHRLEFT = !digitalRead(R1_PIN);
 STERNTHRRIGHT = !digitalRead(R2_PIN);
 HORN = !digitalRead(R0_PIN);
}

void debug()
{
  if(debug_timer <= millis())
  {

  
if(BOWTHRLEFT == 0)
Serial.println("BOW THRUSTER LEFT");
if(BOWTHRRIGHT == 0)
Serial.println("BOW THRUSTER RIGHT");
if(LEFTENGFWD == 0)
Serial.println("LEFT ENGINE FORWARD");
if(RIGHTENGFWD == 0)
Serial.println("RIGHT ENGINE FORWARD");
if(LEFTENGREV == 0)
Serial.println("LEFT ENGINE REVERSE");
if(RIGHTENGREV == 0)
Serial.println("RIGHT ENGINE REVERSE");
if(STERNTHRLEFT == 0)
Serial.println("STERN THRUSTER LEFT");
if(STERNTHRLEFT == 0)
Serial.println("STERN THRUSTER RIGHT");
if(HORN == 0)
Serial.println("HORN");
debug_timer = millis() + 100;
}
}

    