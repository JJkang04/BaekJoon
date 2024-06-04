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

	int space = 2 * n;

	for (int i = 1; i <= (line - 1) / 2; ++i) {
		for (int j = 0; j < i; ++j) {
			cout << '*';
		}
		for (int k = 0; k < space - 2 * i; ++k) {
			cout << ' ';
		}
		for (int j = 0; j < i; ++j) {
			cout << '*';
		}
		cout << '\n';
	}
	
	for (int i = 0; i < space; ++i) {
		cout << '*';
	}
	cout << '\n';

	for (int i = (line-1)/2; i >=1; --i) {
		for (int j = 0; j < i; ++j) {
			cout << '*';
		}
		for (int k = 0; k < space - 2 * i; ++k) {
			cout << ' ';
		}
		for (int j = 0; j < i; ++j) {
			cout << '*';
		}
		cout << '\n';
	}


	return 0;
}