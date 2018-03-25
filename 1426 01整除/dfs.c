#include <stdio.h>
#include <time.h>
//递归
int n;
int flag;
int Random(int start, int end){
    srand((unsigned)time(NULL));
    int dis = end - start;
    return rand() % dis + start;
}
void dfs(unsigned long long int start, int num) {
    //printf("%lld\n", start);
    if(num == 19 || flag) {
        return ;
    }
    if(start % n == 0 ) {
        putchar('\"');
        printf("%lld", start);
        putchar('\"');
        putchar(',');
        putchar('\n');
        flag = 1;
    }
    int a;
    a = Random(1, 10000);
    if(a >= 5000) {
        dfs(start * 10 , num+ 1);
        dfs(start * 10 + 1, num + 1);
    } else if (a < 5000) {
        dfs(start * 10 + 1, num + 1);
        dfs(start * 10 , num+ 1);
    }
}

int main() {
    // scanf("%d", &n);
    // while(n != 0) {
    //     flag = 0;
    //     dfs(1, 0);
    //     scanf("%d", &n);
    // }
    for(int i = 1; i <= 200; ++i) {
        n = i;
        dfs(1, 0);
        flag = 0;
    }
}