const int ledPin = 13;           
const int threshold = 220;       
bool shouldBlink = false;        

void setup() {
  pinMode(ledPin, OUTPUT);      
  Serial.begin(9600);            
}

void loop() {
  int rawBrightness = analogRead(A0);     
  int brightness = map(rawBrightness, 0, 1023, 0, 255);  

  Serial.print("Mapped Brightness Level: ");
  Serial.println(brightness);

  if (brightness >= threshold) {
    shouldBlink = true;         
  }

  if (shouldBlink) {
    digitalWrite(ledPin, HIGH);  
    delay(100);                  
    digitalWrite(ledPin, LOW);   
    delay(100);                  
  }
  
  if (Serial.available() > 0) {
    String input = Serial.readString();  
    input.trim();                        

    
    if (input.equalsIgnoreCase("stop")) {
      shouldBlink = false;
      digitalWrite(ledPin, LOW);         
    }
  }
}