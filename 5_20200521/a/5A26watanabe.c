// 2020.05.21 課題5-A
// 5A26watanabe.c
// Made by Taiki Watanabe(5SE-26)
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI M_PI
#define f(x) (sin(2 * PI * (x)) + 1.5)

int main(void)
{
    int const N = 4;
    double const S_T = 1.30997;
    double const a = 0, b = 0.8;
    double h = (b - a) / (double)N;
    int i;
    double s = (f(a) + f(b)) / 2;

    for (i = 1; i < N; i++)
    {
        s += f(a + ((double)i * h));
    }
    s *= h;

    printf("N=%d, s=%.15lf, error=%.15lf", N, s, fabs(s - S_T));

    return 0;
}