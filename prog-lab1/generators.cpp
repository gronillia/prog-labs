#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>

using namespace std;

long int    ex_gcd(long a, long b, long &x, long &y)
{
    long x1, y1, d;
    
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

void gystogram(double diff_, double segm, int n, int *occur, int gen_num)
{
    double diff = diff_ / n;
    for (int i = 0; i < n; ++i)
    {
        cout << "[" << segm << ", " << segm + diff << "] "
                << (double)occur[i] / gen_num << endl;
        segm += diff;
    }
}
    

void lin_conherent()
{
    const long m = 115974144000;
    const int a = 85801;
    const int c = 61;
    const int n = 10;
    const int gen_num = 1000000;
    long xn = 41;
    double un = 0;
    
    int occur[n];
    for (int i = 0; i < n; ++i)
        occur[i] = 0;
    
    for (int i = 0; i < gen_num; ++i)
    {
        xn = (a*xn + c) % m;
        un = (double)xn / m;
        ++occur[(int)(un * n)];
    }
    gystogram(1., 0., n, occur, gen_num);
}

void quad_conherent()
{
    const long m = 3088800;
    const long d = 141570;
    const int a = 21451;
    const int c = 61;
    const int n = 10;
    const int gen_num = 1000000;
    long xn = 41;
    double un = 0;
    
    int occur[n];
    for (int i = 0; i < n; ++i)
        occur[i] = 0;
    
    for (int i = 0; i < gen_num; ++i)
    {
        xn = (d*xn*xn + a*xn + c) % m;
        un = (double)xn / m;
        ++occur[(int)(un * n)];
    }
    
    gystogram(1., 0., n, occur, gen_num);
}

void fib()
{
    const long m = 3088800;
    const long d = 141570;
    const int a = 21451;
    const int c = 61;
    const int n = 10;
    const int gen_num = 1000000;
    long xn = 137;
    long xn_ = 39;
    double un = 0;
    long temp = 0;
    
    int occur[n];
    for (int i = 0; i < n; ++i)
        occur[i] = 0;
    
    for (int i = 0; i < gen_num; ++i)
    {
        temp = xn;
        xn = (xn + xn_)%m;
        xn_ = temp;
        un = (double)xn / m;
        ++occur[(int)(un * n)];
    }
    
    gystogram(1., 0., n, occur, gen_num);
}

void inv_conherent()
{
    const long m = 67108864;
    const int a = 251;
    const int c = 62;
    const int n = 10;
    const int gen_num = 1000;
    long xn = 1;
    long x = 0;
    long y = 0;
    double un = 0;
    
    int occur[n];
    for (int i = 0; i < n; ++i)
        occur[i] = 0;
    
    for (int i = 0; i < gen_num; ++i)
    {
        ex_gcd(xn, m, x, y);
        if (x < 0) x = m - x;
        xn = (a*x + c) % m;
        un = (double)xn / m;
        ++occur[(int)(un * n)];
    }
    
    gystogram(1., 0., n, occur, gen_num);
}

void unif()
{
    const long m_ = 115974144000;
    const int a_ = 85801;
    const long m = 3088800;
    const long d = 141570;
    const int a = 21451;
    const int c = 61;
    const int n = 10;
    const int gen_num = 1000000;
    long xn;
    long yn = 41;
    long zn = 41;
    double un = 0;
    
    int occur[n];
    for (int i = 0; i < n; ++i)
        occur[i] = 0;
    
    for (int i = 0; i < gen_num; ++i)
    {
        yn = (a_*yn + c) % m_;
        zn = (d*zn*zn + a*zn + c) % m;
        xn = (yn - zn) % m_;
        un = (double)xn / m_;
        ++occur[(int)(un * n)];
    }
    
    gystogram(1., 0., n, occur, gen_num);
}

void sigma()
{
    const long m = 115974144000;
    const int a = 85801;
    const int c = 61;
    const int n = 10;
    const int gen_num = 1000;
    long xn = 41;
    double yn;
    double sum = 0;
    double un = 0;
    
    int occur[n];
    for (int i = 0; i < n; ++i)
        occur[i] = 0;
    
    for (int i = 0; i < gen_num; ++i)
    {
        sum = 0;
        for (int i = 0; i < 12; ++i)
        {
            un = (double) xn / m;
            sum += un;
            xn = (a*xn + c) % m;
        }
        yn = sum - 6;
        ++occur[static_cast<int>(((yn + 3) / 6) * n)];
    }
    
    gystogram(6., -3., n, occur, gen_num);
}

void polar_coord()
{
    const long m = 115974144000;
    const int a = 85801;
    const int c = 61;
    const int n = 60;
    const int gen_num = 10000;
    long un = 41;
    double v1, v2, s, xn;
    
    int occur[n];
    for (int i = 0; i < n; ++i)
        occur[i] = 0;
    
    for (int i = 0; i < gen_num; ++i)
    {
        do
        {
            un = ((a*un + c) % m);
            v1 = (double) un / m;
            v1 = 2 * v1 - 1;
            un = ((a*un + c) % m);
            v2 = (double) un / m;
            v2 = 2 * v2 - 1;
            s = v1 * v1 + v2 * v2;
        }
        while (s >= 1);
        xn = v1 * sqrt((-2) * log(s) / s);
        if (((xn + 3) / 6) <= 1)
            ++occur[static_cast<int>(((xn + 3) / 6) * n)];
        xn = v2 * sqrt((-2) * log(s) / s);
        if (((xn + 3) / 6) <= 1)
            ++occur[static_cast<int>(((xn + 3) / 6) * n)];
    }
    
    gystogram(6., -3., n, occur, gen_num);
}

void correl()
{
    const long m = 115974144000;
    const int a = 85801;
    const int c = 61;
    const int n = 60;
    const int gen_num = 10000;
    long un = 41;
    double v1, v2, s, xn;
    
    int occur[n];
    for (int i = 0; i < n; ++i)
        occur[i] = 0;
    
    for (int i = 0; i < gen_num; ++i)
    {
        do
        {
            un = ((a*un + c) % m);
            v1 = (double) un / m;
            un = ((a*un + c) % m);
            v2 = (double) un / m;
            xn = sqrt(8/M_E)*(v1 - 0.5)/v2;
        }
        while (xn * xn > -4 * log(v2));
        if (((xn + 3) / 6) <= 1)
            ++occur[static_cast<int>(((xn + 3) / 6) * n)];
    }
    
    gystogram(6., -3., n, occur, gen_num);
}

void logarithm()
{
    const long m = 115974144000;
    const int a = 85801;
    const int c = 61;
    const int n = 100;
    const int gen_num = 10000;
    const double mu = 0.4;
    long un = 41;
    double v1, xn;
    
    int occur[n];
    for (int i = 0; i < n; ++i)
        occur[i] = 0;
    
    for (int i = 0; i < gen_num; ++i)
    {
        un = ((a*un + c) % m);
        v1 = (double) un / m;
        xn = -mu*log(v1);
        if (xn <= 1) ++occur[static_cast<int>(xn * n)];
    }
    
    gystogram(100., 0., n, occur, gen_num);
}

void gamma()
{
    const long m = 115974144000;
    const int a = 85801;
    const int c = 61;
    const int n = 100;
    const int a_ = 13;
    const int gen_num = 10000;
    long un = 41;
    double x, y, u, v;
    double criteria;
    
    int occur[n];
    for (int i = 0; i < n; ++i)
        occur[i] = 0;
    
    for (int i = 0; i < gen_num; ++i)
    {
        x = 0.;
        v = 1.;
        criteria = 0.;
        while ((x <= 0) && (v > criteria))
        {
            un = ((a*un + c) % m);
            u = (double) un / m;
            y = tan(M_PI * u);
            x = sqrt(2*a_ - 1)*y + a_ - 1;
            if (x <= 0)
                continue;
            un = ((a*un + c) % m);
            v = (double) un / m;
            criteria = (1 + y*y)*exp((a_ - 1)*log(x / (a_ - 1) - sqrt(2*a_ - 1)*y));
        }
        if (x <= 100)++occur[static_cast<int>(x)];
    }
    
    gystogram(100., 0., n, occur, gen_num);
}

