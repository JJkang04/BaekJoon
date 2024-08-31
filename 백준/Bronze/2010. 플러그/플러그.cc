#include <iostream>
#include <cmath>
#include <string>
using namespace std;


int main() {
	int n;
	cin >> n;

	int sumOfPlug = 0;


	int k;

	for (int i = 0; i < n; ++i) {
		cin >> k;
		sumOfPlug += k;
	}

	cout << sumOfPlug - n + 1;

	return 0;
}
