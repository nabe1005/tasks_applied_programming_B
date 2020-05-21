// 2020.04.16 課題1-B
// 1B26watanabe.c
// Made by Taiki Watanabe(5SE-26)
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char name[20];
    int math1;
    int math2;
    int sum;
} SCORE;

int compare_score(const void *p, const void *q)
{
    return (((SCORE *)q)->sum - ((SCORE *)p)->sum);
}

int main(void)
{
    FILE *fp;
    char fname[] = "SampleB.txt";
    SCORE data[50] = {0};
    SCORE *sp;
    sp = data;

    // ファイルの読み込みおよびエラー処理
    fp = fopen(fname, "r");

    if (fp == NULL)
    {
        printf("Can't open this file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(fp, "%d\t%s\t%d\t%d", &sp->id, sp->name, &sp->math1, &sp->math2) != EOF)
    {
        sp->sum = sp->math1 + sp->math2;
        // printf("%d %s %d %d %d\n", sp->id, sp->name, sp->math1, sp->math2, sp->sum);
        sp++;
    }

    fclose(fp);

    // 構造体を点数が高い順にソート
    qsort(data, sizeof(data) / sizeof(data[0]), sizeof(SCORE), compare_score);

    // ソート後の1番目から1番高い点数を出力
    sp = data;
    printf("総合点が最も高かったのは、\n");
    while (data->sum == sp->sum)
    {
        printf("出席番号:%d番\t電気電子数学1:%d点\t電気電子数学2:%d点\t合計:%d点\n", sp->id, sp->math1, sp->math2, sp->sum);
        sp++;
    }

    return 0;
}
