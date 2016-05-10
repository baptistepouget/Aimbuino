void restoreData(){
 for (int i=0; i<sizeof(save); i++)
    {
   ((uint8_t*)&save)[i] = EEPROM.read(i);
    }
 }

void saveData(){
         for (int i=0; i<sizeof(save);i++)
        {
            EEPROM.write(i,((uint8_t*)&save)[i]);
         }
  
}

