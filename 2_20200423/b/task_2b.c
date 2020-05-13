// 2020.04.16 課題2-B
// task_2b.c
// Made by Taiki Watanabe(5SE-26)
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI M_PI
#define EP0 8.854187817e-12
#define PART_OF_V(molecule, l) (molecule / (4 * PI * EP0 * l))

int main(void)
{
    FILE *fp;
    char fname[] = "result.txt";

    // Q1:内球の電荷, Q2:外球の電荷
    // a:内球の半径, b:外球の内径, c:外球の外径
    double q1 = 5e-10, q2 = 1e-10;
    double a = 0.1, b = 0.4, c = 0.5, r = 0, v = 0;

    fp = fopen(fname, "w");

    if (fp == NULL)
    {
        printf("Can't open this file");
        exit(EXIT_FAILURE);
    }

    for (r = 0; r < 1.01; r += 0.01)
    {
        if (r <= a)
        {
            v = PART_OF_V(q1, a) + PART_OF_V(-q1, b) + PART_OF_V((q1 + q2), c);
        }
        else if (r > a && r <= b)
        {
            v = PART_OF_V(q1, r) + PART_OF_V(-q1, b) + PART_OF_V((q1 + q2), c);
        }
        else if (r > b && r <= c)
        {
            v = PART_OF_V((q1 + q2), c);
        }
        else
        {
            v = PART_OF_V((q1 + q2), r);
        }

        fprintf(fp, "%lf\t%.10lf\n", r, v);
        printf("%lf\t%.10lf\n", r, v);
    }

    return 0;
}