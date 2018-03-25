#include <stdio.h>

int main() {
    long long int x, y, m, n, L;
    scanf("%lld %lld %lld %lld %lld", &x, &y, &m, &n, &L);
    int flag = 0;
    long long int xstart, ystart;
    xstart = x;
    ystart = y;
    long long int stepnum = 0;
    while(x != y) {
        x = (x + m) % L;
        y = (y + n) % L;
        stepnum += 1;
        if(x == xstart && y == ystart) {
            flag = 0;
            break;
        }
    }
    if(x == y) {
        flag = 1;
    }
    if(!flag) {
        printf("Impossible\n");
    } else {
        printf("%lld\n", stepnum);
    }
    return 0;
}