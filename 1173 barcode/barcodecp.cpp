#include <iostream>
#include <string>
#define MAXSIZE 100
using namespace std;

string res[MAXSIZE];
int resnum = 1;
int judge(string s, int max) {
    char one = '1';
    int _posh, _post;
    int flag = 1;
    _posh = _post = s.find(one, 0);
    if(_posh >= max) {
        flag = 0;
    } else {
        while(_post != string::npos) {
            if(_post - _posh > max) {
                flag = 0;
                break;
            }
            _posh = _post;
            _post = s.find(one, _posh + 1);
        }
    }
    // if(s.length() - s.rfind(one) >= max) {
    //     flag = 0;
    // }
    return flag;
}

int exist(string s) {
    int i = 0;
    while(!res[i].empty()) {
        if(res[i] == s) {
            return 1;
        }
        ++i;
    }
    return 0;
}

int getBoardNum(string s) {
    int i = 0;
    int count = 0;
    while(s[i]) {
        if(s[i] == '1') {
            count += 1;
        }
        ++i;
    }
    return count;
}

void findAllBars(string s, int poslastb, int boardnum, int blank, int board, int maxboxl) {
    string q;
    q = s;
    cout << s << endl;
    if(boardnum > board) {
        return ;
    }
    if(boardnum <= board && poslastb == blank) {
        return ;
    }
    if(!judge(q, maxboxl)) {
        return ;
    } else {
        if(!exist(s) && getBoardNum(s) == board) {
            cout << s << endl;
            res[resnum] = s;
            resnum += 1;
        }
    }
    for(int i = poslastb + 1; i <= blank; ++i) {
        q[i] = '1';
        findAllBars(q, i, boardnum + 1, blank, board, maxboxl);
        q[i] = '0';
    }
}

int main() {
    string s;
    int length, box, maxboxl;

    cin >> length >> box >> maxboxl;

    s.assign(length - 1, '0');

    cout << s << endl;
    findAllBars(s, -1, 1, length - 1, box - 1, maxboxl);
}


