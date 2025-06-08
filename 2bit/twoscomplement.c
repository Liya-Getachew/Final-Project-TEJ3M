// Created by: Liya Getachew
// Created on: June 7th 2025
//
// This is the code for a 2-bit twos complement adder.

const int DIGIT_A1 = 13;
const int DIGIT_A2 = 12;
const int DIGIT_B1 = 11;
const int DIGIT_B2 = 10;
const int DELAY_TIME = 4000;

void setup()
{
  // setup serial output
  Serial.begin(9600);
  // set pin mode to output
  pinMode(DIGIT_A1, OUTPUT);
  pinMode(DIGIT_A2, OUTPUT);
  pinMode(DIGIT_B1, OUTPUT);
  pinMode(DIGIT_B2, OUTPUT);
  
  // set all pins to "0"
  digitalWrite(DIGIT_A1, 0); //LOW and HIGH just reference 0 & 1
  digitalWrite(DIGIT_A2, 0); 
  digitalWrite(DIGIT_B1, 0); 
  digitalWrite(DIGIT_B2, 0);
  
  // loop over the inputs
  Serial.print("Starting ... \n\n");
  delay(1000); // Wait for 1000 millisecond(s)

  // loop through all two bit combinations from 00 to 11 for A
  for (int twosA = 0; twosA <= 1; twosA = twosA + 1) {
    digitalWrite(DIGIT_A2, twosA);
    for (int onesA = 0; onesA <= 1; ++onesA) {
      digitalWrite(DIGIT_A1, onesA);
      
      // loop through all two bit combinations from 00 to 11 for B
      for (int twosB = 0; twosB <= 1; twosB = twosB +1) {
        digitalWrite(DIGIT_B2, twosB);
        for (int onesB = 0; onesB <= 1; ++onesB) {
          digitalWrite(DIGIT_B1, onesB);
          
          // changes digit A & B from binary to integers
          int aValue = (twosA * 2) + onesA;
          int bValue = (twosB * 2) + onesB;
          
          // makes sure the digit values are between 1 to -2 (highest and lowest possible values using 2-bit twos complement adders)
          if (aValue >= 2) {
              aValue -= 4;
          }
        
          if (bValue >= 2) {
              bValue -= 4;
          }
          
          Serial.print("A value = " + String(twosA) + String(onesA) + "\n");
          Serial.print("B value = " + String(twosB) + String(onesB) + "\n");
          Serial.print(String(aValue) + " + " + String(bValue) + " = " + String(aValue + bValue) + "\n\n");
          delay(DELAY_TIME); // Wait for 2000 millisecond(s)
        }
      }
    }
  }
}

void loop()
{
  // Done
  Serial.print("\nDone. \n");
  delay(10000); // Wait for 10000 millisecond(s)
}
