#define echoPin 8
#define trigPin 9
#define redPin 3
#define bluePin 4
#define greenPin 5
#define piezoPin 2

int dro = 0;
float manzili = 0.0;
void setup()
{
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);A
  pinMode(greenPin, OUTPUT);
  pinMode(piezoPin, OUTPUT);
	Serial.begin(9600);

}

void loop()
{
  digitalWrite(trigPin, 1);
 delayMicroseconds(10);
   digitalWrite(trigPin, 0);
  
 dro = pulseIn(echoPin, HIGH);
  manzili = 0.034*(dro/2.0);
  Serial.println(manzili);
  
  if(manzili > 50){
  RGBon(0,1,0);
    digitalWrite(piezoPin, 0);
  }else if(manzili < 50){
  	  digitalWrite(piezoPin, 1);
        RGBon(1,0,0);
    	delay(50);
        RGBon(0,0,0);
        delay(50);
  }
}

void RGBon(bool r, bool g, bool b){
  digitalWrite(redPin, r);
  digitalWrite(greenPin, g);
  digitalWrite(bluePin, b);	
}