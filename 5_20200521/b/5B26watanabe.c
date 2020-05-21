// 2020.05.21 課題5-B
// 5B26watanabe.c
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
    double s_trapezoid = (f(a) + f(b)) / 2;
    double s_rectangle = f(a);

    for (i = 1; i < N; i++)
    {
        s_trapezoid += f(a + ((double)i * h));
        s_rectangle += f(a + ((double)i * h));
    }
    s_trapezoid *= h;
    s_rectangle *= h;

    printf("tragezoid:N=%d, s=%.15lf, error=%.15lf\n", N, s_trapezoid, fabs(s_trapezoid - S_T));
    printf("rectangle:N=%d, s=%.15lf, error=%.15lf\n", N, s_rectangle, fabs(s_rectangle - S_T));

    return 0;
}