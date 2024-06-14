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

int n;
string str;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	int count = 0;

	while (n--) {
		cin >> str;

		deque<char> deq;

		if (str.size() % 2 != 0) {
			continue;
		}

		for (int i = 0; i < str.size(); ++i) {

			if (deq.empty()) {
				deq.push_back(str[i]);
			}

			else if (deq.back() == str[i]) {
				deq.pop_back();
			}

			else deq.push_back(str[i]);
		}

		if (deq.empty()) { count++; }
	}

	cout << count;
}
