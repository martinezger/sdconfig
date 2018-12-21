#include <Arduino.h>
#include <ArduinoJson.h>
#include <SD.h>
#include <SPI.h>
#include <SdConfig.h>


//Constructor

SdConfig::SdConfig(char* fileName, int chipSelect){
    
    _fileName = fileName;
    _chipSelect = chipSelect;
    
}

// Getters and Setters

int SdConfig::getChipSelect(){
    return _chipSelect;
}

int SdConfig::setChipSelect(int chipSelect){
    _chipSelect = chipSelect;
}

//methods

bool SdConfig::begin(){

    if (!SD.begin(_chipSelect)) {
        Serial.println("initialization failed!");
        return false; 
    }
    
    // Open file for reading
    File file = SD.open(_fileName);

    if (!file){
        Serial.println("File not exist exist");
        return false; 
    } 
    
     Serial.println("File exist");
    
    // Allocate the memory pool on the stack.
    // Don't forget to change the capacity to match your JSON document.
    // Use arduinojson.org/assistant to compute the capacity.
    DynamicJsonBuffer jsonBuffer;

    // Parse the root object
    _root = jsonBuffer.parseObject(file);

    if (!_root.success()){
        Serial.println(F("Failed in attempt to parsing file"));
        return false;
    }
        
    Serial.println(F("Success in attempt to parsing file"));        
    file.close();
    return true;
}

    
    
