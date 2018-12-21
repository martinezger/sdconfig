/*
  SdConfig.h - Library for reading json config files from sd cards.
  Created by Germán Martinez.
  Released into the public domain.
*/
#ifndef SdConfig_h
#define SdConfig_h

#include <ArduinoJson.h>
#include <Arduino.h>
#include <SD.h>

class SdConfig
{
    public:
        SdConfig(char* fileName, int chipSelect);
        JsonObject& getRoot(){ 
            return _root;
        };
        bool begin();
        int getChipSelect();
        int setChipSelect(int chipSelect);        
        JsonVariant _root;
    private:
        //arduino's pin which read data from card
        int _chipSelect;
        //file Name
        char* _fileName;
        // File
        File _file;
        //JsonObject
        
};

#endif

