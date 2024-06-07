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




const int MX = 10000;
int dat[MX];
int pos = 0;

void push(int x) {
	dat[pos++] = x;
}

void pop() {
	if (pos != 0) {
		cout << dat[pos-- - 1];
	}
	else {
		cout << -1;
	}
}

void size() {
	cout << pos;
}

void top() {
	if (pos != 0) {
		cout << dat[pos - 1];
	}
	else {
		cout << -1;
	}
}

void empty() {
	if (pos == 0) {
		cout << 1;
	}
	else {
		cout << 0;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	while (n--) {
		string op;
		cin >> op;

		if (op == "push") {
			int i;
			cin >> i;
			push(i);
		}
		else if (op == "top") {
			top();
			cout << '\n';
		}
		else if (op == "size") {
			size();
			cout << '\n';
		}
		else if (op == "empty") {
			empty();
			cout << '\n';
		}
		else { //pop
			pop();
			cout << '\n';
		}
	}
}