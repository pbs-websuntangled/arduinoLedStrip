Flasher::Flasher(String name, int lengthOfFlash, int speedOfFlash, uint32_t colourOfFlash)
  {           
    _objectName = name;
    _lengthOfFlash = lengthOfFlash;
    _speedOfFlash = speedOfFlash;
    _colourOfFlash = colourOfFlash;
    _currentFlashHeadPosition = 0;
    _currentFlashTailPosition = 1+_currentFlashHeadPosition - _lengthOfFlash;
    _millisWhenFlashMoveDue = 0;
    _flashDirection = 1;

  } // End of Constructor.

// ---------------------------------------------------------------------------------------------------------------------------
int Flasher::getFlashTailPosition() 
  {
    return _currentFlashTailPosition;       
  }  
// ---------------------------------------------------------------------------------------------------------------------------
int Flasher::getFlashHeadPosition() 
  {
    return _currentFlashHeadPosition;       
  }  
 
  // ---------------------------------------------------------------------------------------------------------------------------
void Flasher::moveFlasher() 
  {     

    // If it's time for a move then turn the existing one off, set the new position and time for next move    
    if (millis() > _millisWhenFlashMoveDue)
    {
      // Turn this flash off 
      for (int i=min(_currentFlashHeadPosition,_currentFlashTailPosition) ; i <= max(_currentFlashHeadPosition,_currentFlashTailPosition); i=i+1) 
        {
          strip.setPixelColor(i, 0x000000);
        }
             
      _currentFlashHeadPosition = _currentFlashHeadPosition + _flashDirection;
      _currentFlashTailPosition = _currentFlashTailPosition + _flashDirection;
      if (_currentFlashHeadPosition > NUMPIXELS)
      {
        _flashDirection = _flashDirection * -1;
        _currentFlashHeadPosition = 1 + NUMPIXELS - _lengthOfFlash;
        _currentFlashTailPosition = NUMPIXELS;
      }
      if (_currentFlashHeadPosition < 0)
      {
        _flashDirection = _flashDirection * -1;
        _currentFlashHeadPosition =  _lengthOfFlash;
        _currentFlashTailPosition = 1;
      }
       _millisWhenFlashMoveDue = millis() + _speedOfFlash;
    }

     // Make sure this flash is on, even if it's been overwritten by another
     for (int i=min(_currentFlashHeadPosition,_currentFlashTailPosition) ; i <= max(_currentFlashHeadPosition,_currentFlashTailPosition); i=i+1) 
      {
        
        strip.setPixelColor(i,_colourOfFlash);
      }  
    
  }  
  
