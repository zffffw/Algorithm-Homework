#include <iostream>
#include <string>
#include <iomanip>
#define MAXSIZE 100
using namespace std;
typedef struct board {
    int b[MAXSIZE][MAXSIZE];
} board;

void PrintChessBoard(int size);
board chessboard;
int tile = 0;

void TileBoard(int tr, int tc, int dr, int dc, int size) {
    if(size < 2) {
        return ;
    }
    int s = size/2;
    tile ++;
    int t = tile + 1;
    if (dr < tr + s && dc < tc + s) { // 左下
        TileBoard(tr, tc, dr, dc, s);
    } else {
        chessboard.b[tr + s - 1][tc + s - 1] = t;
        TileBoard(tr, tc, tr + s - 1, tc + s - 1, s);
    }
    if(dr < tr + s && dc >= tc + s) { //右下
        TileBoard(tr, tc + s, dr, dc, s);
    } else {
        chessboard.b[tr + s - 1][tc + s] = t;
        TileBoard(tr, tc + s, tr + s - 1, tc + s, s);
    }
    if(dr >= tr + s && dc >= tc + s) { //右上
        TileBoard(tr + s, tc + s, dr, dc, s);
    } else {
        chessboard.b[tr + s][tc + s] = t;
        TileBoard(tr + s, tc + s, tr + s, tc + s, s);

    }
    if(dr >= tr + s && dc < tc + s) { //左上
        TileBoard(tr + s, tc, dr, dc, s);
    } else {
        chessboard.b[tr + s][tc + s - 1] = t;
        TileBoard(tr + s, tc, tr + s, tc + s - 1, s);
    }

    cout << tr << " " << tc << " " << tr + size - 1 << " " << tc + size - 1 << endl;
    PrintChessBoard(size);

}

void PrintChessBoard(int size) {
    for (int i = size; i >= 1; --i) {
        for(int j = 1; j <= size; ++j) {
            cout << setw(2) << setfill(' ') << chessboard.b[i][j] << ' ';
        }
        cout << '\n';
    }
}


int main() {
    int startx, starty;
    int size;
    cin >> startx >> starty;
    cin >> size;
    chessboard.b[startx][starty] = 99;
    TileBoard(1, 1, startx , starty, size);
    return 0;
}