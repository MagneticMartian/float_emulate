#include "../include/r_reg.h"

double float_sign(unsigned long a)
{
    double sign;
    if ((a & 0x80000000) != 0){
        sign = -1.0;
    } else {
        sign = 1.0;
    }  
    return sign;
}

double exponent(unsigned long a)
{
    unsigned long a_e = a & 0x7f800000;
    a_e = a_e >> 23;
    double val = ((double) a_e - 127.0)*log10(2.0);
    return val;
}

double mantissa(unsigned long a)
{
    double mant = 0.0;
    for(int i = 0; i < MAX_REG-8; ++i){
        if ((a & (1 << (MANT_MAX - i))) != 0){
            mant += pow(0.5,i+1);
        } else {
            continue;
        }
    }
    mant += 1.0;
    return mant;
}

double f_point(unsigned long a)
{
    double mant = mantissa(a);
    double expon = exponent(a);
    double sign = float_sign(a);

    double float_val = sign*mant*pow(10,expon);
    if(float_val > FLT_MAX){
        float_val = INFINITY;
    } else if(float_val < FLT_MIN){
        float_val = -INFINITY;
    }
    return float_val;
}
