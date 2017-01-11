char data = 0;            //Variable for storing received data
int IN1=8;
int IN2=9;
//int ENA=3;

int IN3=7;
int IN4=6;

void setup() {
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  
  Serial.begin(9600);   //Sets the baud for serial data transmission                               
  pinMode(9, OUTPUT);  //Sets digital pin 13 as output pin  
  pinMode(6, OUTPUT);
}

void loop() {
  if(Serial.available() > 0){      // Send data only when you receive data:
    data = Serial.read();        //Read the incoming data & store into data
    Serial.print(data);          //Print Value inside data in Serial monitor
    Serial.print("\n");        
    if(data=='1'){//adelante
      //analogWrite(ENA, 100);// motor speed  
      digitalWrite(IN1,HIGH);
      digitalWrite(IN2,LOW);
      digitalWrite(IN3,LOW);
      digitalWrite(IN4,HIGH);
    }else if (data=='2'){//atras
     digitalWrite(IN1,LOW);
      digitalWrite(IN2,HIGH);
      digitalWrite(IN3,HIGH);
      digitalWrite(IN4,LOW); 
    }else if (data=='3'){//izquierda
      digitalWrite(IN1,HIGH);
      digitalWrite(IN2,LOW);
      digitalWrite(IN3,LOW);
      digitalWrite(IN4,LOW);
    }else if (data=='4'){//derecha
      digitalWrite(IN1,LOW);
      digitalWrite(IN2,LOW);
      digitalWrite(IN3,LOW);
      digitalWrite(IN4,HIGH);
    }else if (data=='s'){//stop
      digitalWrite(IN1,LOW);
      digitalWrite(IN2,LOW);
      digitalWrite(IN3,LOW);
      digitalWrite(IN4,LOW);
    }
  }
}
