#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <set> 
#include <algorithm>
#include <list>
#include <stack>
#include <queue>
#define endl '\n'

typedef long long ll;

using namespace std;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    vector<int> vec;

    int k;

    for (int i = 0; i < n; ++i) {
        cin >> k;
        vec.push_back(k);
    }

    sort(vec.begin(), vec.end(), greater<int>());
   
    for (const int& i : vec) {
        cout << i << '\n';
    }

    return 0;
}