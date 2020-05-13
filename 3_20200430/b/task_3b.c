// 2020.04.30 課題3-A
// task_3a.c
// Made by Taiki Watanabe(5SE-26)
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define f(x) (atan(x - 1))

int main(void)
{
    FILE *fp;
    char fname[] = "result.txt";
    long count = 1;
    double x1, x2, temp, error, d;

    fp = fopen(fname, "w");

    if (fp == NULL)
    {
        printf("Can't open this file.");
        exit(EXIT_FAILURE);
    }

    x1 = -0.2, x2 = 1.5;
    error = fabs(x2 - x1);

    fprintf(fp, "反復回数\t区間x1\t区間x2\t中間値M\tf(x1)\tf(x2)\tf(M)\tδ\n");

    while (error > 1e-3)
    {
        temp = (x2 + x1) / 2.0;

        printf("\n【%ld回目】------------------\n", count);
        printf("上側:x1=%15.15lf\tf(x1)=%lf\n", x1, f(x1));
        printf("中央:x3=%15.15lf\tf(x3)=%lf\n", temp, f(temp));
        printf("下側:x2=%15.15lf\tf(x2)=%lf\n", x2, f(x2));

        fprintf(fp, "%ld\t%15.15lf\t%15.15lf\t%15.15lf\t%15.15lf\t%15.15lf\t%15.15lf\t", count, x1, x2, temp, f(x1), f(x2), f(temp));

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
        printf("誤差:error=%15.15lf\n", error);
        fprintf(fp, "%15.15lf\n", error);

        count++;
    }

    fclose(fp);

    printf("\n\n計算終了:%ld回\n", count - 1);
    printf("x1=%15.15lf\n", x1);
    printf("x2=%15.15lf\n", x2);
    printf("誤差:error=%15.15lf\n", error);

    return 0;
}