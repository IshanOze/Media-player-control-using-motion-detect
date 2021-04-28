const int trig = 9;   //digital pin of trigger
const int echo = 10;   //digital pin of echo
long duration,cm;


void setup() {
  Serial.begin(9600);   //Starts the serial monitor
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
 
 }

//function to calculate distance
void calculate_distance(int trig, int echo)
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);   //duration is taken in time so we need to convert it in cm by the following formula
  cm = (duration/2) * 0.0343;

  if(cm > 58)   //you can limit any value for the scale but I found 58 more suitable
    cm = 58;
  
}

void loop() {

  calculate_distance(trig, echo);
  
  //Play/Pause
  if(cm > 25 && cm < 58)    //if any obstruction is introduced between the given scale, it prints 'Play/Pause' in the serial monitor
  {
    Serial.println("Play/Pause");
    delay(500);
    calculate_distance(trig, echo);
  }

 //Lock  
if (cm>=10 && cm<=20)
{
  delay(100); // Hold Time
  calculate_distance(trig,echo);
  
  if (cm>=10 && cm<=20)   //confirms that the obstruction is locked in the given scale
  {
    Serial.println("Locked");
    while(cm<=50)
    {
      calculate_distance(trig,echo);
      if (cm > 2 && cm < 15) //pushed in 
      {Serial.println ("Volume Increased"); delay (300);}
      if (cm > 15 && cm < 30) //pulled out
      {Serial.println ("Volume Decreased"); delay (300);}
    }
  }
}

  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  delay(250);
 }


/* You can always tweak any of the values defined in the code which is suitable for your needs.*/
