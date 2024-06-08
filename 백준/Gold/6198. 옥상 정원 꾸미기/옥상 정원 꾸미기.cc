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



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	stack<int> rooftop;

	int n;

	cin >> n;
	rooftop.push(1000000001);
	ll ans = 0;

	for (int i = 0; i < n; ++i) {
		int h;
		cin >> h;
		while (rooftop.top() <= h) {
			rooftop.pop();
		}
		ans += rooftop.size() - 1;
		rooftop.push(h);
	}
	cout << ans;
	return 0;
}