#include <stdio.h>

struct student {
    char name[20];
    int score;
};

int main(void)
{
    struct student list[5];
    int k;

    /* 从键盘录入 5 个学生 */
    for (k = 0; k < 5; k++) {
        scanf("%s %d", list[k].name, &list[k].score);
    }

    /* ---------- 写文件 ---------- */
    FILE *fp = fopen("students.txt", "w");
    if (fp == NULL) {
        printf("打开失败\n");
        return 1;
    }
    for (k = 0; k < 5; k++) {
        fprintf(fp, "%s %d\n", list[k].name, list[k].score);
    }
    fclose(fp);

    /* ---------- 读回来 ---------- */
    FILE *fp2 = fopen("students.txt", "r");
    if (fp2 == NULL) {
        printf("打开失败\n");
        return 1;
    }
    for (k = 0; k < 5; k++) {
        int n = fscanf(fp2, "%s %d", list[k].name, &list[k].score);
        if (n != 2) {
            printf("第 %d 个读取失败\n", k + 1);
            break;
        }
        printf("%s %d\n", list[k].name, list[k].score);
    }
    fclose(fp2);

    return 0;
}
