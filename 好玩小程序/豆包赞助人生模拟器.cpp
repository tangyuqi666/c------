
//以下是一个更完整的、基于选择分支且包含属性系统的“人生模拟器” C 语言程序，你可以直接编译运行：
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 定义角色属性的结构体
typedef struct {
    int intelligence;  // 智力
    int stamina;       // 体力
    int money;         // 金钱
    int happiness;     // 快乐值
    int charm;         // 魅力值
} Character;

// 函数声明
void childhood(Character *player);
void adolescence(Character *player);
void youth(Character *player);
void middleAge(Character *player);
void oldAge(Character *player);
void randomEvent(Character *player);
void printStatus(Character *player);
void checkEnding(Character *player);

int main() {
    // 初始化随机数种子
    srand((unsigned int)time(NULL));

    Character player = {60, 70, 500, 60, 50};  // 初始属性
    int again = 1;

    while (again == 1) {
        // 重置角色属性（若重新运行）
        player = (Character){60, 70, 500, 60, 50};

        printf("===== 重生之人生模拟器 =====\n");
        printf("你将经历从童年到老年的人生，每一个选择都将影响你的属性！\n");
        printf("按 Enter 键开始你的人生...\n");
        getchar();

        // 人生各阶段
        childhood(&player);
        adolescence(&player);
        youth(&player);
        middleAge(&player);
        oldAge(&player);

        // 人生总结与结局
        printf("\n===== 人生总结 =====\n");
        printStatus(&player);
        checkEnding(&player);

        // 询问是否重新运行
        printf("\n是否重新体验人生？输入 1 重新开始，输入 0 退出：\n");
        scanf("%d", &again);
        getchar();  // 吸收换行符
    }

    printf("感谢体验人生模拟器，再见！\n");
    return 0;
}

// 童年阶段
void childhood(Character *player) {
    int choice;
    printf("\n===== 童年 =====\n");
    printStatus(player);
    printf("童年选择：\n");
    printf("1. 去图书馆看书（智力+10，快乐值-5）\n");
    printf("2. 和小伙伴出去玩（体力+10，快乐值+10，金钱-20，魅力值+5）\n");
    printf("3. 帮家里干活（金钱+30，体力-5，快乐值-10）\n");
    scanf("%d", &choice);
    getchar();

    switch (choice) {
        case 1:
            player->intelligence += 10;
            player->happiness -= 5;
            break;
        case 2:
            player->stamina += 10;
            player->happiness += 10;
            player->money -= 20;
            player->charm += 5;
            break;
        case 3:
            player->money += 30;
            player->stamina -= 5;
            player->happiness -= 10;
            break;
        default:
            printf("选择无效，默认执行选项 1\n");
            player->intelligence += 10;
            player->happiness -= 5;
    }

    // 随机事件
    randomEvent(player);
}

// 少年阶段
void adolescence(Character *player) {
    int choice;
    printf("\n===== 少年 =====\n");
    printStatus(player);
    printf("少年选择：\n");
    printf("1. 努力学习（智力+15，体力-10）\n");
    printf("2. 参加体育活动（体力+15，魅力值+10，智力-5）\n");
    printf("3. 沉迷游戏（智力-10，快乐值+15，金钱-50）\n");
    scanf("%d", &choice);
    getchar();

    switch (choice) {
        case 1:
            player->intelligence += 15;
            player->stamina -= 10;
            break;
        case 2:
            player->stamina += 15;
            player->charm += 10;
            player->intelligence -= 5;
            break;
        case 3:
            player->intelligence -= 10;
            player->happiness += 15;
            player->money -= 50;
            break;
        default:
            printf("选择无效，默认执行选项 1\n");
            player->intelligence += 15;
            player->stamina -= 10;
    }

    // 随机事件
    randomEvent(player);
}

// 青年阶段
void youth(Character *player) {
    int choice;
    printf("\n===== 青年 =====\n");
    printStatus(player);
    printf("青年选择：\n");
    printf("1. 创业（金钱-100，智力+20，体力-15，魅力值+15）\n");
    printf("2. 找稳定工作（金钱+50，智力+5，快乐值-10）\n");
    printf("3. 继续深造（智力+25，金钱-80，快乐值-5）\n");
    scanf("%d", &choice);
    getchar();

    switch (choice) {
        case 1:
            player->money -= 100;
            player->intelligence += 20;
            player->stamina -= 15;
            player->charm += 15;
            break;
        case 2:
            player->money += 50;
            player->intelligence += 5;
            player->happiness -= 10;
            break;
        case 3:
            player->intelligence += 25;
            player->money -= 80;
            player->happiness -= 5;
            break;
        default:
            printf("选择无效，默认执行选项 2\n");
            player->money += 50;
            player->intelligence += 5;
            player->happiness -= 10;
    }

    // 随机事件
    randomEvent(player);
}

// 中年阶段
void middleAge(Character *player) {
    int choice;
    printf("\n===== 中年 =====\n");
    printStatus(player);
    printf("中年选择：\n");
    printf("1. 投入工作晋升（金钱+100，智力+10，快乐值-15）\n");
    printf("2. 享受生活（金钱-80，体力+10，快乐值+20，魅力值+10）\n");
    printf("3. 培养爱好（快乐值+15，智力+5，金钱-30）\n");
    scanf("%d", &choice);
    getchar();

    switch (choice) {
        case 1:
            player->money += 100;
            player->intelligence += 10;
            player->happiness -= 15;
            break;
        case 2:
            player->money -= 80;
            player->stamina += 10;
            player->happiness += 20;
            player->charm += 10;
            break;
        case 3:
            player->happiness += 15;
            player->intelligence += 5;
            player->money -= 30;
            break;
        default:
            printf("选择无效，默认执行选项 2\n");
            player->money -= 80;
            player->stamina += 10;
            player->happiness += 20;
            player->charm += 10;
    }

    // 随机事件
    randomEvent(player);
}

// 老年阶段
void oldAge(Character *player) {
    int choice;
    printf("\n===== 老年 =====\n");
    printStatus(player);
    printf("老年选择：\n");
    printf("1. 参加老年大学（智力+5，快乐值+10，魅力值+5）\n");
    printf("2. 含饴弄孙（快乐值+20，体力-5）\n");
    printf("3. 周游世界（金钱-150，快乐值+25，魅力值+15）\n");
    scanf("%d", &choice);
    getchar();

    switch (choice) {
        case 1:
            player->intelligence += 5;
            player->happiness += 10;
            player->charm += 5;
            break;
        case 2:
            player->happiness += 20;
            player->stamina -= 5;
            break;
        case 3:
            player->money -= 150;
            player->happiness += 25;
            player->charm += 15;
            break;
        default:
            printf("选择无效，默认执行选项 2\n");
            player->happiness += 20;
            player->stamina -= 5;
    }

    // 随机事件
    randomEvent(player);
}

// 随机事件
void randomEvent(Character *player) {
    int event = rand() % 10 + 1;  // 生成 1-10 的随机数

    if (event <= 3) {  // 30% 概率触发随机事件
        printf("\n===== 随机事件 =====\n");
        int subEvent = rand() % 3 + 1;
        switch (subEvent) {
            case 1:
                printf("你在路上捡到了 100 元！（金钱+100）\n");
                player->money += 100;
                break;
            case 2:
                printf("你生了一场小病，身体变虚弱了。（体力-15，快乐值-10）\n");
                player->stamina -= 15;
                player->happiness -= 10;
                break;
            case 3:
                printf("你参加活动获得了表彰，大家都很喜欢你！（魅力值+10，快乐值+10）\n");
                player->charm += 10;
                player->happiness += 10;
                break;
        }
    }
}

// 打印当前属性状态
void printStatus(Character *player) {
    printf("当前属性：智力=%d，体力=%d，金钱=%d，快乐值=%d，魅力值=%d\n",
           player->intelligence, player->stamina, player->money, player->happiness, player->charm);
}

// 检查并输出结局
void checkEnding(Character *player) {
    if (player->happiness >= 80 && player->money >= 800) {
        printf("你度过了幸福且富足的一生，是人生赢家！\n");
    } else if (player->happiness >= 70) {
        printf("你的一生充满快乐，虽然可能不算富有，但精神世界很充实。\n");
    } else if (player->money >= 1000) {
        printf("你积累了大量财富，但似乎缺少了一些快乐。\n");
    } else if (player->intelligence >= 120) {
        printf("你拥有很高的智慧，对世界有深刻的认识。\n");
    } else {
        printf("你的一生普普通通，没有太突出的地方，也没有太多遗憾。\n");
    }
}
/*程序说明
 
1. 属性系统：通过  Character  结构体封装了智力、体力、金钱、快乐值、魅力值五种属性，模拟人生中不同维度的状态。
2. 人生阶段：分为童年、少年、青年、中年、老年五个阶段，每个阶段有 3 种选择，不同选择会改变属性。
3. 随机事件：运行时会随机触发“捡钱”“生病”“获得表彰”等事件，增加游戏的随机性和趣味性。
4. 多结局：根据最终属性（快乐值、金钱、智力等）的不同，输出不同的人生总结结局。
5. 重复运行：程序支持多次体验人生，每次都可重新选择，感受不同人生轨迹。
 
你可以直接编译运行这个程序，开始体验“重生”后的人生选择～*/