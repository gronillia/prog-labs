
/* 
 * File:   long_num.cpp
 * Author: illyagron
 *
 * Created on November 2, 2017, 12:07 AM
 */


#include "long_num.h"
#include "check.h"

long_num::long_num()
{
    digits = vector<int>(1, 0);
    size = 1;
    sign = 0;
}


long_num::long_num(long long num, int base_)
{
    size = 0;
    base = base_;
    if (num == 0)
    {
        digits.push_back(0);
        size = 1;
        sign = 0;
    }
    
    if (num < 0)
        sign = -1;
    
    num *= sign;  
    while (num > 0)
    {
        digits.push_back(num % base);
        num /= base;
        size++;
    }
    
}

long_num::long_num(long long num)
{
    size = 0;
    if (num == 0)
    {
        digits.push_back(0);
        size = 1;
        sign = 0;
    }
    
    if (num < 0)
        sign = -1;
    
    num *= sign;  
    while (num > 0)
    {
        digits.push_back(num % base);
        num /= base;
        size++;
    }
    
}


long long long_num::to_decimal(long_num bin)
{
    long long res = 0;
    vector<int> rdigits(bin.digits.begin(), bin.digits.end());
    for (int i = 0; i < rdigits.size(); ++i)
    {
        if (rdigits[i] == 1)
        {
       long long temp = 1;
       for (int j = 0; j < i; ++j)
           temp *= 2;
       res += temp;
        }
    }
    return res;
}

long_num::long_num(vector<int> Num)
{
    for (int i = 0; i < Num.size(); i++ )
        digits.push_back(Num[i]);
    size = digits.size();
    normalize();
}

long_num::long_num(string Num)
{
    for (int i = Num.size() - 1; i >= 0; i-- )
        digits.push_back((char)Num[i] - '0');
    size = digits.size();
}

int long_num::getsize()
{
    return size;
}

long_num::operator bool()
{
    return sign != 0;
}

long_num::operator long()
{
    long R = 0;
    long currPow = 1;
    for (int i = 0; i < size; i++)
    {
        R += digits[i] * currPow;
        currPow *= base;
    }
    R *= sign;
    return R;
}

long_num::operator string()
{
    string  res;
    for (int i = 0; i < size; i++)
        res += digits[i] + '0';
    if (sign < 0)
        res += '-';
    else
        res += '+';
    reverse(res.begin(), res.end());
    return res;
}

void long_num::normalize()
{
    while (digits.back() == 0 && digits.size() != 1)
    {
        digits.pop_back();
        size--;
    }
}


int long_num::allign(long_num &first, long_num &second)
{
    while (first.digits.size() < second.digits.size())
    {
        first.digits.push_back(0);
        first.size++;
    }
    while (first.digits.size() > second.digits.size())
    {
        second.digits.push_back(0);
        second.size++;
    }
    return first.digits.size();
}

bool long_num::operator==(long_num other)
{
    int  i = 0;
    if (sign != other.sign || size != other.size)
        return false;
    normalize();
    other.normalize();
    while (i < size && digits[i] == other.digits[i])
        i++;
    if (i == size)
        return true;
    return false;
}

bool long_num::operator!=(long_num other)
{
    return !operator==(other);
}

bool long_num::operator<=(long_num other)
{
    int i = 0;
    int a, b;
    if (sign < other.sign || size < other.size)
        return true;
    if (sign > other.sign || size > other.size)
        return false;
    
    for (int j = 0; j < size; j++)
    {
        a = digits[j];
        b = other.digits[j];
    }
    i = allign((*this), other);
    while (i > 0 && (digits[i - 1] * sign) == (other.digits[i - 1] * other.sign))
        i--;
    if ((digits[i - 1] * sign) <= (other.digits[i - 1] * other.sign))
        return true;
    return false;
}

bool long_num::operator <(long_num other)
{
    return operator<=(other) && operator!=(other);
}

bool long_num::operator >(long_num other)
{
    return !operator<=(other);
}

bool long_num::operator >=(long_num other)
{
    return !operator<(other);
}

long_num long_num::operator +(long_num other)
{
    long_num final;
    int width, temp;          
    
    this->normalize();
    other.normalize();
    width = allign(*this, other);
    vector<int>    result(width + 1, 0);
    if (other.sign < 0 && sign < 0)
    {
        final = (-(*this)) + (-other);
        final = -final;
        return final;
    }
    if (-other > (*this) && other.sign < 0)
    {	
        final = (-other) + (-(*this));
        final = -final;
        return final;
    }
    if (-(*this) > other && sign < 0)
	{
		final = (-*this) + (-other);
		final = -final;
		return final;
	}

    for (int i = 0; i < width; i++)
    {
        temp = result[i] + (*this).digits[i] * (*this).sign +
                other.digits[i] * other.sign;
        result[i] = (temp + 2 * base) % base;
        result[i + 1] = (temp + 2 * base) / base - 2;
    }
    
    this->normalize();
    other.normalize();
    final = long_num(result);
    final.normalize();
    return final;
}

long_num long_num::operator +=(long_num other)
{
    (*this) = operator +(other);
    return (*this);
}

long_num long_num::operator -()
{
    long_num  R(*this);
    R.sign *= -1;
    return R;
}

long_num long_num::operator -(long_num other)
{
    return (*this) +(-other);
}

long_num long_num::operator -=(long_num other)
{
    (*this) = operator -(other);
    return (*this);
}

long_num long_num::operator <<(int n)
{
    long_num  me(*this);
    for (int i = 0; sign != 0 && i < n; i++)
    {
        me.digits.insert(me.digits.begin(), 0);
        me.size++; 
    }
    return me;
}

long_num long_num::operator <<= (int n)
{
	*this = *this << n;
	return *this;
}


long_num long_num::operator /(long long n)
{
    vector<long long> Rdigits;
    vector<int> R;
    for (int i = 0; i < size; i++)
        Rdigits.push_back(digits[i]);
    for (int i = Rdigits.size() - 1; i > 0; --i)
    {
        long long temp = Rdigits[i];
        Rdigits[i] /= n;
        Rdigits[i - 1] += base * (temp - n * Rdigits[i]);
    }
    Rdigits[0] /= n;
    for (int i = 0; i < size; i++)
        R.push_back(Rdigits[i]);
    long_num res(R);
    res.normalize();
    return res;
}

long_num long_num::operator /=(long long n)
{
    *this = *this / n;
    return *this;
}

long_num long_num::operator %(long long n)
{
    return (*this - (*this / n) * long_num(n, 2));
}

long_num long_num::operator %=(long long n)
{
    *this = *this % n;
    return *this;
}

long_num long_num::operator *(long_num other)
{
    int width = allign((*this), other);
    if (width == 1)
    {
        int num = digits[0] * other.digits[0];
        num *= ((*this).sign) * (other.sign);
        long_num R(num);
        R.normalize();
        return R;
    }
    if (width % 2 == 1)
    {
        width++;
        digits.push_back(0);
        size++;
        other.digits.push_back(0);
        other.size++;
    }
    
    long_num  U0 (vector<int>(digits.begin(), digits.begin() + width / 2)), 
            U1 (vector<int>(digits.begin() + width / 2, digits.end())), 
            V0 (vector<int>(other.digits.begin(), other.digits.begin() + width / 2)), 
            V1 (vector<int>(other.digits.begin() + width / 2, other.digits.end()));
    long_num  UV1 = U1 * V1,
            UV0 = U0 * V0,
            UU = U1 - U0,
            VV = V0 - V1,
            UV = UU * VV;
    long_num  R1 = (UV1 << width),
            R2 = (UV1 << (width / 2)),
            R3 = (UV << (width / 2)),
            R4 = (UV0 << (width / 2));
    
    long_num  R = R1 + R2 + R3 + R4 + UV0;
    R.sign = (*this).sign * other.sign;
    R.normalize();
    return R;
}


long_num long_num::operator *=(long_num other)
{
    *this = (*this) * other;
    return *this;
}

long_num long_num::Toom_(long_num first, long_num second)
{
    long_num  R;
    long_num  W[5];
    long_num  V[3];
    long_num  U[3];
    int     width;
    first.normalize();
    second.normalize();
    width = allign(first, second);
    while (width % 3 != 0)
    {
        first.digits.push_back(0);
        first.size++;
        second.digits.push_back(0);
        second.size++;
        width++;
    }
    for (int i = 0; i < 3; i++)
    {
        V[i] = long_num(vector<int>(first.digits.begin() + i * (width / 3), 
                first.digits.begin() + (i + 1) * (width / 3)));
        U[i] = long_num(vector<int>(second.digits.begin() + i * (width / 3), 
                second.digits.begin() + (i + 1) * (width / 3)));
    }
    
    for (int i = 0; i < 5; i++)
    {
        W[i] = (V[2] * long_num(i * i) + V[1] * long_num(i) + V[0]) * 
                (U[2] * long_num(i * i) + U[1] * long_num(i) + U[0]);
    }
    
    long_num  temp, last;
    for (int i = 1; i < 5; i++)
    {   
        last = W[i - 1];
        for (int j = i; j < 5; j++)
        {
            temp = W[j];
            W[j] = (W[j] - last) / (long long)i;
            last = temp;
        }
    }
    
    for (int i = 5; i > 1; i--)
      for (int j = i - 1; j < 4; j++)
        {
            W[j] -= long_num(i - 1) * W[j + 1];
        }
    for (int i = 0; i < 5; i++)
        R += W[i] << (i * (width / 3));
    R.normalize();
    return R;
}

long_num long_num::Schoenhage(long_num first, long_num second)
{
    first.normalize();
    second.normalize();
    const int ShonkagePow[mods_] = {-1, 1, 2, 3, 5, 7};
    vector<int> Q = { 1 };
    vector<int> P = { 26 };
    vector<long long> M(mods_, 1);
    vector<vector<long long> > C(mods_, vector<long long>(mods_, 0));
    vector<long_num> F, S, R, _R(mods_);
    long_num result;
    
    int width = allign(first, second);
    int i = 0;
    while (P[i] < width)
    {
        Q.push_back(3 * Q[i] - 1);
        i++;
        P.push_back(18 * Q[i] + 8);
    }
    
    for (int j = 0; j < mods_; j++)
    {
        M[j] <<= (6 * Q[i] + ShonkagePow[j]);
        M[j] -= 1;
    }
    
    for (int k = 0; k < mods_; k++)
    {
        for (int j = 0; j < mods_; j++)
        {
            C[k][j] = inverse_m(M[k], M[j]);
        }
    }
    for (int i = 0; i < mods_; i++)
    {
        F.push_back(first % M[i]);
        S.push_back(second % M[i]);
        R.push_back(F[i] * S[i]);
        R[i] %= M[i];
    }
            

    for (int j = 0; j < mods_; j++)
    {
        _R[j] = R[j];
        for (int i = 0; i < j; i++)
            _R[j] = (_R[j] - _R[i]) * long_num(C[i][j]);
        _R[j] %= M[j];
    }
    result = _R[mods_ - 1];
    for (int i = mods_ - 2; i >= 0; --i)
    {
        result *= long_num(M[i]);
        result += _R[i];
    }
    result.normalize();
    return result;
}

void Furie(vector<complex<double>> & a, bool invert)
{
    int n = (int) a.size();
 
	for (int i=1, j=0; i<n; ++i) {
		int bit = n >> 1;
		for (; j>=bit; bit>>=1)
			j -= bit;
		j += bit;
		if (i < j)
			swap (a[i], a[j]);
	}
 
	for (int len=2; len<=n; len<<=1) {
		double ang = 2*M_PI/len * (invert ? -1 : 1);
		complex<double> wlen (cos(ang), sin(ang));
		for (int i=0; i<n; i+=len) {
			complex<double> w (1);
			for (int j=0; j<len/2; ++j) {
				complex<double> u = a[i+j],  v = a[i+j+len/2] * w;
				a[i+j] = u + v;
				a[i+j+len/2] = u - v;
				w *= wlen;
			}
		}
	}
	if (invert)
		for (int i=0; i<n; ++i)
			a[i] /= n;
}

vector<int> long_num::Strassen(long_num first, long_num second)
{
    first.normalize();
    second.normalize();
    vector<int> a = first.digits, b = first.digits;
    vector<complex<double>> fa(a.rbegin(), a.rend()), fb(b.rbegin(), b.rend());
    int n = 1, k = max(a.size(), b.size());
    while (n < k) n <<= 1;
    n <<= 1;
    fa.resize(n);
    fb.resize(n);
    Furie(fa, false);
    Furie(fb, false);
    for (int i = 0; i < n; ++i)
        fa[i] *= fb[i];
    Furie(fa, true);
    vector<int> R;
    R.resize(n);
    for (int i = 0; i < n; ++i)
        R[i] = int(fa[i].real() + 0.5);
    int carry = 0;
	for (size_t i = 0; i < n; ++i) {
		R[i] += carry;
		carry = R[i] / 10;
		R[i] %= 10;
	}
    reverse(R.begin(), R.end());
    return R;
}

ostream& operator << (ostream& out, long_num N)
{
	out << (string)N;
	return out;
}
