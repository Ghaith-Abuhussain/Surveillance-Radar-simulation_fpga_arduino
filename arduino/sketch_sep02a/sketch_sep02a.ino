int databin15 = 37;
int databin14 = 36;
int databin13 = 35;
int databin12 = 34;
int databin11 = 33;
int databin10 = 32;
int databin9 = 31;
int databin8 = 30;
int databin7 = 29;
int databin6 = 28;
int databin5 = 27;
int databin4 = 26;
int databin3 = 25;
int databin2 = 24;
int databin1 = 23;
int databin0 = 22;
int clk      = 40;
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
  pinMode(databin15, INPUT);
  pinMode(databin14, INPUT);
  pinMode(databin13, INPUT);
  pinMode(databin12, INPUT);
  pinMode(databin11, INPUT);
  pinMode(databin10, INPUT);
  pinMode(databin9, INPUT);
  pinMode(databin8, INPUT);
  pinMode(databin7, INPUT);
  pinMode(databin6, INPUT);
  pinMode(databin5, INPUT);
  pinMode(databin4, INPUT);
  pinMode(databin3, INPUT);
  pinMode(databin2, INPUT);
  pinMode(databin1, INPUT);
  pinMode(databin0, INPUT);
  Serial.begin(115200);

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
    delay(0.001);
    digitalWrite(clk, LOW);
    delay(0.001);
  
  
  long s = 0;
  if (digitalRead(databin15) == HIGH)
  {
    s = s + 32768;
  }
  if (digitalRead(databin15) == LOW)
  {
    s = s + 0;
  }


  if (digitalRead(databin14) == HIGH)
  {
    s = s + 16384;
  }
  if (digitalRead(databin14) == LOW)
  {
    s = s + 0;
  }


  if (digitalRead(databin13) == HIGH)
  {
    s = s + 8192;
  }
  if (digitalRead(databin13) == LOW)
  {
    s = s + 0;
  }


  if (digitalRead(databin12) == HIGH)
  {
    s = s + 4096;
  }
  if (digitalRead(databin12) == LOW)
  {
    s = s + 0;
  }


  if (digitalRead(databin11) == HIGH)
  {
    s = s + 2048;
  }
  if (digitalRead(databin11) == LOW)
  {
    s = s + 0;
  }


  if (digitalRead(databin10) == HIGH)
  {
    s = s + 1024;
  }
  if (digitalRead(databin10) == LOW)
  {
    s = s + 0;
  }


  if (digitalRead(databin9) == HIGH)
  {
    s = s + 512;
  }
  if (digitalRead(databin9) == LOW)
  {
    s = s + 0;
  }


  if (digitalRead(databin8) == HIGH)
  {
    s = s + 256;
  }
  if (digitalRead(databin8) == LOW)
  {
    s = s + 0;
  }


  
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
    if(cntr >= 65408)
      Serial.end();
      
  
  }
  //Serial.println(s);
  

}
