#include <iostream> 
using namespace std;

int getMax(int a, int b) {
    return a>b?a:b;
}

int getMin(int a, int b) {
    return a<b?a:b;
}

void countDigit(int num, long long  hash[]) {
    int digitNum = 0;
    while(num != 0) {
        digitNum = num % 10;
        hash[digitNum] += 1;
        num /= 10;
    }
}


int main() {
    long long hash[10] = {};
    int num_head, num_tail;
    int i;
    cin >> num_head >> num_tail;
    while(num_head && num_tail) {
        int max, min;
        max = getMax(num_head, num_tail);
        min = getMin(num_head, num_tail);
        for(i = min; i <= max; ++i) {
            countDigit(i, hash);
        }
        cin >> num_head >> num_tail;
        for(i = 0; i < 10; ++i) {
            cout << hash[i] << ' ';
            hash[i] = 0;
        }
        cout << endl;
    }
}