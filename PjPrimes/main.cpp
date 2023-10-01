//
//  main.cpp
//  PjPrimes
//
//  Created by Jacob Yeung on 9/29/23.
//

#include <iostream>
#include <string>
#include "primeFactorization.hpp"
#include "integerManipulation.hpp"

using namespace std;

//class PrimeFactorization {
//public:
//    void first125000PrimeNum(long long list[], int length) {
//        list[0] = 2;
//        int listCount = 1;
//        long long minRange = 2 + 1;
//        long long maxRange = 2 * 2 + 1; // Fixed maxRange initialization
//
//        for (long long testnum = minRange; testnum <= maxRange; ++testnum) {
//            bool isPrime = true;
//            for (int i = 0; i < listCount; ++i) {
//                if (testnum % list[i] == 0) {
//                    isPrime = false;
//                    break;
//                }
//            }
//            if(!isPrime){
//                continue;
//            }
//
//            list[listCount++] = testnum;
//            std::cout << listCount << ": " << testnum << endl;
//
//            if (listCount >= length) {
//                break; // Break when you have enough primes
//            }
//            maxRange = testnum * testnum + 1;
//        }
//    }
//};

int main(int argc, const char * argv[]) {

    primeFactorization pf;

    while(true){
        printf("Enter an integer between 2 and 270,000,000,000,000: ");
        long long i;
        cin >> i;
        //long long primes[125000];
            // 1655131 * 1655131 = 2739458627161 ( 2,739,458,627,161 )
        pf.setNum(i);
        //pf.first125000PrimeNum(primes, 125000);
        pf.factorization();

        std::cout << std::endl;
    }
    
    return 0;
};


