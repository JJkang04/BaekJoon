#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	if (b >= c) {
		cout << -1;
		return 0;
	}

	int incomeByEach = c - b;
	
	long long int ans = floor(a / incomeByEach) + 1;

	cout << ans;
	return 0;
}