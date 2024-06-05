#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <set> 
#include <algorithm>
#include <list>
#define endl '\n'

using namespace std;

typedef long long ll;

const int MX = 1000005;
char dat[MX];
int pre[MX];
int nxt[MX];
int unused = 1;

void insert(int addr, char ch) {
    dat[unused] = ch;
    nxt[unused] = nxt[addr];
    pre[unused] = addr;

    if (nxt[addr] != -1) {
        pre[nxt[addr]] = unused;
    }

    nxt[addr] = unused;
    unused++;
}

void erase(int addr) {
    nxt[pre[addr]] = nxt[addr];
    
    if (nxt[addr] != -1) {
        pre[nxt[addr]] = pre[addr];
    }
}

void traversal() {
    int cur = nxt[0];
    while (cur != -1) {
        cout << dat[cur];
        cur = nxt[cur];
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fill(pre, pre + MX, -1);
    fill(nxt, nxt + MX, -1);

    string str;
    cin >> str;

    int cursor = 0;

    for (const char& c : str) {
        insert(cursor, c);
        cursor++;
    }

    int t;
    cin >> t;

    while (t--) {
        char c;
        cin >> c;

        if (c == 'P') {
            char ch;
            cin >> ch;

            insert(cursor, ch);
            cursor = nxt[cursor];
        }
        else if (c == 'L') {
            if (pre[cursor] != -1) {
                cursor = pre[cursor];
            }
        }
        else if (c == 'D') {
            if (nxt[cursor] != -1) {
                cursor = nxt[cursor];
            }
        }
        else if (c == 'B') {
            if (pre[cursor] != -1) {
                erase(cursor);
                cursor = pre[cursor];
            }
        }
    }

    traversal();

    return 0;

}