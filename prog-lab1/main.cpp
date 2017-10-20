/* 
 * File:   main.cpp
 * Author: illyagron
 *
 * Created on September 20, 2017, 9:52 PM
 */

#include "generators.h"
#include <iostream>

using namespace std;

typedef void (*FP)();

FP arr[] = {&lin_conherent, &quad_conherent, &fib, &inv_conherent, &unif, &sigma, &polar_coord, &correl, &logarithm, &gamma};

int main() {
    int temp = 0;
    while(cin)
    {
        cout << "Choose one of 10 generators" << endl;
        cin >> temp;
        if (cin && (temp >= 1) && (temp <= 10))
            arr[temp - 1]();
        
    }
  return 0;
}

