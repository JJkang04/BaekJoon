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

#define X first
#define Y second

using namespace std;

typedef long long ll;

int n, m, k;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	// 1 2 3 4 5 6 7 8 9
	deque<int> deq;

	for (int i = 1; i <= n; ++i) {
		deq.push_back(i);
	}

	int ans = 0;

	while (m--) {
		
		cin >> k;
		
		int count = 0;
		
		while (deq.front() != k) {
			deq.push_back(deq.front());
			deq.pop_front();
			count++;
		}
		if (count > n - count) {
			count = n - count;
		}
		deq.pop_front();
		ans += count;
		n--;
	}
	cout << ans;
	return 0;
}
