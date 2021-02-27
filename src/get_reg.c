#include "../include/r_reg.h"

unsigned long get_reg(double x)
{
    float fx = (float) x;
    unsigned long rx = *((unsigned long*) &fx);
    return rx;
}
