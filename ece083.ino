int Red = 2;
int White = 3;
int Green = 4;
int in1=5;
int in2=6;
int en=9;
void setup() {
  Serial.begin(9600);
  pinMode(Green,OUTPUT);
  pinMode(White,OUTPUT);
  pinMode(Red,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(en,OUTPUT);  
}
char c;
String voice;
void loop() {
  if (Serial.available()>0)
  {
    voice="";
    voice=Serial.readString();
    Serial.print(voice+'\n');
  }
  if(voice=="one" || voice=="apoorv")
  {
    digitalWrite(Green,HIGH);
  } else if(voice=="green off" || voice=="green close" || voice=="green of")
  {
    digitalWrite(Green,LOW);
  }
    if(voice=="white" || voice=="white on")
  {
    digitalWrite(White,HIGH);
  } else if(voice=="white off" || voice=="white close" || voice=="white of")
  {
    digitalWrite(White,LOW);
  }
  if(voice=="red" || voice=="red on")
  {
    digitalWrite(Red,HIGH);
  } else if(voice=="red off" || voice=="red close" || voice=="red of")
  {
    digitalWrite(Red,LOW);
  }
  if(voice=="fan on" || voice=="fan" || voice=="switch on fan" )
  {
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    digitalWrite(en,HIGH);
  } 
  else if(voice=="fan off" || voice=="fan close" || voice=="fan of" || voice=="stop fan" || voice=="switch off fan" || voice=="switch of fan")
  {
    digitalWrite(en,LOW);  
}
else if(voice=="fan medium" || voice=="fan at 2" )
{
  analogWrite(en,100);
}
 if(voice=="all off" || voice=="all of")
{
  digitalWrite(Green,LOW);
  digitalWrite(Red,LOW);
  digitalWrite(White,LOW);
  digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
   digitalWrite(en,LOW);
}
else if(voice=="all on")
{
  digitalWrite(Green,HIGH);
  digitalWrite(Red,HIGH);
  digitalWrite(White,HIGH);
  digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
   digitalWrite(en,HIGH);
}
}