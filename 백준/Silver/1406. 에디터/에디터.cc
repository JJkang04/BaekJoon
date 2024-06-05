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

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    list<char> L;
    string str;
    cin >> str;

    for (const char& c : str) {
        L.push_back(c);
    }
    auto cursor = L.end();
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        
        char c;
        cin >> c;
        if (c == 'P') {
            char ch;
            cin >> ch;
            L.insert(cursor,ch);
        }
        else if (c == 'L') {
            if (cursor != L.begin()) {
                cursor--;
            }
        }
        else if (c == 'D') {
            if (cursor != L.end()) {
                cursor++;
            }
        }
        else if (c == 'B') {
            if (cursor != L.begin()) {
                cursor--;
                cursor  = L.erase(cursor);
            }
        }
    }

    for (auto i : L) {
        cout << i;
    }
    return 0;

}