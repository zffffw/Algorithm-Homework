#include <stdio.h>
#define MAXCODELENGTH 35
#define MAXCHOICE 1001
#include <string.h>
typedef struct barcode {
    int bin[MAXCODELENGTH];
} Barcode;

Barcode bcode[MAXCHOICE];

int bcodenum = 1;
int content_k_and_m(int bin[], int n, int k, int m) {
    int i;
    int count = 0;
    int lastzero;
    int lastone;
    int maxsize = 0;
    int same = 1;
    for(i = 1; i <= n; ++i) {
        if(bin[i] == 0 && bin[i - 1] == 1) {
            count += 1;
            int temp = 0;
            temp = i - lastzero - 1;
            same = 1;
            if(temp > maxsize)
                maxsize = temp;
        } else if(bin[i] == 1 && bin[i - 1] == 0) {
            count += 1;
            int temp = 0;
            temp = i - lastone - 1;
            same = 1;
            if(temp > maxsize) {
                maxsize = temp;
            }
        } else if(bin[i] == bin[i - 1]){
            same += 1;
        }

        if(maxsize > m || same > m) {
            return 0;
        }

        if(bin[i] == 1) {
            lastone = i;
        } else if (bin[i] == 0) {
            lastzero = i;
        }

    }

    if(count == k) {
        return 1;
    } else {
        return 0;
    }
}

int updateBcode(int t[], int pos, int n) {
    for(int i = 1; i <= n; ++i) {
        bcode[pos].bin[i] = t[i];
        printf("%d", t[i]);
    }
    printf("\n");
    return pos + 1;
}

void exist(int t[], int pos, int n) {

} 

void search(int t[], int n, int k, int m, int pos) {
    int temp[MAXCODELENGTH];
    for(int j = 1; j <= n; ++j) {
        temp[j] = t[j];
    }
    int max = ((pos + m + 1) > n) ? n : (pos + m + 1);
    for(int i = pos; i >= 1; --i) {
        // for(int j = 1; j <= n; ++j) {
        //     printf("%d", temp[j]);
        // }
        // printf("\n");
        temp[i] = 1;
        if(i - 1 >= 0) {
            search(temp, n, k, m, i - 1);
        }
        if(content_k_and_m(temp, n, k, m)) {
            bcodenum = updateBcode(temp, bcodenum, n);
        }
        if(i != 1)
            temp[i] = 0;
        if(i - 1 >= 0) {
            search(temp, n, k, m, i - 1);
        }
        if(content_k_and_m(temp, n, k, m)) {
            bcodenum = updateBcode(temp, bcodenum, n);
        }
    }
}




int main() {
    int n, k, m;
    //scanf("%d %d %d", &n, &k, &m);
    int i, j;
    int s[MAXCODELENGTH] = {};
    int val;
    search(s, 7, 4, 3, 7);
    return 0;
}

