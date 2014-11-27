
void setup()
{
    pinMode(4, OUTPUT);
    pinMode(7, OUTPUT);
}

void loop()
{
    digitalWrite(7, HIGH);
    digitalWrite(4, LOW);
  
    delay(200);
    
    digitalWrite(7, LOW);
    digitalWrite(4, HIGH);
    
    delay(1000);
}

