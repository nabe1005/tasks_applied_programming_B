// 2020.04.30 課題3-A
// task_3a.c
// Made by Taiki Watanabe(5SE-26)
#include <stdio.h>
#include <math.h>

#define f(x) (atan(x - 1))

int main(void)
{
    long count = 1;
    double x1, x2, temp, error, d;

    //初期値設定
    x1 = -0.5, x2 = 1.2;
    error = fabs(x2 - x1);

    //計算開始
    while (error > 1e-3)
    {
        temp = (x2 + x1) / 2.0;

        printf("\n【%ld回目】\n", count);
        printf("x1=%15.15lf\tf(x1)=%lf\n", x1, f(x1));
        printf("x3=%15.15lf\tf(x3)=%lf\n", temp, f(temp));
        printf("x2=%15.15lf\tf(x2)=%lf\n", x2, f(x2));

        d = f(temp) * f(x2);

        if (d < 0)
        {
            x1 = temp;
        }
        else
        {
            x2 = temp;
        }

        error = fabs(x2 - x1);
        printf("error=%lf\n", error);

        count++;
    }

    printf("\n\n計算終了:%ld回\n", count - 1);
    printf("x1=%15.15lf\n", x1);
    printf("x2=%15.15lf\n", x2);
    printf("error=%lf\n", error);

    return 0;
}