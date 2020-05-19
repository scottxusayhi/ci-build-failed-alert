const int redPin = 9;
const int yellowPin = 10;
const int greenPin = 11;

const String OFF = "off";
const String RED = "red";
const String YELLOW = "yellow";
const String GREEN = "green";

const String C110 = "c110";
const String C101 = "c101";
const String C011 = "c011";
const String C111 = "c111";

//这里就是定义 开和关
void setup()
{
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  Serial.println("Arduino is Ready!");
}
void loop()
{
  if (Serial.available())
  {
    String ans = Serial.readStringUntil('\r');
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
    else if (ans == C110)
    {
      digitalWrite(redPin, HIGH);
      digitalWrite(yellowPin, HIGH);
      digitalWrite(greenPin, LOW);
    }
    else if (ans == C101)
    {
      digitalWrite(redPin, HIGH);
      digitalWrite(yellowPin, LOW);
      digitalWrite(greenPin, HIGH);
    }
    else if (ans == C011)
    {
      digitalWrite(redPin, LOW);
      digitalWrite(yellowPin, HIGH);
      digitalWrite(greenPin, HIGH);
    }
    else if (ans == C111)
    {
      digitalWrite(redPin, HIGH);
      digitalWrite(yellowPin, HIGH);
      digitalWrite(greenPin, HIGH);
    }
    else
    {
      Serial.println("unknown color");
    }
  }
}