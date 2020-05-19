const int redPin = 9;
const int yellowPin = 10;
const int greenPin = 11;

const String OFF = "off";
const String RED = "red";
const String YELLOW = "yellow";
const String GREEN = "green";

//这里就是定义 开和关
void setup()
{
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}
void loop()
{
  if (Serial.available())
  {
    String ans = Serial.readString();
    Serial.println(ans);
    if (ans == RED)
    {
      digitalWrite(redPin, HIGH);
      digitalWrite(yellowPin, LOW);
      digitalWrite(greenPin, LOW);
    }
    else if (ans == YELLOW)
    {
      digitalWrite(redPin, LOW);
      digitalWrite(yellowPin, HIGH);
      digitalWrite(greenPin, LOW);
    }
    else if (ans == GREEN)
    {
      digitalWrite(redPin, LOW);
      digitalWrite(yellowPin, LOW);
      digitalWrite(greenPin, HIGH);
    }
    else if (ans == OFF)
    {
      digitalWrite(redPin, LOW);
      digitalWrite(yellowPin, LOW);
      digitalWrite(greenPin, LOW);
    }
    else
    {
      Serial.println("unknown color");
    }
  }
}