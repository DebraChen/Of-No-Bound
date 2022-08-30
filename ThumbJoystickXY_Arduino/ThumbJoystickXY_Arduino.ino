
//char inChar;
const int analogInA0X = A0;
const int analogInA1Y = A1;

int X_Value = 0;
int Y_Value = 0;

float averageXValue = 0.0;
float averageYValue = 0.0;

int MeasurementsToAverage = 32;

String combineXY; 


void setup() 
{

  pinMode(12, OUTPUT); //this is our LED pin
  digitalWrite(12, LOW); //default off
  Serial.begin(19200);
}

void loop() 
{ 

//
  X_Value = analogRead(analogInA0X); //reading X
  Y_Value = analogRead(analogInA1Y); //reading Y

 
  Average(X_Value,averageXValue); //custom function to filter data and reduce stuttering
  Average(Y_Value,averageYValue);
  combineXY = String(map(averageXValue,0,700,100,200))+ String(map(averageYValue,0,700,100,200));//Then in the unreal I can easily devide the value into X and Y part.
  Serial.println(combineXY);
  
//  Serial.println(combineXY.toFloat()); //printing X+Y value to the serial

//  while(Serial.available()) //checking for received messages on serial
//  { 
//    inChar = Serial.read();
//    toggleLight(); //custom function for turning on/off light - but this could be anything!
//  }

 
}

//void toggleLight(){
//  if (inChar == '1') //if we receive the character "1"....
//  {
//    Serial.println("On");
//    digitalWrite(12, HIGH);//... turn the LED on
//  }
//
//  else if (inChar == '0') //if we receive the character "0"....
//  {
//    Serial.println("Off");
//    digitalWrite(12, LOW); //turn the light off
//  }
//}


void Average(int input, float & averageVal)
{
  
  for(int i = 0; i < MeasurementsToAverage; ++i)
  {
    averageVal += input;
    delay(1);//may be delay after--
  }
  averageVal /= MeasurementsToAverage;
}
