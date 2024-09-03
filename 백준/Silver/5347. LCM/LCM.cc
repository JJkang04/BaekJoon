#include <iostream>
using namespace std;


int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;

		if (a == b) {
			cout << a << '\n';
			continue;
		}

		int big, small;

		if (a > b) {
			big = a;
			small = b;
		}
		else {
			big = b;
			small = a;
		}

		int mul = 1;

		while (true) {
			long long int temp = big;
			temp *= mul;
			if (temp % small == 0) {
				cout << temp << '\n';
				break;
			}
			mul++;
		}
	}
}