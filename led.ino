int red = 20;
int green = 20;
int blue = 20;

void ledFade() {
  for (int i=0; i<NUMPIXELS; i++){              //loop throug pixels
    
    int fadeState = ledState[i][3];             // get fade state of LED for fadeStates array
    
    for(int y=0; y<3; y++){                     // loop throug color
      
      if(fadeStates[fadeState][y] == 255){      // check if increment or decrement
        if (ledState[i][y] < 255){              // Limit to max 255
          ledState[i][y] = ledState[i][y] + 1;
        }
      }else{
        if (ledState[i][y] > 0){                // Limit to min 0
          ledState[i][y] = ledState[i][y] - 1;
        }
      }
    }

    // Check for next fading state
    if( fadeStates[fadeState][0] == ledState[i][0] && 
        fadeStates[fadeState][1] == ledState[i][1] && 
        fadeStates[fadeState][2] == ledState[i][2]){
      if (ledState[i][3] < 6){
        ledState[i][3] = ledState[i][3] + 1;
      }else{
        ledState[i][3] = 0;
      }
    }
    pixels.setPixelColor(i, pixels.Color(ledState[i][0],ledState[i][1],ledState[i][2]));
  }
}

void initLeds(){
  int state = 0;
  int value = 0;
  
  for (int i=0; i<NUMPIXELS; i++){
     if(state == 7){
        state = 0;
     }
     ledState[i][3] = state;
     state++;
  }
}

void initLedsFloat(){
  int state = 0;
  int value = 0;
  
  for (int i=0; i<NUMPIXELS; i++){
     if(state == 7){
        state = 0;
     }
     ledState[i][0] = value;
     value = value+255/NUMPIXELS;
  }
}
