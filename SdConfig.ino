/*
  SdConfig.h - Library for reading json config files from sd cards.
  Created by Germán Martinez.
  Released into the public domain.
*/
#ifndef SdConfig_h
#define SdConfig_h

#include "Arduino.h"

class SdConfig
{
  public:
    SdConfig(String configFileName);
    void read();
    void print();
};

#endif

