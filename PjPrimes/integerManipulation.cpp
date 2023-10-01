//
//  integerManipulation.cpp
//  PjPrimes
//
//  Created by Jacob Yeung on 9/30/23.
//

#include "integerManipulation.hpp"
//#include "integerManipulation.h"
#include <cmath>

integerManipulation::integerManipulation(long long n){
  this->setNum(n);
        //The default value of num is 0;
      //Postcondition: num = n; revNum = 0; evenscount = 0;
      //    oddsCount = 0; zerosCount = 0;
}

void integerManipulation::setNum(long long n){
  this->num = n;
  this->reverseNum();
  this->classifyDigits();
}

long long integerManipulation::getNum(){
  return this->num;
}

      //Function to reverse the digits of num.
      //Postcondition: revNum is set to num with digits in
      //    in the reverse order.
void integerManipulation::reverseNum(){
    long long temp = abs(this->getNum());
    this->revNum = 0; // Initialize revNum to 0

    while (temp > 0) { // Use temp instead of num
        this->revNum = this->revNum * 10 + temp % 10;
        temp /= 10;
    }

    // Handle the sign of revNum
    this->revNum *= this->getNum() < 0 ? -1 : 1;

    // Handle the case when input number is 0
    if (this->getNum() == 0) {
        this->revNum = 0;
    }
}


void integerManipulation::classifyDigits(){
  this->evensCount = this->getNum()== 0 ? 0 : this->getEvensCount();
  this->oddsCount = this->getNum() == 0? 0 : this->getOddsCount();
  this->zerosCount = this->getNum() == 0? 0 : this->getZerosCount();
}
      //Function to count the even, odd, and zero digits of num.
      //Postcondition: evenCount = the number of even digits in num.
      //      oddCount = the number of odd digits in num.

    int integerManipulation::getEvensCount(){
      this->evensCount = 0;
      long long temp = abs(this->getNum());

    while (temp != 0) {
        int digit = temp % 10; // Get the last digit
        if (digit % 2 == 0) {
            this->evensCount++; // Increment count if the digit is even
        }
        temp /= 10; // Remove the last digit from the number
    }

      return this->evensCount;
    }
      //Function to return the number of even digits in num.
      //Postcondition: The value of evensCount is returned.

    int integerManipulation::getOddsCount(){
           this->oddsCount = 0;
      long long temp = abs(this->getNum());

    while (temp != 0) {
        int digit = temp % 10; // Get the last digit
        if (digit % 2 == 1) {
            this->oddsCount++; // Increment count if the digit is even
        }
        temp /= 10; // Remove the last digit from the number
    }

      return this->oddsCount;
    }
      //Function to return the number of odd digits in num.
      //Postcondition: The value of oddscount is returned.

    int integerManipulation::getZerosCount(){
      this->zerosCount = 0;
      long long temp = abs(this->getNum());

    while (temp != 0) {
        if (temp % 10 == 0) {
            this->zerosCount++;
        }
        temp /= 10;
    }

      return this->zerosCount;
    }
      //Function to return the number of zeros in num.
      //Postcondition: The value of zerosCount is returned.

    int integerManipulation::sumDigits(){
      int sum = 0;
      long long temp = abs(this->getNum());
    
    while (temp != 0) {
        sum += temp % 10; // Add the last digit to the sum
        temp /= 10;      // Remove the last digit from the number
    }
    
      return sum;
    }
      //Function to return the sum of the digits of num.
      //Postcondition: The sum of the digits is returned.

// private:
//     long long num;
//     long long revNum;
//     int evensCount;
//     int oddsCount;
//     int zerosCount;
// }
