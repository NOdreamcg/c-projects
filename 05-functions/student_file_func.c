#include <stdio.h>
#include <stdlib.h>

struct student {
    char name[20];
    int score;
};

/* 从键盘读 n 个学生 */
void input(struct student *a, int n)
{
    int k;
    for (k = 0; k < n; k++) {
        scanf("%s %d", a[k].name, &a[k].score);
    }
}

/* 写进文件；成功返回 1，失败返回 0 */
int save(struct student *a, int n)
{
    FILE *fp = fopen("students.txt", "w");
    int k;

    if (fp == NULL) {
        printf("打开失败\n");
        return 0;
    }
    for (k = 0; k < n; k++) {
        fprintf(fp, "%s %d\n", a[k].name, a[k].score);
    }
    fclose(fp);
    return 1;
}

/* 从文件读回来；成功返回 1，失败返回 0 */
int load(struct student *a, int n)
{
    FILE *fp2 = fopen("students.txt", "r");
    int k;

    if (fp2 == NULL) {
        printf("打开失败\n");
        return 0;
    }
    for (k = 0; k < n; k++) {
        int ret = fscanf(fp2, "%s %d", a[k].name, &a[k].score);
        if (ret != 2) {
            printf("第 %d 个读取失败\n", k + 1);
            fclose(fp2);   /* 先关文件 */
            return 0;      /* 再返回失败 */
        }
    }
    fclose(fp2);
    return 1;
}

void print(struct student *a, int n)
{
    int k;
    for (k = 0; k < n; k++) {
        printf("%s %d\n", a[k].name, a[k].score);
    }
}

int main(void)
{
    struct student *list;
    int n;

    /* 1. 读人数，判合法性（scanf 的返回值也要判） */
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("人数不合法\n");
        return 1;
    }

    /* 2. 按人数申请，判空 */
    list = malloc(n * sizeof(struct student));
    if (list == NULL) {
        printf("内存申请失败\n");
        return 1;
    }

    /* 3. 拆成四步，main 里一行循环都没有 */
    input(list, n);

    if (save(list, n) != 1) {
        printf("处理失败\n");
        free(list);
        return 1;
    }
    if (load(list, n) != 1) {
        printf("处理失败\n");
        free(list);
        return 1;
    }
    print(list, n);

    free(list);
    return 0;
}
