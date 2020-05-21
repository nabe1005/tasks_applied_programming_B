// 2020.04.16 課題1-A
// 1A26watanabe.c
// Made by Taiki Watanabe(5SE-26)
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI M_PI
#define f(a, t) (exp(-(a) * (t)) * sin((t)*PI))

int main(void)
{
    FILE *fp;
    char fname[] = "result.txt";
    double t = 0;

    fp = fopen(fname, "w");

    if (fp == NULL)
    {
        printf("Can't open this file\n");
        exit(EXIT_FAILURE);
    }

    for (t = 0; t <= 15; t += 0.25)
    {
        fprintf(fp, "%.2lf\t%lf\n", t, f(2.7, t));
        printf("%.2lf\t%lf\n", t, f(2.7, t));
    }

    fclose(fp);
    return 0;
}
