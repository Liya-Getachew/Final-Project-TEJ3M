// Created by: Liya Getachew
// Created on: June 7th 2025
//
// This is the code for a 4-bit twos complement adder/subtractor.

const int DIGIT_A1 = 13;
const int DIGIT_A2 = 12;
const int DIGIT_B1 = 11;
const int DIGIT_B2 = 10;
const int DIGIT_A3 = 9;
const int DIGIT_B3 = 8;
const int DIGIT_A4 = 7;
const int DIGIT_B4 = 6;
const int SUBTRACTION = 5;

const int DELAY_TIME = 7000;

void setup()
{
  // setup serial output
  Serial.begin(9600);
  // set pin mode to output
  pinMode(DIGIT_A1, OUTPUT);
  pinMode(DIGIT_A2, OUTPUT);
  pinMode(DIGIT_A3, OUTPUT);
  pinMode(DIGIT_A4, OUTPUT);
  pinMode(DIGIT_B1, OUTPUT);
  pinMode(DIGIT_B2, OUTPUT);
  pinMode(DIGIT_B3, OUTPUT);
  pinMode(DIGIT_B4, OUTPUT);
  pinMode(SUBTRACTION, OUTPUT);
  
  // set all pins to "0"
  digitalWrite(DIGIT_A1, 0); //LOW and HIGH just reference 0 & 1
  digitalWrite(DIGIT_A2, 0);
  digitalWrite(DIGIT_A3, 0);
  digitalWrite(DIGIT_A4, 0);
  digitalWrite(DIGIT_B1, 0); 
  digitalWrite(DIGIT_B2, 0);
  digitalWrite(DIGIT_B3, 0);
  digitalWrite(DIGIT_B4, 0);
  digitalWrite(SUBTRACTION, 0);
  
  // loop over the inputs
  Serial.print("Starting ... \n\n");
  delay(1000); // Wait for 1000 millisecond(s)

  // once all addition equations are complete, loop through all subtraction equations
  for (int subtraction_state = 0; subtraction_state <= 1; subtraction_state = subtraction_state + 1) {
    digitalWrite(SUBTRACTION, subtraction_state);

        // loop through all three bit combinations from 0000 to 1111 for the A value
    for (int foursA = 0; foursA <= 1; ++foursA) {
      digitalWrite(DIGIT_A4, foursA);

      // loop through all three bit combinations from 0000 to 1111 for the A value
      for (int threesA = 0; threesA <= 1; ++threesA) {
        digitalWrite(DIGIT_A3, threesA);

        for (int twosA = 0; twosA <= 1; ++twosA) {
          digitalWrite(DIGIT_A2, twosA);

          for (int onesA = 0; onesA <= 1; ++onesA) {
            digitalWrite(DIGIT_A1, onesA);

            for (int foursB = 0; foursB <= 1; ++foursB) {
              // loop through all three bit combinations from 000 to 111 for the B value
              for (int threesB = 0; threesB <= 1; threesB) {
                digitalWrite(DIGIT_B3, threesB);
                for (int twosB = 0; twosB <= 1; twosB = twosB +1) {
                  digitalWrite(DIGIT_B2, twosB);
                  for (int onesB = 0; onesB <= 1; ++onesB) {
                    digitalWrite(DIGIT_B1, onesB);
                
                      // changes digits A & B from binary to integers
                      int aValue =  (foursA * 8) + (threesA * 4) + (twosA * 2) + onesA;
                      int bValue =  (foursB * 8) + (threesB * 4) + (twosB * 2) + onesB;

                        // makes sure the digit values are between 3 to -4 (highest and lowest possible values using 3-bit twos complement adders)
                      if (aValue >= 4) {
                        aValue -= 8;
                      }

                      if (bValue >= 4) {
                        bValue -= 8;
                      }

                      if (subtraction_state < 1){
                        Serial.print("A value = " + String(foursA) + String(threesA) + String(twosA) + String(onesA) + "\n");
                        Serial.print("B value = " + String(foursB) + String(threesB) + String(twosB) + String(onesB) + "\n");
                        Serial.print(String(aValue) + " + " + String(bValue) + " = " + String(aValue - bValue) + "\n\n");
                        delay(DELAY_TIME); // Wait for 2000 millisecond(s)
                      }
              
                      else {
                        Serial.print("A value = " + String(foursA) + String(threesA) + String(twosA) + String(onesA) + "\n");
                        Serial.print("B value = " + String(foursB) + String(threesB) + String(twosB) + String(onesB) + "\n");
                        Serial.print(String(aValue) + " - " + String(bValue) + " = " + String(aValue - bValue) + "\n\n");
                        delay(DELAY_TIME); // Wait for 2000 millisecond(s)
                    }
                  }
                }
              }
            }
          }
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