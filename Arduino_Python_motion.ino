const int trig = 9;
const int echo = 10;
long duration,cm;


void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
 
 }

void calculate_distance(int trig, int echo)
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  cm = (duration/2) * 0.0343;

  if(cm > 58)
    cm = 58;
  
}

void loop() {

  calculate_distance(trig, echo);
  
  //Play/Pause
  if(cm > 25 && cm < 58)
  {
    Serial.println("Play/Pause");
    delay(500);
    calculate_distance(trig, echo);
  }

 //Lock  
if (cm>=10 && cm<=20)
{
  delay(100); //Hand Hold Time
  calculate_distance(trig,echo);
  
  if (cm>=10 && cm<=20)
  {
    Serial.println("Locked");
    while(cm<=50)
    {
      calculate_distance(trig,echo);
      if (cm > 2 && cm < 15) //Hand pushed in 
      {Serial.println ("Volume Increased"); delay (300);}
      if (cm > 15 && cm < 30) //Hand pulled out
      {Serial.println ("Volume Decreased"); delay (300);}
    }
  }
}

  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  delay(250);
 }
