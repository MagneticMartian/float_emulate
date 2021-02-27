#include "../include/r_reg.h"

int main()
{
    double x = 8176.609863;
    unsigned long a = get_reg(x);
    printf("The register is stored with: 0x%x\n", a);
    double f = f_point(a);
    printf("The value of the register is: %lf\n", f);
}
