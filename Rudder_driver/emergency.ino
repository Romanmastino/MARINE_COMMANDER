
void emergencyOFF()
{
 digitalWrite(BUZZER_PIN_OUT, BUZZState); // MAKE A NICE SOUND
if (BUZZER_PEEP.isReady())
{
   if (BUZZState == LOW) {
      BUZZState = HIGH;
    } else {
      BUZZState = LOW;
    }   
}
//STOP PUMP
  digitalWrite(MOTOR_RIGHT_DIRECTION_ENABLE_PIN, LOW);
  digitalWrite(MOTOR_LEFT_DIRECTION_ENABLE_PIN, LOW);
  analogWrite(MOTOR_PWM_PIN, 0);



}