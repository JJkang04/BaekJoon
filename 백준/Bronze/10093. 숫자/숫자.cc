#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#define endl '\n'

using namespace std;

typedef long long ll;

int main() {
	ll a, b;
	cin >> a >> b;

	if (a == b) {
		cout << 0;
		return 0;
	}

	ll big = (a > b) ? a : b;
	ll small = (a < b) ? a : b;

	

	int diff = big - small - 1;

	cout << diff << '\n';


	for (int i = 1; i <= diff; ++i) {
		cout << small + i << ' ';
	}
	return 0;
}