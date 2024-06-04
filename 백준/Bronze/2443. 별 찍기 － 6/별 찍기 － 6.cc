#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>
#define endl '\n'

using namespace std;

typedef long long ll;

int main() {

	int n;
	cin >> n;

	int space = 2 * n - 1;

	for (int i = 1; i <=n; ++i) {
		int star = 2 * n - (2*i - 1);
		for (int j = 0; j < (space - star) / 2; ++j) {
			cout << ' ';
		}
		for (int k = 0; k < star; ++k) {
			cout << '*';
		}
		cout << '\n';
	}


	return 0;
}