//Declaração dos pinos do motor
int E1 = 5;   
int M1 = 4; 
int E2 = 6;                       
int M2 = 7;
char rec;

void setup(){      
  pinMode(M1, OUTPUT);       
  pinMode(M2, OUTPUT); 
  pinMode(E1, OUTPUT);       
  pinMode(E2, OUTPUT); 
  Serial.begin(9600);//Iniciando comunicação Serial
} 

void loop(){ 
  if(Serial.available()){
    rec = Serial.read();
    if(rec == 'F')front();
    if(rec == 'L')left();    
    if(rec == 'R')right();
    if(rec == 'B')back();
    if(rec == 'S')stoprobot();    
  }  
  Serial.flush();
} 

void stoprobot(){
  digitalWrite(E1, LOW);
  digitalWrite(E2, LOW);  
  digitalWrite(M1, LOW);
  digitalWrite(M2, LOW); 
} 

void front(){  
  digitalWrite(E1, HIGH); 
  digitalWrite(M2, HIGH); 
  digitalWrite(E2, HIGH); 
} 

void back(){
  digitalWrite(E2, HIGH); 
  digitalWrite(M1, HIGH); 
  digitalWrite(E1, HIGH); 
}

void left(){  
  digitalWrite(E1, HIGH);     
  digitalWrite(E2, HIGH); 
}

void right(){
  digitalWrite(M1, HIGH); 
  digitalWrite(E1, HIGH);   
  digitalWrite(M2, HIGH);      
  digitalWrite(E2, HIGH); 
}

