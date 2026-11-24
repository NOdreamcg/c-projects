# 05 拆函数：把 main 里的活分出去

## 题目

把 04 那个程序拆成函数：

```
1. 人数 n 从键盘读，用 malloc 按 n 申请数组（不是写死 5 个）
2. 拆成四个函数，main 里不许有循环体
   void input(struct student *a, int n);
   int  save (struct student *a, int n);   // 成功 1 / 失败 0
   int  load (struct student *a, int n);   // 成功 1 / 失败 0
   void print(struct student *a, int n);
3. 每条失败路径都要 free(list) 再 return
4. 零警告，跑通
```

## 涉及的知识点

- **数组传参退化成指针**：函数里 `sizeof(a)` 得到的是指针大小（8），不是数组大小，
  所以**长度必须单独传 `n`**（错题库 022）
- `a[]` 和 `*a` 在参数表里是**同一回事**，写成 `*a` 更能提醒自己它是指针
- `malloc(n * sizeof(struct student))` + 判 `NULL` + `free`
- **返回值语义**：成功 1 / 失败 0。失败也返回 1，调用方的判断就永远是假的
- **每个退出路径都要善后**：`free` 要写在 `return` 之前
- `break` 和 `return` 只能选一个

## 核心结构

```
main:
    读 n（判 scanf 返回值、判 n > 0）
    malloc（判 NULL）
    input(list, n)
    if (save(list, n) != 1) → free → return 1
    if (load(list, n) != 1) → free → return 1
    print(list, n)
    free(list)
    return 0
```

`main` 里**一行循环都没有**，全靠四个函数干活。

## 踩过的坑

1. **`save` / `load` 写了两遍** —— 一遍裸调用、一遍带判断。`fscanf` 那个更致命：每次读走一条记录
2. **失败也 `return 1`** —— 调用方的 `!= 1` 永远不成立，判断等于没写
3. **`free` 写在 `return` 后面** —— 死代码，永远到不了
4. **`break; return 0;` 两个都写** —— `break` 先执行，`return 0` 成了死代码，读失败还是返回 1
5. **`int n = fscanf(...)` 遮住了参数 `n`** —— 同一个名字两个东西

## 编译与测试

```bash
gcc -Wall -Wextra -o student_file_func student_file_func.c
```

`-Wall -Wextra` 零警告。测过三种情况：

| 输入 | 结果 |
|---|---|
| n=5 + 5 个学生 | 读写一致，5 条全对 |
| n=1 + 1 个学生 | 正确 |
| n=0 | 输出「人数不合法」，不崩 |

**另测过失败路径**：造一个只有 1 条记录、却要读 3 条的 `students.txt`，
函数正确返回 0（改之前返回的是 1）。

## 判据（验收标准）

| # | 判据 | 结果 |
|---|---|---|
| 1 | `main` 里没有循环体，只有调用 | ✓ |
| 2 | 四个函数都在，参数带 `n` | ✓ |
| 3 | `fopen` 判空 + 失败返回 0（含 `load` 读失败） | ✓ |
| 4 | 零警告，跑出来跟之前一致 | ✓ |
| 5 | `malloc` 判了 `NULL`，失败路径都 `free` | ✓ |

## 一句话总结

**编译通过、跑对了，不代表没 bug。**

这一版第一次提交时，零警告、输出全对——但里面藏着"失败返回 1"和"死代码"两个真问题。
