#include <stdio.h>
#include <math.h>
typedef struct coor{
    int row;
    int col;
}coor;
int i;
int picture[730][730] = {};

//递归 
void printFractal(double n, int size, coor begin, coor end) {
    if((begin.row == end.row && begin.col == end.col)) {
        picture[begin.row][end.col] = 'X';
        return ;
    }
    if(n == 1) {
        return;
    }
    int nextsize = size/3;

    coor nextbegin, nextend;
    nextbegin.row = begin.row;
    nextbegin.col = begin.col;
    nextend.row = end.row - 2*nextsize;
    nextend.col = end.col - 2*nextsize;
    printFractal(n - 1, nextsize, nextbegin, nextend); //左上

    nextbegin.row = begin.row;
    nextbegin.col = begin.col + 2*nextsize;
    nextend.row = end.row - 2*nextsize;
    nextend.col = end.col;
    printFractal(n - 1, nextsize, nextbegin, nextend); //右上

    nextbegin.row = begin.row + nextsize;
    nextbegin.col = begin.col + nextsize;
    nextend.row = end.row - nextsize;
    nextend.col = end.col - nextsize;
    printFractal(n - 1, nextsize, nextbegin, nextend); //中间

    nextbegin.row = begin.row + 2*nextsize;
    nextbegin.col = begin.col;
    nextend.row = end.row;
    nextend.col = end.col - 2*nextsize;
    printFractal(n - 1, nextsize, nextbegin, nextend); //左下

    nextbegin.row = begin.row + 2*nextsize;
    nextbegin.col = begin.col + 2*nextsize;
    nextend.row = end.row;
    nextend.col = end.col;
    printFractal(n - 1, nextsize, nextbegin, nextend); //右下
}

int main() {
    int n;
    scanf("%d", &n);
    int i, j;
    while(n != -1) {
        int row, col;
        row = col = pow(3, n - 1);
        coor begin, end;
        begin.col = 1;
        begin.row = 1;
        end.col = col;
        end.row = row;
        printFractal(n, pow(3, n - 1), begin, end);
        for(i = 1; i <= pow(3, n - 1); ++i) {
            for(j = 1; j <= pow(3, n - 1); ++j) {
                if(picture[i][j] == 0) {
                    putchar(' ');
                } else {
                    putchar(picture[i][j]);
                }
            }
            putchar('\n');
        }
        printf("-\n");
        scanf("%d", &n);
    }
    return 0;
}