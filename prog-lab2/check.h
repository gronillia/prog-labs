

/* 
 * File:   functions.h
 * Author: illyagron
 *
 * Created on November 2, 2017, 12:08 AM
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdlib.h>
#include <ctime>

#define s_iterations   20
#define l_iterations   20
#define m_iterations   20

bool s_strassen(long num);
bool lehmann(long num);
bool r_miller(long num);

long long pow_m(long long, long long, long long);
long long gcd(long long first, long long second);
long long ex_gcd(long long, long long, long long&, long long&);
long long inverse_m(long long, long long);
int jacob_(long first, long second);



#endif /* FUNCTIONS_H */

