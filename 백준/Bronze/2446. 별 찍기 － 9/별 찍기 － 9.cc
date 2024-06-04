#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>
#define endl '\n'

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int line = 2 * n - 1;

	for (int i = 0; i < (line - 1) / 2; ++i) {
		for (int j = 0; j < i; ++j) {
			cout << " ";
		}
		for (int j = 0; j < line - (2 * i);  ++j) {
			cout << "*";
		}
		cout << '\n';
	}

	for (int i = 0; i < (line - 1) / 2; ++i) {
		cout << " ";
	}
	cout << "*";
	cout << '\n';

	for (int i = 0; i < (line - 1) / 2; ++i) {
		for (int j = (line-1)/2 -1-i; j >0; --j) {
			cout << " ";
		}
		for (int j = 2*(i+1)+1; j > 0; --j) {
			cout << "*";
		}
		cout << '\n';
	}

	return 0;
}