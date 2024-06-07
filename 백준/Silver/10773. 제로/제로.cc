#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <set> 
#include <algorithm>
#include <list>
#include <stack>
#define endl '\n'

using namespace std;

typedef long long ll;


stack<int> stk;
int n, k;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	ll ans = 0;

	while (n--) {
		cin >> k;
		if (k == 0) {
			ans -= stk.top();
			stk.pop();
		}
		else {
			ans += k;
			stk.push(k);
		}
	}

	cout << ans;

}