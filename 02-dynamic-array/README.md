# 02 动态数组：边读边扩容

## 题目

人数事先不知道，读到姓名为 `end` 为止。起始只申请 2 个学生的空间，满了就翻倍扩容。

## 涉及的知识点

- `malloc` 申请、`free` 归还
- `realloc` 扩容：**参数是新的总字节数**，返回值才是有效地址
- 三个变量配合：`count`（已存几个）、`capacity`（最多能存几个）、`a`（数据在哪）
- `buf` 临时缓冲：读进来 → 判结束 → 判满扩容 → 再 `strcpy` 存进数组
- `strcmp` 判结束（不能写 `name == "end"`）

## 核心逻辑

```
capacity = 2
a = malloc(capacity * sizeof(Student))
count = 0

循环：
    scanf 名字到 buf
    buf == "end"      → 退出
    count == capacity → capacity *= 2，realloc（用临时指针接返回值）
    strcpy(a[count].name, buf)
    scanf 成绩
    count++

排序 → 输出 → free
```

## 踩过的坑

1. `char name;` —— 应该是 `char name[20]`，`strcmp`/`%s` 都要 `char*`
2. `struct student *tmp;` —— 应该是 `struct student tmp;`，整体赋值要的是值不是指针
3. `int count;` 没初始化 —— 拿垃圾值当下标，靠运气才没崩
4. **先写数组再判满** —— `count == capacity` 时已经越界写了一个
5. 用 `for (count = 0; count < capacity; count++)` 当主循环 —— `count` 一追到 `capacity` 循环就退出，扩容永远不执行
6. 把结束标记和成绩一起 `scanf("%19s %d")` 读 —— 读到 `end` 时 `%d` 会一直等输入

## 编译与测试

```bash
gcc -Wall -Wextra -o dynamic_array dynamic_array.c
```

`-Wall -Wextra` 零警告。测过三种情况：

| 输入 | 结果 |
|---|---|
| 7 个学生 + end | 降序正确 |
| 1 个学生 + end | 正确 |
| 直接 end | 空输出，不崩 |

## 内存路径

```
malloc(2) → 存 2 个 → count==capacity → realloc(4) → 存 2 个
→ realloc(8) → ... → free
```
