const int switchPin = 2; // the number of the input pin
long startTime; // store starting time here
long duration; // variable to store how long the timer has been running
float secduration; // variable to store the duration in seconds
int startStop;
int CurrentStartTime;

void setup()
{
  //Set the input pin as an input
  pinMode(2, INPUT);
  Serial.begin(9600); //this will allow the Uno to comunicate with the serial monitor
}

void loop()
{
  startTime = millis(); // stores the number of millisceoncds since the Uno was last reset. See http://arduino.cc/en/Reference/millis
  Serial.println("Button pushed"); // this will print to the serial monitor
  //Read start state from pin
  startStop = digitalRead(switchPin);
  while (startStop != HIGH) {
    CurrentStartTime = millis();
    startStop = digitalRead(switchPin);
    duration = abs(CurrentStartTime - startTime);
    secduration = (float)duration / 1000;
    Serial.print("Button released after "); // print out your results
    Serial.print(secduration);
    Serial.println(" seconds");
  }
  Serial.print("Button released after "); // print out your results
  Serial.print(secduration);
  Serial.println(" seconds");


}
