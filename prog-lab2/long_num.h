/* 
 * File:   long_numbers.h
 * Author: illyagron
 *
 * Created on October 20, 2017, 6:40 PM
 */
#ifndef LONG_NUMBERS_H
#define LONG_NUMBERS_H

#define mods_ 6

#include <iostream>
#include <string>
#include <vector>
#include <complex>
#include <cmath>
#include <algorithm>

using namespace std;

class   long_num {
public:
    long_num();
    long_num(long long, int);
    long_num(long long);
    long_num(string);
    
    
    long_num(vector<int>);
    bool operator <(long_num);
    bool operator >(long_num);
    bool operator <=(long_num);
    bool operator >=(long_num);
    bool operator ==(long_num);
    bool operator !=(long_num);
    long_num operator +(long_num);
    long_num operator +=(long_num);
    long_num operator -();
    long_num operator -(long_num);
    long_num operator -=(long_num);
    long_num operator *(long_num);
    long_num operator *=(long_num);
    long_num operator /(long long);
    long_num operator /=(long long);
    long_num operator %(long long);
    long_num operator %=(long long);
    long_num operator <<(int n); //* 2^n
    long_num operator <<=(int n);
    operator string();
    operator bool(); //is not 0 
    operator long(); //decimal conversion
            
    static long long to_decimal(long_num bin);
    
    static long_num Toom_(long_num, long_num);
    static long_num Schoenhage(long_num, long_num);
    static vector<int> Strassen(long_num, long_num);
    void normalize();
    friend class long_float;
    friend ostream& operator << (ostream&, long_num);
    static int allign(long_num &first, long_num &second);
    int getsize();
    
    ~long_num() = default;
        
protected:
    vector<int> digits;
    int         size;
    int         sign = 1;
    int         base = 2;
};

#endif 

