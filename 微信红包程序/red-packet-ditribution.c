#include <stdio.h>
#include <stdlib.h>
#define MONEY 0 //MONEY表示对应红包类型的金额
#define SUM 1  //SUM表示对应数额红包的个数
#define MAXMONEYTYPE 10 //最大幸运红包的种类数

/*
 *输入幸运红包的种类数以及金额数
 */

int inputLuckyPocket(float pocket[][MAXMONEYTYPE]) {
    int amount_pocket; //红包种类数
    printf("请输入幸运红包的种类总数:");
    scanf("%d", &amount_pocket);
    printf("请输入幸运红包的具体面额, 以空格隔开:");
    for (int i = 0; i < amount_pocket; ++i) {
        scanf("%f", &pocket[MONEY][i]);
    }
    return amount_pocket;
}


void PrintPocket(int amount_pocket, float pocket[][MAXMONEYTYPE]) {
    int i = 0;
    while(i < amount_pocket) {
        printf("%f \n", pocket[MONEY][i]);
        ++i;
    }
}

/*判断是否满足条件*/
int IsContent(int amount_people, float amount_money, int amount_pocket, float pocket[][MAXMONEYTYPE]) {
    float sum_money = 0; //当前红包的总额
    int pocket_num = 0; //当前红包个数
    for (int i = 0; i < amount_pocket; ++i) {
        sum_money += pocket[MONEY][i] * pocket[SUM][i];
        pocket_num += pocket[SUM][i];
    }
    if(sum_money == amount_money && pocket_num == amount_people) { //amount_money 实际所需的红包总额  amount_people 实际所需的红包个数
        return 1;
    } else {
        return 0;
    }
}
void PrintResult(int amount_pocket, float pocket[][MAXMONEYTYPE]) {
    printf("-----------------------------\n");
    for(int i = 0; i < amount_pocket; ++i) {
        printf("红包金额:%.2f,  个数: %1.0f\n", pocket[MONEY][i], pocket[SUM][i]);
    }
    printf("-----------------------------\n\n");
}

/*
 *递归穷举寻找合适的红包配额
 *amount_people 总人数
 *amount_money 总钱数
 *amount_pocket 红包类型总数
 *type_pocket 当前递归层所处的红包类型序号
 */
int existRes = 0; //是否有结果的标志

int GetOneResOfNumber(int amount_people, float amount_money, int amount_pocket, float pocket[][MAXMONEYTYPE], int type_pocket) {
    if(type_pocket > amount_pocket) {
        return 0;
    }
    int flag = 0;
    for(int i = 0; i <= amount_people; ++i) {
        pocket[SUM][type_pocket - 1] = i;
        type_pocket += 1;
        if(IsContent(amount_people, amount_money, amount_pocket, pocket)) {
            existRes = 1;
            PrintResult(amount_pocket, pocket);
            return 1;
        }
        flag = GetOneResOfNumber(amount_people, amount_money, amount_pocket, pocket, type_pocket);
        if(flag) {
            return 1;
        }
        type_pocket -= 1;
    }
    pocket[SUM][type_pocket - 1] = 0;
    return 0;
}

/*寻找所有可能的结果*/
int GetAllResOfNumber(int amount_people, float amount_money, int amount_pocket, float pocket[][MAXMONEYTYPE], int type_pocket) {
    static int count = 0;
    if(type_pocket > amount_pocket) {
        return 0;
    }
    int flag = 0;
    for(int i = 0; i <= amount_people; ++i) {
        pocket[SUM][type_pocket - 1] = i;
        type_pocket += 1;
        if(IsContent(amount_people, amount_money, amount_pocket, pocket)) {
            count++;
            existRes = 1;
            PrintResult(amount_pocket, pocket);
        }
        flag = GetAllResOfNumber(amount_people, amount_money, amount_pocket, pocket, type_pocket);
        type_pocket -= 1;
    }
    pocket[SUM][type_pocket - 1] = 0;
    return 0;
}


// int GetResult_Complex(int amount_people, float amount_money, int amount_pocket, float pocket[][MAXMONEYTYPE], int type_pocket) {
//     int pocket_num = 0;
//     // if(IsContent(amount_people, amount_money, amount_pocket, pocket)) {
//     //     return 1;
//     // }
//     int flag = 0;
//     if(flag = IsContent(amount_people, amount_money, amount_pocket, pocket)) {
//         return 1;
//     }
//     for (int i = 1; i <= amount_people; ++i) {
//         if(flag) {
//             return 1;
//         } 
//         pocket[SUM][type_pocket] = i;
//         // if(flag = IsContent(amount_people, amount_money, amount_pocket, pocket)) {
//         //     return 1;
//         // }
//         for(int i = 0; i < amount_pocket; ++i) {
//             pocket_num += pocket[SUM][i];
//         }
//         type_pocket += 1;
//         if(pocket_num > amount_pocket) {
//             pocket[SUM][type_pocket] = 0;
//             return 0;
//         } else if(type_pocket > amount_pocket) {
//             return 0;
//         }
//         //printf("typenum:%d pocketnum:%d iscont:%d\n", type_pocket, pocket_num, flag);
//         PrintResult(amount_pocket, pocket);

//         flag = GetResult_Complex(amount_people, amount_money, amount_pocket, pocket, type_pocket);
//         type_pocket -= 1;
//     }
//     pocket[SUM][type_pocket] = 0;
// }



int main() {
    float amount_money;
    int amount_pocket;
    float pocket[2][MAXMONEYTYPE] = {};
    int amount_people;
    int res = 0;
    int choose = 0;
    printf("---------------------------\n请输入总人数:");
    scanf("%d", &amount_people);
    printf("请输入红包的总额:");
    scanf("%f", &amount_money);

    amount_pocket = inputLuckyPocket(pocket);

    printf("请选择[找到所有结果:输入1,  找到一个结果:输入0]\n");
    scanf("%d", &choose);
    if(choose == 0) {
        GetOneResOfNumber(amount_people, amount_money, amount_pocket, pocket, 1);
    } else {
        GetAllResOfNumber(amount_people, amount_money, amount_pocket, pocket, 1);
    }
    if(!existRes) {
        printf("找不到!\n");
    }
    return 0;
}