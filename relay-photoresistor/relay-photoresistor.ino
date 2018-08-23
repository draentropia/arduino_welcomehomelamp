const int relay = 13;
const int sensor = A0;
int prevValue = 0;
int postValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(relay, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(sensor);
  postValue = sensorValue;
  Serial.println(sensorValue);
  int valueDiff = abs(postValue - prevValue);
  
  if (sensorValue < 600)
  {
    if (valueDiff > 100)
    {
      digitalWrite(relay,LOW);
      prevValue = postValue;
    }
  }
  else 
  {
    if (valueDiff > 100)
    {
      digitalWrite(relay,HIGH);
      prevValue = postValue;
    }
  }
  delay(1000);
}
