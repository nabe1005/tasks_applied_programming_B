#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define f(x) (x * x - 2)
#define df(x) (2 * x)

int main(void)
{
    double const error0 = 0.0001;
    int count = 0;
    double xnew, x, error = 1;
    x = 2.0;

    while (error > error0)
    {
        count++;
        xnew = x - f(x) / df(x);

        printf("計算回数 %d\n", count);
        printf("f(x)=%15.15lf\n", f(x));
        printf("df(x)=%15.15lf\n", df(x));
        printf("新しいx= %15.15lf\n", xnew);
        error = fabs(xnew - x);

        //if(error<0.001) break;

        x = xnew;
    }

    printf("計算回数 %d\n", count);
    printf("新しいx= %15.15lf\n", xnew);
}