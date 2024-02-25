// I used this PCB (https://ibb.co/Jkjb45m)


int ROW[] = {6,5,4,3,2};  
int COL[] = {11,10,9,8,7};  
int s1, s2, s3, s4, s5, s6;
  
unsigned char frame1[5][5]=   
{  
  0,0,1,0,0,
  0,1,0,1,0, 
  1,0,0,0,1,
  0,1,0,1,0,  
  0,0,1,0,0,   
};

unsigned char frame2[5][5]=   
{  
  0,0,0,0,0,
  0,1,1,1,0, 
  0,1,0,1,0,
  0,1,1,1,0,  
  0,0,0,0,0,   
};

unsigned char frame3[5][5]=   
{  
  0,0,1,0,0,
  0,1,0,1,0, 
  1,0,0,0,1,
  0,1,0,1,0,  
  0,0,1,0,0,   
};

unsigned char frame4[5][5]=   
{  
  0,0,0,0,0,
  0,1,1,1,0, 
  0,1,0,1,0,
  0,1,1,1,0,  
  0,0,0,0,0,   
};


unsigned char LEFT[5][5]=   
{  
  0,0,1,0,0,
  0,1,0,1,0, 
  1,0,0,0,1,
  0,1,0,1,0,  
  0,0,1,0,0,     
};

unsigned char RIGHT[5][5]=   
{  
  0,1,0,1,0,
  1,0,0,0,1, 
  0,0,0,0,0,
  1,0,0,0,1,  
  0,1,0,1,0,    
};

unsigned char ring1[5][5]=   
{  
  0,0,0,0,0,
  0,0,0,0,0, 
  0,0,1,0,0, 
  0,0,0,0,0,  
  0,0,0,0,0,   
};

unsigned char ring2[5][5]=   
{  
  0,0,0,0,0,
  0,1,1,1,0, 
  0,1,0,1,0, 
  0,1,1,1,0,  
  0,0,0,0,0,   
};  

unsigned char ring3[5][5]=   
{  
  1,1,1,1,1,
  1,0,0,0,1, 
  1,0,0,0,1, 
  1,0,0,0,1,  
  1,1,1,1,1,   
};  


unsigned char EXPAND[5][5]=   
{  
  1,1,1,1,1,
  1,0,0,0,1, 
  1,0,0,0,1,
  1,0,0,0,1,  
  1,1,1,1,1,   
};

unsigned char CONTRACT[5][5]=   
{  
  0,0,0,0,0,
  0,1,1,1,0, 
  0,1,0,1,0,
  0,1,1,1,0,  
  0,0,0,0,0,   
};

unsigned char DIAGONAL[5][5]=   
{  
  0,0,0,0,1,
  0,0,0,1,0, 
  0,0,1,0,0,
  0,1,0,0,0,  
  1,0,0,0,0,   
};

unsigned char DIAGONAL2[5][5]=   
{  
  1,0,0,0,0,
  0,1,0,0,0, 
  0,0,1,0,0,
  0,0,0,1,0,  
  0,0,0,0,1,   
};
void setup()  
{  
   
   Serial.begin(115200);
   pinMode(A0, INPUT); //s1 
   pinMode(A1, INPUT); //s2
   pinMode(A2, INPUT); //s3
   pinMode(A3, INPUT); //s4
   pinMode(A4, INPUT); //s5
   pinMode(A5, INPUT); //s6
   
   for(int i = 0;i<5;i++)  
  
  {  
    pinMode(ROW[i],OUTPUT);  
    pinMode(COL[i],OUTPUT);
  }
}  
  
void loop()  
{ 
  s1=digitalRead(A0);
  //delay(10);
  s2=digitalRead(A1);
  //delay(10);
  s3=digitalRead(A2);
  //delay(10);
  s4=digitalRead(A3);
  //delay(10);
  s5=digitalRead(A4);
  //delay(10);
  s6=digitalRead(A5);
  //delay(10);
  
   if(PINC & B00000001) 
  {
    for(int i = 0 ; i < 60  ; i++){
      Display(frame1);
     
    }
    for(int i = 0 ; i < 60  ; i++){
      Display(frame2);
     
    }
    for(int i = 0 ; i < 60  ; i++){
      Display(frame3);
     
    }
    for(int i = 0 ; i < 60  ; i++){
      Display(frame4);
    
    }
  }


if(PINC & B00000010) 
  {
    Serial.println("--s2--"); 
  for(int i = 0 ; i < 80  ; i++) 
  { 
    Display(LEFT);
    }
    
     for(int i = 0 ; i < 80  ; i++) 
  { 
    Display(RIGHT);
    }
    
}
  
  if(PINC & B00000100) 
  { 
  for(int i = 0 ; i < 80  ; i++) 
  { 
    Display(EXPAND);
    }
   
    for(int i = 0 ; i < 80  ; i++) 
  { 
    Display(CONTRACT);
    }
    
  }
    
  if(PINC & B00001000) 
  { 
  for(int i = 0 ; i < 80  ; i++) 
  { 
    Display(DIAGONAL);
    }
     
     for(int i = 0 ; i < 80  ; i++) 
  { 
    Display(DIAGONAL2);
    }
     
  }

 if(PINC & B00010000) 
  {
    for(int i = 0 ; i < 60  ; i++){
    Display(ring1);
    
    }
    for(int i = 0 ; i < 60  ; i++){
    Display(ring2);
   
    }
    for(int i = 0 ; i < 60  ; i++){
    Display(ring3);
   
    }
  }

  if(PINC & B00100000) 
  {
    for(int i = 0 ; i < 60  ; i++){
    Display(ring3);
    }

    for(int i = 0 ; i < 60  ; i++){
    Display(ring2);
    }

    for(int i = 0 ; i < 60  ; i++){
    Display(ring1);
    }
  }
}
   
void Display(unsigned char  dat[5][5])    
{  
  for(int c = 0; c<5;c++)  
  {  
    digitalWrite(COL[c],LOW);
    for(int r = 0;r<5;r++)  
    {  
      digitalWrite(ROW[r],dat[r][c]);  
    }  
    delay(1);  
    Clear();  
  }  
}
  
void Clear()                       
{  
  for(int i = 0;i<5;i++)  
  {  
    digitalWrite(ROW[i],LOW);  
    digitalWrite(COL[i],HIGH);  
  }  
}
