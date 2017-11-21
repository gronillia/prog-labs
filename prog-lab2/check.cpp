
/* 
 * File:   functions.cpp
 * Author: illyagron
 *
 * Created on November 2, 2017, 12:08 AM
 */

#include "check.h"

bool s_strassen(long t)
{
    srand((unsigned int) time(nullptr));
    long a;
    for (auto i = 0; i < s_iterations; i++)
    {
        a = rand() % (t - 1) + 1;
        if (gcd(a, t) != 1)
            return false;
        int j = (pow_m(a, (t - 1) / 2, t) + t) % t;
        int J = (jacob_(a, t) + t) % t;
        if (j != J)
            return false;
    }
    return true;
}

bool lehmann(long p)
{
    srand((unsigned int) time(nullptr));
    long a;
    for (auto i = 0; i < l_iterations; i++)
    {
        a = rand() % (p - 1) + 1;
        int j = pow_m(a, (p - 1) / 2, p);
        if (j != 1 && j != p - 1)
            return false;
    }
    return true;
}

bool r_miller(long p)
{
    srand((unsigned int) time(nullptr));
    long m = p - 1, b = 0;
    long a, z;
    while (m % 2 == 0)
    {
        m /= 2;
        b++;
    }
    for (auto i = 0; i < m_iterations; i++)
    {
        int j = 0;
        a = rand() % (p - 1) + 1;
        z = pow_m(a, m, p);        
        if (z != 1 && z != p - 1)
        {
            while ((z != p - 1) && (j++ != b) && (z != 1))
            {
                z = (z * z) % p;
            }
            if (z != p - 1)
                return false;
        }
    }
    return true;
}

long long gcd(long long first, long long second)
{
    if (second == 0)
        return (first);
    else
        return gcd (second, first % second);
}

int jacob_(long first, long second)
{
    if (gcd(first, second) != 1)
        return 0;
    int r = 1;
    if (first < 0)
    {
        first *= -1;
        if (second % 4 == 3)
            r *= -1;
    }
    while (first != 0)
    {
        int t = 0;
        while (first % 2 == 0)
        {
            t++;
            first /= 2;
        }
        if (t % 2 == 1 && (second % 8 == 3 || second % 8 == 5))
            r *= -1;
        if (first % 4 == second % 4 && first % 4 == 3) 
            r *= -1;
        long temp = first;
        first = second % temp;
        second = temp;
    }
    return r;
}

long long ex_gcd(long long a, long long b, long long &x, long long &y)
{
    long long x1 = 0, y1 = 0, d;
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    d = ex_gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

long long inverse_m(long long a, long long mod_)
{
    long long x, y;
    long long g = ex_gcd(a, mod_, x, y);
    return (x + mod_) % mod_;
}


long long pow_m(long long base, long long exponent, long long mod_)
{
    long    result = 1;
    while (exponent > 0) {
        if ((exponent % 2) == 1) 
            result = (result * base) % mod_;
        base = (base * base) % mod_;
        exponent /= 2;
    }
    return result;
}
