## 主要内容

- 开始界面（开始、继续、退出、排行榜、帮助）

- 游戏本体

  金矿、石头、背景、计分、计时

  文件、音乐、商店（拉取速度增加，积分增加，石头价值增加，钩子变大）

- 菜单（暂停、继续、保存游戏、读取游戏、金手指、帮助）及其配套快捷键

- 双人内容



## 结构类型

矿物结构及其链表

```c
typedef enum{  //矿物类型
    GOLD,
    STONE,
    DIAMOND
} rockType;

typedef enum{  //矿物大小
    SMALL,
    MEDIUM,
    LARGE
} rockSize;

typedef struct{
    double x, y;  //用于表示矿物位置
    rockSize size;  //用于表示矿物大小
    rockType type;  //用于表示矿物类型
} block;

typedef struct linkBlock{
    void* element;
    struct linkBlock* next, *prev;
} linkBlock;
```

玩家存档结构

```c
typedef struct{
    int level;
    int score;
    int money;
    int grades[4];  //储存四项能力的等级（分别是拉取速度增加，积分增加，石头价值增加，钩子变大）
} player;
```

## TODO

- file.c输入用户名登录排行榜的内容
