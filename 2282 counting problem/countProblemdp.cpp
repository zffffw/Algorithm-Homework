#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include<string>
#include<sstream>
using namespace std;
string itos(int i) {// 将int 转换成string
    stringstream s;
    s << i;
    return s.str();
}
using namespace std;

int bit[10] ={1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};

int getMax(int a, int b) {
    return a>b?a:b;
}

int getMin(int a, int b) {
    return a<b?a:b;
}

long getRes(int num, int digit) {
    int times;
    int ans = 0;
    int m;
    for(int i = 1; i < 9; ++i) {
        if(digit == 0) {
            times = num / bit[i] - 1;
        } else {
            times = num / bit[i];
        }
        ans += times * bit[i - 1];
        m = (num % bit[i] - num % bit[i - 1])/bit[i - 1];
        if(m > digit) {
            ans += bit[i - 1];
        } else if(m == digit) {
            ans += num % bit[i - 1] + 1;
        }
        if(num < bit[i]) {
            break;
        }
    }
    return ans;
}

int main() {
    int num_head, num_tail;
    cin >> num_head >> num_tail;
    while(num_head && num_tail) {
        int max, min;
        max = getMax(num_head, num_tail);
        min = getMin(num_head, num_tail);
        int resmax = 0;
        int resmin = 0;
        for(int i = 0; i <= 9; ++i) {
            resmax = getRes(max, i);
            resmin = getRes(min - 1, i);
            char str[10];                        
            cout << resmax - resmin << ' ';
        }
        cout << endl;
        cin >> num_head >> num_tail;
    }
}