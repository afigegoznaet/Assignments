#include <stdio.h>
#include <stdlib.h>
#include <math.h>



#define EXPONENT_BITS 4
#define FRACTION_BITS 5


int
computeFP(float val) {
// input: float value to be represented
// output: integer version in our representation
//
// Perform this the same way we did in class -
//    either dividing or multiplying the value by 2
//    until it is in the correct range (between 1 and 2).
//    Your exponent is the number of times this operation
//    was performed.   
// Deal with rounding by simply truncating the number.
// Check for overflow - 
//    with 4 exponent bits, we have overflow if the number to be 
//       stored is > 14 or < 1
//    return -1 if overflow occurs

   return 0;
}

float getFP(int val) {
// Using the defined representation, compute the floating point
//    value
// For denormalized values other than 0, simply return 0.
// For special values, return 0;

  return 0.0;
}

int
addVals(int source1, int source2) {
// Do this function last - it is the most difficult!
// You must implement this as described in class:
//     If needed, adjust one of the two number so that 
//        they have the same exponent E
//     Add the two fractional parts:  F1' + F2 = F
//              (assumes F1' is the adjusted F1)
//     Adjust the sum F and E so that F is in the correct range
//     
// As described in the handout, you only need to implement this for
//    positive, normalized numbers
// Also, return -1 if the sum overflows
//
   return 0;

}

int
multVals(int source1, int source2) {
// You must implement this by using the algorithm
//    described in class:
//    Add the exponents:  E = E1+E2 
//    multiply the fractional values: M = M1*M2
//    if M too large, divide it by 2 and increment E
//    set the sign bit:  S = S1^S2 
//    save the result
// Be sure to check for overflow - return -1 in this case


   return 0;
    
}

