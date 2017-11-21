/* 
 * File:   main.cpp
 * Author: illyagron
 *
 * Created on October 20, 2017, 6:21 PM
 */

#include <iostream>
#include "long_num.h"
#include "long_float.h"
#include "check.h"

using namespace std;



int main() {
    long A = 1934899;
    long_num c ;
    c = long_num(9876765765756765)*long_num(98787698676564535);
    cout << c << endl << long_num::to_decimal(c) << endl;
    return 0;
}