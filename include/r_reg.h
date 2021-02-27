#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

static const int MAX_REG = 31;
static const int MANT_MAX = 22;

double float_sign(unsigned long);
double exponent(unsigned long);
double mantissa(unsigned long);
double f_point(unsigned long);

unsigned long get_sign(double);
unsigned long get_expon(double);
unsigned long get_mant(double);
unsigned long get_reg(double);
