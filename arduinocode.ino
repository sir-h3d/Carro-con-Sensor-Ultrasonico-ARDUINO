class NewPing {
  public:
    NewPing(int TRIGGER_PIN, int ECHO_PIN, int MAX_DISTANCE ){
      trigPin=TRIGGER_PIN;
      echoPin=ECHO_PIN;
      maxDistance=MAX_DISTANCE;

      pinMode(trigPin,OUTPUT);
      pinMode(echoPin,INPUT);
    }

    int ping_cm(){
      // Clears the trigPin
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      long duration = pulseIn(echoPin, HIGH);
      int distance =  duration*0.034/2;
      if (distance>maxDistance){
        distance=0;
      }
      return(distance);
    }

  private:
    int trigPin;
    int echoPin;
    int maxDistance;
};



#define TRIG_PIN A0                
#define ECHO_PIN A1                
#define MAX_DISTANCE 200            
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE); 

boolean goesForward=false;         
int distance = 100;               
int speedSet = 0;               
                                  
const int motorPin1  = 8;          
const int motorPin2  = 9;          
const int motorPin3  = 5;          
const int motorPin4  = 6;  

void setup() {
  Serial.begin(115200);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
}

void loop() {
 delay(50);  
 distance = sonar.ping_cm();
 Serial.print("Ping: ");
 Serial.print(distance); 
 Serial.println("cm");
 int distanceR = 0;
 int distanceL =  0;
 delay(40);
 if(distance<=15)                
 {
  moveStop();                   
  delay(1000);                   
  moveBackward();             
  delay(1000);                      
  moveStop();

  if(distanceR>=distanceL)
  {
    turnRight();           
    moveStop();
  }
  
      else
      
  {
    turnLeft();            
    moveStop();
  }
  
 }else   
                        
 {
  moveForward();         
 }
 distance = readPing();
}

int readPing() { 
  delay(70);
  int cm = sonar.ping_cm();
  if(cm==0)
  {
    cm = 250;
  }
  return cm;
}

void moveStop() {
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 0);
  } 
  
void moveForward() {       


    analogWrite(motorPin1, 180);       
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 180);     
    analogWrite(motorPin4, 0);  
  
}

void moveBackward() {        
    
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 180);       
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 180);      
  
}  

void turnRight() {     
  
    analogWrite(motorPin1, 180);     
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 180);   
    delay(300);
    moveForward();      
  
} 
 
void turnLeft() {           
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 180);   
    analogWrite(motorPin3, 180);    
    analogWrite(motorPin4, 0);     
    delay(300);
    moveForward();
}  
