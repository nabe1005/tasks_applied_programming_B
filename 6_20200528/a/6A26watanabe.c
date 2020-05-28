// 2020.05.28 課題6-A
// 6A26watanabe.c
// Made by Taiki Watanabe(5SE-26)
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI M_PI
#define f(x) (4 / (1 + (x) * (x)))

int main(void)
{
    int const N = 10;
    double const a = 0, b = 1;
    double const h = (b - a) / (2 * N);
    double y[21];
    double s = f(a) + f(b);
    int i = 0;

    for (i = 0; i <= 2 * N; i++)
    {
        y[i] = f(a + i * h);
        printf("[%d] x = %lf, y = %lf\n", i, (a + i * h), y[i]);
    }

    for (i = 1; i <= N; i++)
    {
        s += 4 * y[2 * i - 1] + 2 * y[2 * i];
    }
    s -= 2 * y[2 * N];
    s *= h / 3;

    printf("\n[finish] s_simpson = %.15lf, s_true = %.15lf, error = %.15lf\n", s, PI, fabs(s - PI));
    printf("Matched up to the %.0lfth decimal place.", -1 * ceil(log10(fabs(s - PI))));

    return 0;
}