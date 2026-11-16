# Git 与 GitHub 速查

写给刚开始用的自己。忘了就回来翻这一页。

---

## 一、两个东西的区别

| | Git | GitHub |
|---|---|---|
| 是什么 | 装在你电脑上的**版本管理工具** | 网上的**代码托管网站** |
| 干什么 | 记录每次改动，能回退、能看历史 | 把代码放到网上，别人能看，你自己换电脑也能拉回来 |
| 类比 | 相机的存储卡 | 云相册 |

**没有 GitHub，Git 也能用；但没有 Git，GitHub 用不了。**

---

## 二、五个核心概念

### 1. 仓库（repository / repo）

一个文件夹，被 Git 管起来了。你的 `c-projects` 就是一个仓库。

### 2. 提交（commit）

**一次存档。** 每次 commit 都会留一条记录：谁、什么时候、改了什么。

```
60e1b8a  初始提交：struct-sort 学生成绩排序 + 项目台账
```

**commit 不是自动的**，是你自己决定「这一刻值得存一份」。

### 3. 分支（branch）

平行的版本线。默认那条叫 `main`。

```bash
git branch              # 看有哪些分支
git checkout -b dev     # 新建并切到 dev 分支
git checkout main       # 切回 main
```

**一个人做小项目，只用一个 `main` 就够了。**

### 4. 远程（remote）

网上那份仓库的地址，一般叫 `origin`。

```bash
git remote -v           # 看远程地址
```

### 5. 工作区 / 暂存区 / 仓库

```
你改的文件（工作区）
    ↓ git add          把改动"放进待提交清单"
暂存区
    ↓ git commit       真正存档
本地仓库
    ↓ git push         传到网上
GitHub
```

---

## 三、日常就这四条命令

```bash
git status                    # 看现在改了哪些文件（最常用）
git add -A                    # 把所有改动加入待提交
git commit -m "说明做了什么"   # 存档
git push                      # 传到 GitHub
```

**改完代码 → 这四条 → 完事。**

---

## 四、看历史、回退

```bash
git log --oneline            # 提交历史（一行一条）
git diff                     # 还没 add 的改动具体是什么
git show 60e1b8a             # 看某次提交改了什么
```

**改坏了想回到上一次提交：**

```bash
git checkout -- 文件名        # 丢弃这个文件没提交的改动（小心，找不回）
git reset --hard HEAD         # 丢弃所有未提交改动（更小心）
```

---

## 五、网页上常用的几个功能

| 位置 | 作用 |
|---|---|
| **README.md** | 仓库首页显示的内容，等于项目说明书。**别人进来第一眼看的就是它** |
| **Commits** | 提交历史，能看出你什么时候在干活 |
| **Issues** | 记问题、记待办（给自己的项目用也行） |
| **Star** | 收藏别人的仓库 |
| **Fork** | 把别人的仓库复制一份到自己名下 |
| **Pin** | 在个人主页置顶仓库——**简历上放链接时，人家会点进主页看** |
| **Settings** | 改仓库名、删仓库、开 Pages |

---

## 六、新手最容易犯的四个错

### 1. 把密码、密钥传上去

**Public 仓库全世界都能看。** 传了 API key、密码、身份证号，等于公开。

`.gitignore` 就是干这个的，写进去的文件不会被提交。

### 2. commit 说明写成「更新」「修改」

三个月后自己都看不懂。写清楚：

```
❌ git commit -m "修改"
✅ git commit -m "02 动态数组：用 malloc 按输入人数申请结构体数组"
```

### 3. 传了不该传的大文件

视频、安装包、编译产物（`.exe`）不要传。仓库超过 100MB 会推不上去。

### 4. 忘了先 add 就 commit

`commit` 只提交**暂存区**里的东西。改完不 `add`，commit 出来是空的。

---

## 七、我自己的仓库

```
https://github.com/NOdreamcg/c-projects

本地位置：C:\Users\1\Downloads\DSH练习\c-projects
```

日常流程：

```powershell
cd C:\Users\1\Downloads\DSH练习\c-projects
git status
git add -A
git commit -m "做了什么"
git push
```

凭据已经存在系统里，不用每次登录。

---

## 八、以后可能会用到的

- **GitHub Pages**：把仓库变成一个网页（`设置 → Pages`），免费
- **GitHub Student Pack**：学生认证后有免费额度
- **Actions**：自动跑测试（现在还早）
- **Pull Request**：给别人仓库提交改动（以后参与开源用）

---

**一句话总结：`add` → `commit` → `push`，剩下的都是锦上添花。**
