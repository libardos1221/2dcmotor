
// Motor 1
int motor1Pin1 = 3; // pin 2 on L293D IC
int motor1Pin2 = 4; // pin 7 on L293D IC
int enable1Pin = 6; // pin 1 on L293D IC

// Motor 2
int motor2Pin1 = 8; // pin 10 on L293D IC
int motor2Pin2 = 9; // pin 15 on L293D IC
int enable2Pin = 11; // pin 9 on L293D IC

int state;
int flag=0;        
int stateStop=0;
void setup() {
 
    pinMode(motor1Pin1, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);
    pinMode(enable1Pin, OUTPUT);
    pinMode(motor2Pin1, OUTPUT);
    pinMode(motor2Pin2, OUTPUT);
    pinMode(enable2Pin, OUTPUT);
    
    digitalWrite(enable1Pin, HIGH);
    digitalWrite(enable2Pin, HIGH);
  
    Serial.begin(9600);
    Serial.println("2 WHEELED ROBO CART SIMULATION");
    Serial.println("TYPE (W) TO FORWARD");
    Serial.println("TYPE (S) TO BACKWARD OR REVERSE");
    Serial.println("TYPE (A) TO TURN LEFT");
    Serial.println("TYPE (D) TO TURN RIGHT");
    Serial.println("TYPE (B) TO STOP");
    Serial.println(" ");
}

void loop() {
 
    if(Serial.available() > 0){     
      state = Serial.read();   
      flag=0;
    }   
    
    if (state == 'W' || state == 'w') {
        digitalWrite(motor1Pin1, HIGH);
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW);
        if(flag == 0){
          Serial.println("Go Forward!");
          flag=1;
        }
     }   
    if (state == 'D' || state == 'd') {
        digitalWrite(motor1Pin1, HIGH);
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);
        if(flag == 0){
          Serial.println("RIGHT TURN!");
          flag=1;
        }
    }
   
    if (state == 'E' || state == 'e') {
        digitalWrite(motor1Pin1, HIGH);
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        if(flag == 0){
          Serial.println("SHARP RIGHT TURN!");
          flag=1;
        }
    }

    if (state == 'A' || state == 'a') {
        digitalWrite(motor1Pin1, LOW);
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        if(flag == 0){
          Serial.println("LEFT TURN!");
          flag=1;
        }
    }
   
    if (state == 'Q' || state == 'q') {
        digitalWrite(motor1Pin1, LOW);
        digitalWrite(motor1Pin2, HIGH); 
        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW);
        if(flag == 0){
          Serial.println("SHARP LEFT TURN!");
          flag=1;
        }
    }
    else if (state == 'B' || state == 'b') {
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);
        if(flag == 0){
          Serial.println("STOP!");
          flag=1;
        }
        stateStop=0;
    }
   
    else if (state == 'S' || state == 's') {
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, HIGH);
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        if(flag == 0){
          Serial.println("Reverse!");
          flag=1;
        }
    }

}
