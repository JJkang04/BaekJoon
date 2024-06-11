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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;

	queue<int> que;


	while (n--) {
		string op;
		cin >> op;

		if (op == "push") {
			int x;
			cin >> x;
			que.push(x);
		}
		else if (op == "pop") {
			if (que.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << que.front()<<'\n';
				que.pop();
			}
		}
		else if (op == "size") {
			cout << que.size()<<'\n';
		}
		else if (op == "empty") {
			if (que.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (op == "front") {
			if (que.empty()) cout << -1 << '\n';
			else cout << que.front()<<'\n';
		}
		else if (op == "back") {
			if (que.empty()) cout << -1 << '\n';
			else cout << que.back()<<'\n';
		}
	}
	return 0;
}