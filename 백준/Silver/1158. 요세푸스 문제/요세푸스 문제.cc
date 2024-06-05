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

    int n, k,len = 0;

    cin >> n >> k;


    vector<int> vec;

    int nxt[5001] = {};
    int pre[5001] = {};

    for (int i = 1; i <= n; ++i) {
        pre[i] = (i == 1) ? n : i - 1;
        nxt[i] = (i == n) ? 1 : i + 1;
        len++;
    }

    int i = 1;
    for (int cur = 1; len != 0; cur = nxt[cur]) {
        if (i == k) {
            pre[nxt[cur]] = pre[cur];
            nxt[pre[cur]] = nxt[cur];
            vec.push_back(cur);
            i = 1;
            --len;
        }
        else {
            ++i;
        }
    }

    cout << "<";

    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i != vec.size() - 1) {
            cout << ", ";
        }
    }

    cout << ">";

    return 0;

}