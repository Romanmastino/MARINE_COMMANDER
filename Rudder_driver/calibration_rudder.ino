//this loop is switched on in inputs

void calibration()
{
  switch (setupbuttonState) {
  case 1:
  //////////////////////LEFT MAX//////////////////////
   if(leftbuttonState == true && rightbuttonState == false && middlebuttonState == false && (leftbuttonstartTime + 5000) > millis())
   {
    rudder_max_left = EMA_S; //take filtered potentiometer value 
    
    if(millis() >= (leftbuttonstartTime + 4500) && millis() <= (leftbuttonstartTime + 4800)) //wait until pot value gets stable 
    {
      digitalWrite(BUZZER_PIN_OUT, HIGH); //turn on confirmatio signal 
      if(left_max_eeprom == true) //run this loop one time, the left_max_eeprom flag will be opened in check_inputs()
      {
      EEPROM.put(0, rudder_max_left); // write in 0 rudder_max_left value 
      Serial.print("Saving max rudder left value:");Serial.println(rudder_max_left); //write confirmation
      left_max_eeprom = false; // close this loop,  
      }

    }
    else
    {
    digitalWrite(BUZZER_PIN_OUT, LOW); // turn off confirmation signal
  
    }
   }
   /////////////////////////RIGHT MAX////////////////
   if(leftbuttonState == false && rightbuttonState == true && middlebuttonState == false && (rightbuttonstartTime + 5000) > millis())
   {
    rudder_max_right = EMA_S;
    
    if(millis() >= (rightbuttonstartTime + 4500) && millis() <= (rightbuttonstartTime + 4800)  )
    {
      digitalWrite(BUZZER_PIN_OUT, HIGH);
      if(right_max_eeprom == true)
      {
      EEPROM.put(10, rudder_max_right);
      Serial.print("Saving max rudder right value:");Serial.println(rudder_max_right);
      right_max_eeprom = false;
      }
    }
    else
    {
    digitalWrite(BUZZER_PIN_OUT, LOW);
  
    }
   }
         ////////////////////////MIDDLE POSITION BUTTON////
     if(leftbuttonState == false && rightbuttonState == false && middlebuttonState == true && (middlebuttonstartTime + 5000) > millis())
   {
    rudder_middle_position = EMA_S;
    
    if(millis() >= (middlebuttonstartTime + 4500) && millis() <= (middlebuttonstartTime + 4800)  )
    {

      digitalWrite(BUZZER_PIN_OUT, HIGH);
      if(middle_pos_eeprom == true)
      {
        EEPROM.put(20, rudder_middle_position);
        Serial.print("Saving rudder middle position value:");Serial.println(rudder_middle_position);
        middle_pos_eeprom = false;
      }         

    }
    else
    {
    digitalWrite(BUZZER_PIN_OUT, LOW);
    }
   }
  break;

  }  

}
