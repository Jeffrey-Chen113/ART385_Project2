//Morse Code Machine
//By Jeffrey Chen

//Set the variables for the outputs
const int rled = 12;
const int gled = 27;
const int bled = 33;
const int sound = 32;

//Variables for the compiler
String input = "";
int len = 0;
char ch;

//Initializes the outputs
void setup() {
  Serial.begin(9600);
  pinMode(rled, OUTPUT);
  pinMode(bled, OUTPUT);
  pinMode(gled, OUTPUT);
  pinMode(sound, OUTPUT);
}

void loop() {
  //While loop prevents the loop from continuuing unless an input is recieved
  while (Serial.available()){
    //Gets an input from the Serial
    input = Serial.readString();
    Serial.print("Generating Morse: ");
    loopThrough();
    Serial.println("");
  }
  delay(1000);
}

//This is to show a dot on the Serial and the LED/Sound unit
void dot()
{
Serial.print(".");
digitalWrite(rled, HIGH);
digitalWrite(sound, HIGH);
delay(100);
digitalWrite(rled, LOW);
digitalWrite(sound, LOW);
delay(100);
}

//This is to show a dash on the Serial and the LED/Sound unit
void dash()
{
Serial.print("-");
digitalWrite(bled, HIGH);
digitalWrite(sound, HIGH);
delay(300);
digitalWrite(bled, LOW);
digitalWrite(sound, LOW);
delay(100);
}

//This is to show a space on the Serial and the LED unit
void space()
{
Serial.print(" ");
digitalWrite(gled, HIGH);
delay(100);
digitalWrite(gled, LOW);
delay(100);
}

//Decodes the input
void pattern(){
  if (ch == '1'){
    dot();
  }
  else if (ch== '2' ){
    dash();
  }
  else if (ch== '3' ){
    space();
  }
}

//Uses for loop to go through input and calls appropriate methods (dot,dash,space)
void loopThrough(){
  len = input.length();
  for (int i = 0; i < len; i++){
    ch = input.charAt(i);
    pattern();
  }
}
