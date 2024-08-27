#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;

	long long int totalDot = 0;

	if (n == 1) {
		totalDot = 5;
	}
	else if (n == 2) {
		totalDot = 12;
	}
	
	else {
		for (int i = 0; i < n-2; ++i) {
			totalDot += 10 + (3 * i);
		}
		totalDot += 12;
	}

	cout << totalDot % 45678;


}