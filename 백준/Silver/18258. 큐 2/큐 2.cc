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

int dat[2000000];
int head = 0;
int tail = 0;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;

	while (n--) {
		string op;
		cin >> op;

		if (op == "push") {
			int x;
			cin >> x;
			dat[tail++] = x;
		}
		else if (op == "pop") {
			if (head == tail) {
				cout << -1 << '\n';
			}
			else {
				cout << dat[head++]<<'\n';
			}
		}
		else if (op == "size") {
			cout << tail - head <<'\n';
		}
		else if (op == "empty") {
			if (head == tail) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (op == "front") {
			if (head == tail ) cout << -1 << '\n';
			else cout << dat[head] <<'\n';
		}
		else if (op == "back") {
			if (head == tail ) cout << -1 << '\n';
			else cout << dat[tail-1]<<'\n';
		}
	}
	return 0;
}