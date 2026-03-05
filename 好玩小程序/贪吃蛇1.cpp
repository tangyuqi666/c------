#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define WIDTH 20  // 游戏区域宽度
#define HEIGHT 10 // 游戏区域高度

// 蛇、食物坐标与游戏状态
int snakeX[WIDTH*HEIGHT], snakeY[WIDTH*HEIGHT];
int len = 3;       // 蛇初始长度
int foodX, foodY;  // 食物坐标
int dir;           // 方向：1上 2下 3左 4右
int score = 0;     // 分数
int gameOver = 0;  // 游戏结束标记

// 初始化游戏
void Init() {
    gameOver = 0;
    dir = 4; // 初始向右

    // 蛇初始位置（屏幕中央）
    snakeX[0] = WIDTH/2;
    snakeY[0] = HEIGHT/2;
    for (int i=1; i<len; i++) {
        snakeX[i] = snakeX[0] - i;
        snakeY[i] = snakeY[0];
    }

    // 随机生成食物
    srand((unsigned int)time(NULL));
    foodX = rand()%WIDTH;
    foodY = rand()%HEIGHT;
}

// 绘制游戏界面
void Draw() {
    system("cls"); // 清空控制台

    // 绘制上边界
    for (int i=0; i<WIDTH+2; i++)
        printf("#");
    printf("\n");

    // 绘制左右边界与游戏区域
    for (int i=0; i<HEIGHT; i++) {
        for (int j=0; j<WIDTH; j++) {
            if (j == 0) printf("#"); // 左边界

            // 绘制蛇头
            if (i == snakeY[0] && j == snakeX[0])
                printf("O");
            // 绘制食物
            else if (i == foodY && j == foodX)
                printf("F");
            // 绘制蛇身
            else {
                int isBody = 0;
                for (int k=1; k<len; k++) {
                    if (i == snakeY[k] && j == snakeX[k]) {
                        printf("o");
                        isBody = 1;
                    }
                }
                if (!isBody) printf(" ");
            }

            if (j == WIDTH-1) printf("#"); // 右边界
        }
        printf("\n");
    }

    // 绘制下边界
    for (int i=0; i<WIDTH+2; i++)
        printf("#");
    printf("\n");

    // 显示分数
    printf("分数：%d | 控制：W(上) S(下) A(左) D(右) | Q(退出)\n", score);
}

// 键盘控制
void Control() {
    if (_kbhit()) { // 检测键盘输入
        switch (_getch()) {
            case 'w': if (dir != 2) dir = 1; break;
            case 's': if (dir != 1) dir = 2; break;
            case 'a': if (dir != 4) dir = 3; break;
            case 'd': if (dir != 3) dir = 4; break;
            case 'q': gameOver = 1; break; // 退出游戏
        }
    }
}

// 游戏逻辑更新
void Update() {
    // 蛇身跟随（后一节复制前一节坐标）
    for (int i=len-1; i>0; i--) {
        snakeX[i] = snakeX[i-1];
        snakeY[i] = snakeY[i-1];
    }

    // 蛇头移动
    switch (dir) {
        case 1: snakeY[0]--; break;
        case 2: snakeY[0]++; break;
        case 3: snakeX[0]--; break;
        case 4: snakeX[0]++; break;
    }

    // 撞墙检测
    if (snakeX[0] < 0 || snakeX[0] >= WIDTH ||
        snakeY[0] < 0 || snakeY[0] >= HEIGHT) {
        gameOver = 1;
    }

    // 撞自己检测
    for (int i=1; i<len; i++) {
        if (snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i]) {
            gameOver = 1;
        }
    }

    // 吃食物逻辑
    if (snakeX[0] == foodX && snakeY[0] == foodY) {
        len++;  // 蛇变长
        score += 10; // 加分
        // 重新生成食物（避免出现在蛇身上）
        while (1) {
            int flag = 1;
            foodX = rand()%WIDTH;
            foodY = rand()%HEIGHT;
            for (int i=0; i<len; i++) {
                if (snakeX[i] == foodX && snakeY[i] == foodY) {
                    flag = 0; break;
                }
            }
            if (flag) break;
        }
    }
}

int main() {
    Init();
    while (!gameOver) {
        Draw();
        Control();
        Update();
        Sleep(300); // 控制游戏速度（数值越小越快）
    }
    printf("游戏结束！最终分数：%d\n", score);
    return 0;
}