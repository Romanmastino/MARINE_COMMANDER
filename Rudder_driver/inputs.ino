void check_inputs()
{
  /// read potentimeter every 20ms
  
  if (read_analog_rudder_interval.isReady())
  {


    int dummy = analogRead(POTENTIOMETER_PIN_IN); // "clean" analog input
    
    sensorValue = analogRead(POTENTIOMETER_PIN_IN);                //read the sensor value using ADC
    EMA_S = (EMA_a*sensorValue) + ((1-EMA_a)*EMA_S);    //run the EMA
    //current_rudder_position = map(EMA_S, rudder_max_left, rudder_max_right, 30, 90); OLD
    CRP_R = map(EMA_S, rudder_middle_position, rudder_max_right, 60, 90); // scale from middle to max right
    CRP_L = map(EMA_S, rudder_max_left, rudder_middle_position, 30, 60); //scale from middle to max left
    
    if(EMA_S > rudder_middle_position)
    current_rudder_position = CRP_R;
    else
    current_rudder_position = CRP_L;


  }


  if (read_analog_buttons_interval.isReady())
  {
    
    //LEFT BUTTON
   if(analogRead(LEFT_BUTTON_PIN_IN) > 100) // if button pressed longer than 100ms
   {
   leftbuttonState = true;
   }
   else
   {
   left_max_eeprom = true;
   leftbuttonState = false;
   leftbuttonstartTime = millis();
   }
 
    //RIGHT BUTTON
   if(analogRead(RIGHT_BUTTON_PIN_IN) > 100) 
   {
   rightbuttonState = true;
   }
   else
   {
   right_max_eeprom = true;
   rightbuttonState = false;
   rightbuttonstartTime = millis();
   }

   //MIDDLE BUTTON
   if(analogRead(MIDDLE_BUTTON_PIN_IN) > 100) 
   {
   middlebuttonState = true;
   }
   else
   {
   middle_pos_eeprom = true;
   middlebuttonState = false;
   middlebuttonstartTime = millis();
   }

   //SETUP BUTTON
   if(analogRead(SETUP_BUTTON_PIN_IN) > 100) 
   {
   setupbuttonState = true;
   if(setupButtonPressConfirmation == true)
   {
     setupButtonPressConfirmation = false;
     Serial.println("ENTER CALIBRATION MODE");

   }

   }
   else
   {
   setupbuttonState = false;
   if(setupButtonPressConfirmation == false)
   {
   setupButtonPressConfirmation = true;
   Serial.println("EXIT CALIBRATION MODE. READING STORED EEPROM VALUES: ");
   EEPROM.get(0, rudder_max_left);
   EEPROM.get(10, rudder_max_right);
   EEPROM.get(20, rudder_middle_position);
   Serial.print("MAX LEFT: ");Serial.print(rudder_max_left);
   Serial.print(" MIDDLE: ");Serial.print(rudder_middle_position);
   Serial.print(" MAX RIGHT: ");Serial.println(rudder_max_right);
   }

   }


  }
  

}