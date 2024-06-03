#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#define endl '\n'

using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		string s, p;
		cin >> s >> p;

		int time = 0;

		int pos = 0;


		while ((pos = s.find(p, pos)) != string::npos) {
			time++;
			pos += p.length();
		}

		int len = s.size();

		cout << len - (time * p.size()) + time << '\n';

	}

	return 0;
}