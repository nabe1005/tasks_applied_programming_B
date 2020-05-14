// 2020.05.14 課題4-B
// task_4b.c
// Made by Taiki Watanabe(5SE-26)
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define f(x) atan(x - 1)
#define df(x) 1 / (1 + ((x - 1) * (x - 1)))

int main(void)
{
    double const error_threshold = 0.01;
    int count = 0;
    double x_new, x, error = 1;
    x = -1.5;

    while (error > error_threshold)
    {
        count++;
        x_new = x - f(x) / df(x);
        error = fabs(x_new - x);

        printf("【計算回数】%d回\n", count);
        printf("f(x)=%.15lf\n", f(x));
        printf("df(x)=%.15lf\n", df(x));
        printf("x_new=%.15lf\n", x_new);
        printf("error=%.15lf\n\n", error);

        x = x_new;

        if (count == 5)
        {
            printf("打ち切り\nerror=%.15lf\n", error);
            printf("x=%.15lf\n", x);
            exit(EXIT_SUCCESS);
        }
    }

    printf("終了:%d回\n", count);
    printf("x=%.15lf\n", x);

    return 0;
}