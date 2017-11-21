
/* 
 * File:   long_float.h
 * Author: illyagron
 *
 * Created on November 2, 2017, 12:08 AM
 */

#ifndef LONG_FLOAT_H
#define LONG_FLOAT_H


#include "long_num.h"

class long_float :public long_num
{
private:
    int decimal_;
        
public:
    long_float(long_num);
    long_float(vector<int>, int);
    operator string();
    void normalize();
    long_float operator + (long_float);
    long_float operator - (long_float);  
    long_float operator * (long_float);
    long_float operator / (long_float);       
    long_float operator << (int);
    long_float operator >> (int);
    long_float inverse(int);
    
    friend class long_num;
    friend ostream& operator << (ostream&, long_float);
    
    ~long_float() = default;
};

#endif /* LONG_FLOAT_H */

