#include <iostream>
using namespace std;
#define MAXSIZE 34
// F[N, K] = F[N - 1, K] + (F[N - 1, K - 1] - F[N - 1 - m, K - 1])
int F[MAXSIZE][MAXSIZE];
int code[MAXSIZE];

void changeMode(char s[], int k) {
    int i = 0;
    int codenum = 1;
    while(s[i]) {
        if((s[i - 1] == '1' && s[i] == '0' && i - 1 >= 0) || (s[i - 1] == '0' && s[i] == '1' && i - 1 >= 0)) {
            codenum += 1;
        }
        code[codenum] += 1;
        ++i;
    }
    // for(int i = 1; i <= k; ++i) {
    //     cout << code[i];
    // }
    // cout << endl;
}

void clearCode() {
    for(int i = 1; i < MAXSIZE; ++i) {
        code[i] = 0;
    }
}

int findRes(int temp[], int k) {
    int flag = 1;
    for(int i = 1; i <= k; ++i) {
        if(temp[i] != code[i]) {
            flag = 0;
            break;
        }
    }
    return flag;
}

void dp(int n, int k, int m) {
    bool flag = false;
    int find = 0;
    int ans = 0;
    int temp[k + 1];
    for(int i = 0; i <= k; i ++) {
        temp[i] = 0;
    }
    int tempos = 1;
    int ball = 0;
    while(1) {
        if(findRes(temp, k) == 1) {
            cout << ans << endl;
            break;
        }
        for(int i = 1; i < tempos; ++i) {
            ball += code[i];
        }
        //cout << tempos << endl;
        if(flag == false) { //1
            for(int i = 1; i < code[tempos]; ++i) {
                if(n - ball - i >= 0 && k - tempos >= 0) {
                    ans += F[n - ball - i][k - tempos];
                }
            }
            temp[tempos] = code[tempos];
            tempos +=1;
            flag = true; 
        } else if (flag == true) { //0
            for(int i = m; i > code[tempos]; --i) {
                if(n - ball - i >= 0 && k - tempos >= 0) {
                    ans += F[n - ball - i][k - tempos];
                }
            }
            temp[tempos] = code[tempos];
            tempos += 1;
            flag = false;
        }
        ball = 0;
    }
}

int main() {
    int n, k, m;
    cin >> n >> k >> m;
    F[0][0] = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= k; ++j) {
            if(i - 1 - m >=0) {
                F[i][j] = F[i - 1][j] + F[i - 1][j - 1] - F[i - m - 1][j - 1];
            } else {
                F[i][j] = F[i - 1][j] + F[i - 1][j - 1];
            }
        }
    }
    cout << F[n][k] << endl;
    int snum;
    char s[MAXSIZE];
    int i = 0;
    cin >> snum;
    while(i < snum) {
        ++i;
        cin >> s;
        changeMode(s, k);
        dp(n, k, m);
        clearCode();

    }
    return 0;
}