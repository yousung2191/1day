#define SIZE 5

float num[SIZE + 1] = { 0, };
float prev_avg;

int trigPin = 2;
int echoPin = 3;

float mov_avg_filter(float prev_avg, float sample)
{
  float avg = 0.0;

  num[SIZE] = sample;

  avg = prev_avg + num[SIZE] / SIZE - num[0] / SIZE;

  for (int i = 0; i < SIZE; i++)
    num[i] = num[i + 1];

  num[SIZE] = 0.0;

  return avg;
}

void setup() {
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  long duration;
  long distance;
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  
  distance = duration * 0.034 / 2;
  Serial.println(distance);
  prev_avg = mov_avg_filter(prev_avg, distance);

  Serial.print("average: ");
  Serial.println(prev_avg);
  
  delay(200);
}
