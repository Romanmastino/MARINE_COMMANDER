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
    pinMode(BUZZER, OUTPUT);
    pinMode(AUX_1, OUTPUT);
    
    
    digitalWrite(LEFT_ENGINE_FORWARD_PIN, LOW);
    digitalWrite(LEFT_ENGINE_REVERSE_PIN, LOW);
    digitalWrite(RIGHT_ENGINE_FORWARD_PIN, LOW);
    digitalWrite(RIGHT_ENGINE_REVERSE_PIN, LOW);

    
    digitalWrite(BUZZER, HIGH);
    delay(1000);
    digitalWrite(BUZZER, LOW);
    Serial.begin(115200);
    Serial.println("PILOT-H STARTED");
    


}

void loop() {
readInputs();
//debug();
controlOutputs();
}

void readInputs()
{
 BOWTHRLEFT = digitalRead(UP_PIN);
 BOWTHRRIGHT = digitalRead(DOWN_PIN);
 LEFTENGFWD = digitalRead(EAST_PIN);
 RIGHTENGFWD = digitalRead(WEST_PIN);
 LEFTENGREV = digitalRead(SOUTH_PIN);
 RIGHTENGREV = digitalRead(NORTH_PIN);
 STERNTHRLEFT = digitalRead(R1_PIN);
 STERNTHRRIGHT = digitalRead(R2_PIN);
 HORN = digitalRead(R0_PIN);
}


void controlOutputs()
{
  
    if(BOWTHRLEFT == 0)
    digitalWrite(BOWTHRUSTER_LEFT_PIN, HIGH);
    else
    digitalWrite(BOWTHRUSTER_LEFT_PIN, LOW);

    if(BOWTHRRIGHT == 0)
    digitalWrite(BOWTHRUSTER_RIGHT_PIN, HIGH);
    else
    digitalWrite(BOWTHRUSTER_RIGHT_PIN, LOW);

    if(LEFTENGFWD == 0)
    digitalWrite(LEFT_ENGINE_FORWARD_PIN, HIGH);
    else
    digitalWrite(LEFT_ENGINE_FORWARD_PIN, LOW);

    if(LEFTENGREV == 0)
    digitalWrite(LEFT_ENGINE_REVERSE_PIN, HIGH);
    else
    digitalWrite(LEFT_ENGINE_REVERSE_PIN, LOW);

    if(LEFTENGFWD == 0 || LEFTENGREV == 0)
    digitalWrite(LEFT_ENGINE_NEUTRAL_SWITCH_PIN, HIGH);
    else
    digitalWrite(LEFT_ENGINE_NEUTRAL_SWITCH_PIN, LOW);

    if(RIGHTENGFWD == 0)
    digitalWrite(RIGHT_ENGINE_FORWARD_PIN, HIGH);
    else
    digitalWrite(RIGHT_ENGINE_FORWARD_PIN, LOW);
    
    if(RIGHTENGREV == 0)
    digitalWrite(RIGHT_ENGINE_REVERSE_PIN, HIGH);
    else
    digitalWrite(RIGHT_ENGINE_REVERSE_PIN, LOW);

    if(RIGHTENGFWD == 0 || RIGHTENGREV == 0)
    digitalWrite(RIGHT_ENGINE_NEUTRAL_SWITCH_PIN, HIGH);
    else
    digitalWrite(RIGHT_ENGINE_NEUTRAL_SWITCH_PIN, LOW);

    if(STERNTHRLEFT == 0)
    digitalWrite(STERNTHRUSTER_LEFT_PIN, HIGH);
    else
    digitalWrite(STERNTHRUSTER_LEFT_PIN, LOW);

    if(STERNTHRRIGHT == 0)
    digitalWrite(STERNTHRUSTER_RIGHT_PIN, HIGH);
    else
    digitalWrite(STERNTHRUSTER_RIGHT_PIN, LOW);
 
    if(HORN == 0)
    digitalWrite(HORN_PIN, HIGH);
    else
    digitalWrite(HORN_PIN, LOW);
    
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
if(STERNTHRRIGHT == 0)
Serial.println("STERN THRUSTER RIGHT");
if(HORN == 0)
Serial.println("HORN");
debug_timer = millis() + 100;
}
}
    