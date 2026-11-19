#include <stdio.h>

static void indent(int d)
{
    int i;
    for (i = 0; i < d; i++) printf("    ");
}

void hanoi(int n, char from, char via, char to, int depth)
{
    indent(depth); printf("进入 hanoi(%d, %c, %c, %c)\n", n, from, via, to);

    if (n == 1) {
        indent(depth); printf("  >>> 搬 %c -> %c\n", from, to);
    } else {
        hanoi(n - 1, from, to, via, depth + 1);
        indent(depth); printf("  >>> 搬 %c -> %c\n", from, to);
        hanoi(n - 1, via, from, to, depth + 1);
    }

    indent(depth); printf("离开 hanoi(%d)\n", n);
}

int main(void)
{
    printf("==== n = 2 ====\n");
    hanoi(2, 'A', 'B', 'C', 0);
    printf("\n==== n = 3 ====\n");
    hanoi(3, 'A', 'B', 'C', 0);
    return 0;
}
