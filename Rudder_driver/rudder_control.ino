
void fly_by_wire_Mode() //current_rudder_position will follow target_rudder_position
{
positionError = target_rudder_position - current_rudder_position;

if(abs(positionError) <= positionTolerance) 
  {
    stop();  
   //Serial.println("STOP");    
  } 
  else if(abs(positionError) >= positionTolerance)
  {
   if(positionError > 0)
   {
    //Serial.println("TURN RIGHT"); // ADD STOP ONLY ONE LOOP, BEFORE TRUN RIGHT
    turn_right();
   }
    else
   {
    //Serial.println("TURN LEFT");
    turn_left();
   }
   }

   //ADD PAUSE BETWEEN FAST CHANGING DIRECTIONS
 if((last_move_left + STOPTIME) <= millis() && (last_move_right + STOPTIME) <= millis()) // change to lastmove for both directions.
 StopPause = false;
 else
 StopPause = true; 

}
void manual_rudder_control_mode() //controlling the rudder with buttons 
{

if(leftbuttonState == true && rightbuttonState == false && middlebuttonState == false && 
setupbuttonState == false)
target_rudder_position = 30;

else if(leftbuttonState == false && rightbuttonState == true && middlebuttonState == false && 
setupbuttonState == false)
target_rudder_position = 90;

else if(leftbuttonState == false && rightbuttonState == false && middlebuttonState == true && 
setupbuttonState == false)
target_rudder_position = 60;

}
/*
void turn_left()
{
    digitalWrite(MOTOR_RIGHT_DIRECTION_ENABLE_PIN, LOW);
    digitalWrite(MOTOR_LEFT_DIRECTION_ENABLE_PIN, HIGH);  
    analogWrite(MOTOR_PWM_PIN, motor_turning_speed);
    softstopPWM = motor_turning_speed;
    
  }
  
void turn_right()
{
    digitalWrite(MOTOR_RIGHT_DIRECTION_ENABLE_PIN, HIGH);
    digitalWrite(MOTOR_LEFT_DIRECTION_ENABLE_PIN, LOW);
    analogWrite(MOTOR_PWM_PIN, motor_turning_speed);
    softstopPWM = motor_turning_speed;
  
  }*/
void STOPPWM() 
{
  //Serial.println("SOFT STOP");
  if (SoftStopPWM.isReady())
  softPWM--;
  if(softPWM <= 0)
  {
  softPWM = 0;
  digitalWrite(MOTOR_RIGHT_DIRECTION_ENABLE_PIN, LOW);
  digitalWrite(MOTOR_LEFT_DIRECTION_ENABLE_PIN, LOW);
  }
  analogWrite(MOTOR_PWM_PIN, softPWM);
}
void STOP() 
{
  //Serial.println("NORMAL STOP");
  digitalWrite(MOTOR_RIGHT_DIRECTION_ENABLE_PIN, LOW);
  digitalWrite(MOTOR_LEFT_DIRECTION_ENABLE_PIN, LOW);
  analogWrite(MOTOR_PWM_PIN, 0);
  
}

void TURN_RIGHT_SOFT_START()
{
    if (SoftStartPWM.isReady())
  {
    softPWM++;
    if(softPWM >= motor_turning_speed)
    softPWM = motor_turning_speed;
  }
    
    digitalWrite(MOTOR_RIGHT_DIRECTION_ENABLE_PIN, HIGH);
    digitalWrite(MOTOR_LEFT_DIRECTION_ENABLE_PIN, LOW);
    analogWrite(MOTOR_PWM_PIN, softPWM);
    

}  
void TURN_RIGHT_NORMAL_START()
{   
    if(StopPause == false)
    {
    digitalWrite(MOTOR_RIGHT_DIRECTION_ENABLE_PIN, HIGH);
    digitalWrite(MOTOR_LEFT_DIRECTION_ENABLE_PIN, LOW);
    analogWrite(MOTOR_PWM_PIN, motor_turning_speed);
    softPWM = motor_turning_speed;
    last_move_right = millis();
    }
}

void TURN_LEFT_SOFT_START()
{
  if (SoftStartPWM.isReady())
  {
    softPWM++;
    if(softPWM >= motor_turning_speed)
    softPWM = motor_turning_speed;
  }
    digitalWrite(MOTOR_RIGHT_DIRECTION_ENABLE_PIN, LOW);
    digitalWrite(MOTOR_LEFT_DIRECTION_ENABLE_PIN, HIGH);  
    analogWrite(MOTOR_PWM_PIN, softPWM);
 
}

void TURN_LEFT_NORMAL_START()
{   
  if(StopPause == false)
  {
    digitalWrite(MOTOR_RIGHT_DIRECTION_ENABLE_PIN, LOW);
    digitalWrite(MOTOR_LEFT_DIRECTION_ENABLE_PIN, HIGH);  
    analogWrite(MOTOR_PWM_PIN, motor_turning_speed);
    softPWM = motor_turning_speed;
    last_move_left = millis();
  }
}



