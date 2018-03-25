#include <stdio.h>
int judge(long long int num) {
    while(num != 0) {
        if(num % 10 != 0 && num % 10 != 1) {
            return 1;
        }

        num = num / 10;
    }
    return 0;
}

int main() {
    int i;
    long long int num;
    for(i = 1; i <= 200; ++i) {
        long long int k = 2;
        num = i;
        //printf("%d: ", i);
        while(judge(num)) {
            //printf("%lld, ", num);
            num = i*k;
            ++k;
        }
        //printf("k:%lld ", k - 1);
        printf("%lld, \n", num);
    }

}