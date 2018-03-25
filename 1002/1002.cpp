#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <map>
using namespace std;

map<int, int> teledict;

int _types = 0;
char getNum(char c);
void AddAppearTimes(string s);
void Judge(string s);


char getNum(char c) {
    if (c >= 'A' && c <= 'C') {
        return '2';
    } else if (c >= 'D' && c <= 'F') {
        return '3';
    } else if (c >= 'G' && c <= 'I') {
        return '4';
    } else if (c >= 'J' && c <= 'L') {
        return '5';
    } else if (c >= 'M' && c <= 'O') {
        return '6';
    } else if (c >= 'P' && c <= 'S') {
        return '7';
    } else if (c >= 'T' && c <= 'V') {
        return '8';
    } else if (c >= 'W' && c <= 'Y') {
        return '9';
    } else if (c >= '0' && c <= '9') {
        return c;
    } else {
        return '-';
    }
}



void AddAppearTimes(string s) {
    int i = 0;
    int sum = 0;
    int digit = 1000000;
    for(int i = 0; i < 7; ++i) {
        sum += (s[i] - '0') * digit;
        digit /= 10;
    }
    teledict[sum] += 1;
}

void Judge(char *s) {
    int i = 0;
    char num;
    while(s[i]) {
        num = getNum(s[i]);
        if(num != '-') {
            s[i] = num;
            ++i;
        } else {
            int j;
            for(j = i; s[j] != 0; j ++) {
                s[j] = s[j + 1];
            }
            s[j - 1] = 0;
        }
    }
    AddAppearTimes(s);
}

int main() {
    int N;
    cin >> N;
    int i = 0;
    char s[31];
    while (i < N) {
        cin >> s;
        Judge(s);
        ++i;
        for(int i = 0; s[i]; ++i) {
            s[i] = 0;
        }
    }
    int flag = 0;
    i = _types - 1;
    map<int, int>::iterator it;
    it = teledict.begin();
    while(it != teledict.end()) {
        if(it->second > 1) {
            flag = 1;
            cout << setw(3) << setfill('0') << it->first/10000 << '-' << setw(4) << setfill('0') << (it->first - it->first/10000*10000) << " " << it->second << endl;
        }
        it ++;
    }
    if(!flag) {
        puts("No duplicates.\n");
    }
    return 0;
}
