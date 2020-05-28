// 2020.05.28 課題6-B
// 6B26watanabe.c
// Made by Taiki Watanabe(5SE-26)
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI M_PI
#define f(birthday, student, x) ((4 * (student) / (birthday)) * sqrt(pow(birthday, 2) - (x) * (x)))

int main(void)
{
    int n = 0;
    double const birthday = 11, student = 26;
    double const a = 0, b = birthday, s_true = PI * birthday * student;
    double y[200], h, error = 1;
    double s;
    int i = 0;

    while (error > 0.1)
    {
        n++;
        h = (b - a) / (2 * n);
        s = f(birthday, student, a) + f(birthday, student, b);
        for (i = 0; i <= 2 * n; i++)
        {
            y[i] = f(birthday, student, a + i * h);
            // printf("[%d] x = %lf, y = %lf\n", i, (a + i * h), y[i]);
        }

        for (i = 1; i <= n; i++)
        {
            s += 4 * y[2 * i - 1] + 2 * y[2 * i];
        }
        s -= 2 * y[2 * n];
        s *= h / 3;
        error = fabs(s - s_true);

        printf("[ N = %d ] s_simpson = %.15lf, s_true = %.15lf, error = %.15lf\n", n, s, s_true, error);
    }

    printf("\n[finish] N = %d, s_simpson = %.15lf, s_true = %.15lf, error = %.15lf\n", n, s, s_true, error);
    printf("Matched up to the 1st decimal place.");

    return 0;
}