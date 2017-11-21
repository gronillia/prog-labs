
/* 
 * File:   long_float.cpp
 * Author: illyagron
 *
 * Created on November 2, 2017, 12:08 AM
 */

#include "long_float.h"

long_float::long_float(long_num N)
{
    N.normalize();
    base = N.base;
    digits = N.digits;
    sign = N.sign;
    decimal_ = 0;
}

long_float::long_float(vector<int> num_, int _decimal)
{
    decimal_ = _decimal;
    while (num_[0] == 0 && decimal_ > 0)
    {
        num_.erase(num_.begin());
        decimal_--;
    }
    while (num_.size() > decimal_ + 1 && num_[num_.size() - 1] == 0)
    {
        num_.pop_back();
        size--;
    }
    digits = num_;
    size = num_.size();
    sign = 1;
    if (size == 1 && num_[0] == 0)
        sign = 0;
    
            
}

long_float long_float::operator + (long_float other)
{
    int width = max(other.decimal_, decimal_);
    long_num temp1 = long_num((*this << width).digits); 
    long_num temp2 = long_num((other << width).digits);
    long_float A = long_float(temp1 + temp2);
    A.decimal_ = width;
    return A;
}

long_float long_float::operator - (long_float other)
{
    int width = max(other.decimal_, decimal_);
    long_num temp1 = long_num((*this << width).digits); 
    long_num temp2 = long_num((other << width).digits);
    long_float A = long_float(temp1 - temp2);
    A.decimal_ = width;
    A.normalize();
    return A;
}

long_float long_float::operator * (long_float other)
{
    int width = max(other.decimal_, decimal_);
    long_num temp1 = long_num((*this << width).digits); 
    long_num temp2 = long_num((other << width).digits);
    long_float A = long_float(temp1 * temp2);
    A.decimal_ = 2 * width;
    A.normalize();
    return A;
}

long_float long_float::operator / (long_float R)
{   
    int width = R.size - R.decimal_;
    long_float A = *this >> width;
    long_float B = R >> width;
    return A * B.inverse(A.decimal_ + B.decimal_);
}

long_float long_float::operator << (int n)
{
    long_float me = *this;
    int p = decimal_;
    p -= n;
    while (p < 0)
    {
        me.digits.insert(me.digits.begin(), 0);
        ++p;
    }
    me.normalize();
    return me;
}

long_float long_float::operator >> (int n)
{
  long_float me(*this);
  me.decimal_ += n;
  while (me.digits.size() < me.decimal_)
    me.digits.push_back(0);
    me.size = me.digits.size();
  return me;
}


long_float   long_float::inverse(int param)
{
    long_float me = *this;
    while (me.decimal_ < 3)
    {
        me.digits.insert(me.digits.begin(), 0);
        ++me.decimal_;
    }
    long_float Z(8 / (4 * me.digits[me.decimal_ - 1] + 
                    2 * me.digits[me.decimal_ - 2] + 
                        me.digits[me.decimal_ - 3]));
    int k = 1;
    while (k < param)
    {
        long_float temp = Z * Z;
        while (me.size < 2 * k + 3)
        {
            me.digits.push_back(0);
            ++me.size;
        }
        vector<int> v(me.digits.begin(), me.digits.end());
        long_float V(v, me.decimal_);
        Z = long_float(Z << 1) - V * temp;
        while ((Z.decimal_ > k + 1) && (Z.digits[0] == 1))
        {
            Z = Z + long_float({ 1 }, decimal_);
            Z.digits.erase(Z.digits.begin());
            Z.decimal_--;
        }
        
        k <<= 1;
    }
    return Z;
}

long_float::operator string()
{
    long_float me = *this;
    string res = "";
    
    me.normalize();
    for (int i = 0; i < me.size; i++)
    {
        if (i == me.decimal_)
            res += '.';
        res += (char)(me.digits[i]) + '0';
    }
    if (sign == -1)
        res += '-';
    else
        res += "+";
    reverse(res.begin(), res.end());
    return res;
}

void long_float::normalize()
{
    while (size < decimal_ + 1)
    {
        size++;
        digits.push_back(0);
    }
    while (digits.size() > decimal_ + 1 && digits.back() == 0)
    {
        digits.pop_back();
        size--;
    }
    while (digits[0] == 0)
    {
        digits.erase(digits.begin());
        --decimal_;
        --size;
    }
}

ostream& operator << (ostream& out, long_float r_)
{ 
    out << (string)r_;
    return out;
}