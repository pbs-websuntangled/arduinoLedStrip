#ifndef Flasher_h
#define Flasher_h
#include <Arduino.h>

/*
  Written because the accell library has no orchestration features
*/


class Flasher
  {
    public:
      Flasher(String name, int lengthOfFlash, int speedOfFlash, uint32_t colourOfFlash);
      
      int getFlashTailPosition(); // 
      int getFlashHeadPosition(); // 
      void moveFlasher();

      
    private:
      String _objectName;
      int _lengthOfFlash;
      int _speedOfFlash;
      uint32_t _colourOfFlash; 
      int _flashDirection;
      int _currentFlashHeadPosition;
      int _currentFlashTailPosition;
      long _millisWhenFlashMoveDue;
      

  };

#endif

