int databin7 = 12;
int databin6 = 11;
int databin5 = 10;
int databin4 = 9;
int databin3 = 8;
int databin2 = 7;
int databin1 = 6;
int databin0 = 5;
int clk      = 2;
int rst      = 13;
int rst_button= 3;
int activate = 0;
int RUN = 0 , S = 1 ,Zout = 0;
long cntr = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(clk, OUTPUT);
  pinMode(rst, OUTPUT);
  pinMode(rst_button, INPUT_PULLUP);
  pinMode(databin7, INPUT);
  pinMode(databin6, INPUT);
  pinMode(databin5, INPUT);
  pinMode(databin4, INPUT);
  pinMode(databin3, INPUT);
  pinMode(databin2, INPUT);
  pinMode(databin1, INPUT);
  pinMode(databin0, INPUT);
  Serial.begin(19200);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(rst_button) == LOW)
  {
    digitalWrite(rst, HIGH);
    RUN = 1;
  }
  if (digitalRead(rst_button) == HIGH)
  {
    digitalWrite(rst, LOW);
  }
  if((RUN == 1) && (S == 1))
  {
    cntr = 0;
    activate = 1;
    S = 0;
  }
  if(activate == 1)
  {
    digitalWrite(clk, HIGH);
    delay(0.1);
    digitalWrite(clk, LOW);
    delay(0.1);
  
  
  int s = 0;
  if (digitalRead(databin7) == HIGH)
  {
    s = s + 128;
  }
  if (digitalRead(databin7) == LOW)
  {
    s = s + 0;
  }


  if (digitalRead(databin6) == HIGH)
  {
    s = s + 64;
  }
  if (digitalRead(databin6) == LOW)
  {
    s = s + 0;
  }


  if (digitalRead(databin5) == HIGH)
  {
    s = s + 32;
  }
  if (digitalRead(databin5) == LOW)
  {
    s = s + 0;
  }


  if (digitalRead(databin4) == HIGH)
  {
    s = s + 16;
  }
  if (digitalRead(databin4) == LOW)
  {
    s = s + 0;
  }


  if (digitalRead(databin3) == HIGH)
  {
    s = s + 8;
  }
  if (digitalRead(databin3) == LOW)
  {
    s = s + 0;
  }


  if (digitalRead(databin2) == HIGH)
  {
    s = s + 4;
  }
  if (digitalRead(databin2) == LOW)
  {
    s = s + 0;
  }


  if (digitalRead(databin1) == HIGH)
  {
    s = s + 2;
  }
  if (digitalRead(databin1) == LOW)
  {
    s = s + 0;
  }


  if (digitalRead(databin0) == HIGH)
  {
    s = s + 1;
  }
  if (digitalRead(databin0) == LOW)
  {
    s = s + 0;
  }

  if(Zout == 0)
    if(s != 0)
      Zout = 1;
  if(Zout == 1)
  {
    Serial.println(s);
    cntr = cntr + 1;
  }
    if(cntr >= 8000)
      Serial.end();
      
  
  }
  //Serial.println(s);
  

}
