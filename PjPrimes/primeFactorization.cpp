//
//  primeFactorization.cpp
//  PjPrimes
//
//  Created by Jacob Yeung on 9/30/23.
//

//#include "integerManipulation.h"

#include "integerManipulation.hpp"
#include "primeFactorization.hpp"
#include <iostream>
#include <string>
#include <cmath>

primeFactorization::primeFactorization(long long n): integerManipulation(n) {
    long long temp = abs(n);
    this->first125000PrimeNum(this->first125000Primes,
                              temp < 125000 && temp >= 2 ? temp : 125000
                              );
}

void primeFactorization::setNum(long long number){
    integerManipulation::setNum(number);
    long long temp = abs(number);
    this->first125000PrimeNum(this->first125000Primes,
                              temp < 125000 && temp >= 2 ? temp : 125000
                              );
}

void primeFactorization::factorization(){
    bool isPrime = this->isPrime(this->getNum());
    printf("\n%lli %s a prime number. Its factorization is:\n%lli = ",
           this->getNum(),
           (!isPrime)? "is not": "is",
           this->getNum()
           );
    
    if(isPrime){
        printf("%lli\n", this->getNum());
    }else{
        long long temp = abs(this->getNum());
        this->primeFact(this->getNum(), this->first125000Primes,
                        temp < 125000 && temp >= 2 ? temp : 125000,
                        0
                        );
        
        printf("\n");
    }
}

void primeFactorization::primeFact(long long num, long long list[], int length,
                                   int firstPrimeFactIndex){
    if (num != 1 && firstPrimeFactIndex <= length){
        if (num % list[firstPrimeFactIndex] == 0){
            printf("%lli ", list[firstPrimeFactIndex]);
            this->primeFact(num/list[firstPrimeFactIndex], list, length, firstPrimeFactIndex);
        }else{
            this->primeFact(num, list, length, ++firstPrimeFactIndex);
        }
    }
}

void primeFactorization::first125000PrimeNum(long long list[], int length){
    list[0] = 2;
    int listCount = 1;
    long long minRange = 2 + 1;
    long long maxRange = 2 * 2 + 1; // Fixed maxRange initialization
    
    for (long long testnum = minRange; testnum <= maxRange; ++testnum) {
        bool isPrime = true;
        for (int i = 0; i < listCount; ++i) {
            if (testnum % list[i] == 0) {
                isPrime = false;
                break;
            }
        }
        if(!isPrime){
            continue;
        }
        
        list[listCount++] = testnum;
        // std::cout << listCount << ": " << testnum << std::endl;
        
        if (listCount >= length) {
            break; // Break when you have enough primes
        }
        maxRange = testnum * testnum + 1;
    }
}

void primeFactorization::primeTest(long long num, long long list[], int length,
                                   bool& primeNum, int& firstPrimeFactIndex){
    if(list[firstPrimeFactIndex] > 0 &&
       firstPrimeFactIndex <= length
       ){
        if (num % list[firstPrimeFactIndex] == 0){
            primeNum = false; // default true
            return;
        }
        if(list[firstPrimeFactIndex] * list[firstPrimeFactIndex] > num){
            return; // primeNum = true;
        }
            
        this->primeTest(num, list, length, primeNum, ++firstPrimeFactIndex);
    }
}

bool primeFactorization::isPrime(long long number){
    if (abs(number) < 2){
        return false;
    }
    
    bool primeNum = true;// default true
    int index = 0;
    long long temp = abs(this->getNum());
    this->primeTest(abs(number), this->first125000Primes,
                    temp < 125000 && temp >= 2 ? temp : 125000,
                    primeNum,
                    index
                    );
    // correct
//    for(auto prime: this->first125000Primes){
//        if(abs(number) % prime == 0){
//            return false;
//        }
//        if(prime * prime > abs(number)){
//            return true;
//        }
//    }
    return primeNum;
}

