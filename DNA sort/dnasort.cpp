#include<algorithm>
#include<iostream>
#define MAXDNALENGTH 52
#define MAXLINES 101
#define A 1
#define C 2
#define G 3
#define T 4
using namespace std;
//算法复杂度 n
//排序复杂度 n^2
typedef struct dna{
    char s[MAXDNALENGTH];
    int count;
    int pos[5];
}DNA;

DNA d[MAXLINES];

int getval(char s) {
    if(s == 'A') {
        return A;
    } else if (s == 'C') {
        return C;
    } else if (s == 'G') {
        return G;
    } else if (s == 'T') {
        return T;
    } else {
        return 0;
    }
}

bool comparation(const DNA a, const DNA b) {
    return a.count < b.count;
}

void update( int val, int i, int j) {
    if(val == A) {
        d[i].count += j - d[i].pos[val];
        d[i].pos[A] += 1;
        d[i].pos[C] += 1;
        d[i].pos[G] += 1;
        d[i].pos[T] += 1;
    } else if (val == C) {
        d[i].count += j - d[i].pos[val];
        d[i].pos[C] += 1;
        d[i].pos[G] += 1;
        d[i].pos[T] += 1;
    } else if (val == G) {
        d[i].count += j - d[i].pos[val];
        d[i].pos[G] += 1;
        d[i].pos[T] += 1;
    } else if (val == T) {
        d[i].count += j - d[i].pos[val];
        d[i].pos[T] += 1;
    }

}

void sortmtol(int N, int M) {
    int i, j;
    for(i = 1; i <= M; ++i) {
        int val;
        val = getval(d[i].s[0]);
        d[i].pos[val] = 0;
        for(j = 0; j < N; ++j) {
            val = getval(d[i].s[j]);
            update(val, i, j);
        }
        //printf("%d\n", d[i].count);
    }
}

void print(int N, int M) {
    int i, j;
    int maxpos;
    int max;
    // for(i = 1; i < M; ++i) {
    //     max = d[i].count;
    //     maxpos = 1;
    //     for(j = i + 1; j <= M; ++j) {
    //         if(d[i].count > d[j].count) {
    //             DNA temp;
    //             temp = d[i];
    //             d[i] = d[j];
    //             d[j] = temp;
    //         }
    //     }
    // }
    sort(d, d + M + 1 , comparation);
    for(i = 1; i <= M; ++i) {
        puts(d[i].s);
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int i, j;
    for (i = 1; i <= M; ++i) {
        for(j = 0; j < N; ++j) {
            d[i].s[j] = 0;
        }
    }
    getchar();
    for(i = 1; i <= M; ++i) {
        j = 0;
        while(j < N) {
            d[i].s[j] = getchar();
            ++j;
        }
        getchar();
        d[i].s[j] = 0;
    }
    sortmtol(N, M);
    print(N, M);
    return 0;

}