void serial_control()
{
 
   while (Serial.available() > 0)
   {
   static char message[MAX_MESSAGE_LENGHT];
   static unsigned int message_pos = 0;
   char inByte = Serial.read();
   if(inByte != '\n' && (message_pos < MAX_MESSAGE_LENGHT - 1))
   {
     message[message_pos] = inByte;
     message_pos++;

   }
   else
   {
     message[message_pos] = '\0';
     
     target_rudder_position = atoi(message);
     
     ///30 degrees scale
     if(target_rudder_position >= 90)
     target_rudder_position = 90;
     else if(target_rudder_position <= 30)
     target_rudder_position = 30;
     Serial.print("SET NEW RUDDER ANGLE "); Serial.println(target_rudder_position);
     message_pos = 0;
   }
   }
  }