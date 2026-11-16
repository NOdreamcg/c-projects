/* 优化版：跟 student_sort.c 功能一样，只是把工程习惯补上。
 * 对比着看，能看出「能跑」和「好维护」差在哪。
 */
#include <stdio.h>

#define N 5             /* 学生人数，以后要改就只改这里 */

typedef struct {
    char name[20];
    int  score;
} Student;              /* 给类型起短名，后面不用每次写 struct */

int main(void)
{
    Student a[N], tmp;
    int i, j, k;

    /* 1. 读入 */
    for (k = 0; k < N; k++) {
        printf("第 %d 个学生（姓名 成绩）：", k + 1);
        /* %19s：20 格的数组留一格给 '\0'，防止输入过长时溢出 */
        if (scanf("%19s %d", a[k].name, &a[k].score) != 2) {
            printf("输入格式不对，退出\n");
            return 1;
        }
    }

    /* 2. 冒泡排序，按成绩从高到低 */
    for (i = 0; i < N - 1; i++) {
        for (j = 0; j < N - 1 - i; j++) {
            /* 降序 = 前面比后面小就交换 */
            if (a[j].score < a[j + 1].score) {
                /* 结构体可以整体赋值，三行完成一次完整交换 */
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }

    /* 3. 输出 */
    printf("\n%-10s %s\n", "姓名", "成绩");
    for (k = 0; k < N; k++) {
        printf("%-10s %d\n", a[k].name, a[k].score);
    }

    return 0;
}
