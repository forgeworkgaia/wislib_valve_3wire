class Valve {
  
  private:

    int id;
    int state;

    // 3 wire pin that OPENS the valve
    byte VALVEONPIN;
    
    // 3 wire pin that CLOSES the valve
    byte VALVEOFFPIN;

    char mode;

    //Cycle is derived from current millis divided by cycleTime.
    int cycle;

    unsigned long cycleTime;

    float valveStartPercentage;
    float valveStopPercentage;

    int valveStatus;

  public:

    Valve (int incId, byte incValveOnPin, byte incValveOffPin, int incMode) {

    
    this->id = incId;

    this->VALVEONPIN = incValveOnPin;
    this->VALVEOFFPIN = incValveOffPin;

    //Mode defines the cycle settings
    this->mode = incMode;

    init();
      
    }

    void init() {

      //Defines the cycle that thiws valve should use.
      switch (this->mode){

        case 1:
        
          //Cycletime is the duration of the cycle, expressed in milliseconds.

          //Common Time Translation
          // 5 minutes = 300000
          // 10 minutes = 600000
          // 30 minutes = 1800000

          this->cycleTime = 3600000;


          //valveStartPercentage is the percentage of time, expressed in decimal form
          //that you want to wait in the cycle before starting.
          //This should be less than stop and less that 1.00.
          this->valveStartPercentage = .0000;

          //valveStopPercentage is the percentage of time, expressed in decimal form
          //that you want to wait in the cycle before stopping.
          //This should be greater than start and less than 1.00.
          this->valveStopPercentage = .08;
      
          break;

      }

        pinMode(this->VALVEOFFPIN, OUTPUT);
        pinMode(this->VALVEONPIN, OUTPUT);

        //On init, reset Valve to IDLE
        off();

   
    }

    void off() {

      //Reset Valve to state IDLE.

      ValveOff();
      
      this->state = 0;
      this->valveStatus = 0;
      
    }


    void ValveOff(){

      digitalWrite(this->VALVEOFFPIN, LOW);
      digitalWrite(this->VALVEONPIN, HIGH);

      
      this->valveStatus = 0;

      
      Serial.println("Valve OFF");


    }

    void ValveOn(){

      digitalWrite(this->VALVEONPIN, LOW);
      digitalWrite(this->VALVEOFFPIN, HIGH);

      this->valveStatus = 1;

      Serial.println("Valve ON");

    }

    unsigned long getCycleTime(){
      
      return this->cycleTime;
      
      
    }

    void setCycle(int incCycle){
      
      this->cycle = incCycle;
      
      
      }

    int getCycle(){
      
      return this->cycle;;
      
      
      }


    float getValveStartPercentage(){

      return this->valveStartPercentage;

    }

    
    float getValveStopPercentage(){

      return this->valveStopPercentage;
      
    }


    int ValveRunning(){
      
      return this->valveStatus;
      
      
      }


};
