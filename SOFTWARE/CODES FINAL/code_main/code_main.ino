#include "functions.h"
void setup() {
  initializeComponents();
  initState();
}

void loop() {
  if(level==0){
    select();
  }
  else if (level==1){
    timeSet();
  }
  else if (level==2){
    intensitySet();
  }
  else if (level==3){
    counting();
  }
  else if (level==4){
    stop();
  }
}
