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
  if (ch == 'a' or ch == 'A'){
    dot();
    dash();
    space();
  }
  else if (ch == 'b' or ch == 'B'){
    dash();
    dot();
    dot();
    dot();
    space();
  }
  else if (ch == 'c' or ch == 'C'){
    dash();
    dot();
    dash();
    dot();
    space();
  }
  else if (ch == 'd' or ch == 'D'){
    dash();
    dot();
    dot();
    space();
  }
  else if (ch == 'e' or ch == 'E'){
    dot();
    space();
  }
  else if (ch == 'f' or ch == 'F'){
    dot();
    dot();
    dash();
    dot();
    space();
  }
  else if (ch == 'g' or ch == 'G'){
    dash();
    dash();
    dot();
    space();
  }
  else if (ch == 'h' or ch == 'H'){
    dot();
    dot();
    dot();
    dot();
    space();
  }
  else if (ch == 'i' or ch == 'I'){
    dot();
    dot();
    space();
  }
  else if (ch == 'j' or ch == 'J'){
    dot();
    dash();
    dash();
    dash();
    space();
  }
  else if (ch == 'k' or ch == 'K'){
    dash();
    dot();
    dash();
    space();
  }
  else if (ch == 'l' or ch == 'L'){
    dot();
    dash();
    dot();
    dot();
    space();
  }
  else if (ch == 'm' or ch == 'M'){
    dash();
    dash();
    space();
  }
  else if (ch == 'n' or ch == 'N'){
    dash();
    dot();
    space();
  }
  else if (ch == 'o' or ch == 'O'){
    dash();
    dash();
    dash();
    space();
  }
  else if (ch == 'p' or ch == 'P'){
    dot();
    dash();
    dash();
    dot();
    space();
  }
  else if (ch == 'q' or ch == 'Q'){
    dash();
    dash();
    dot();
    dash();
    space();
  }
  else if (ch == 'r' or ch == 'R'){
    dot();
    dash();
    dot();
    space();
  }
  else if (ch == 's' or ch == 'S'){
    dot();
    dot();
    dot();
    space();
  }
  else if (ch == 't' or ch == 'T'){
    dash();
    space();
  }
  else if (ch == 'u' or ch == 'U'){
    dot();
    dot();
    dash();
    space();
  }
  else if (ch == 'v' or ch == 'V'){
    dot();
    dot();
    dot();
    dash();
    space();
  }
  else if (ch == 'w' or ch == 'W'){
    dot();
    dash();
    dash();
    space();
  }
  else if (ch == 'x' or ch == 'X'){
    dash();
    dot();
    dot();
    dash();
    space();
  }
  else if (ch == 'y' or ch == 'Y'){
    dash();
    dot();
    dash();
    dash();
    space();
  }
  else if (ch == 'z' or ch == 'Z'){
    dash();
    dash();
    dot();
    dot();
    space();
  }
  else if (ch == ' ' ){
    space();
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
