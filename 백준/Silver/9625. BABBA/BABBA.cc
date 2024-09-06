#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	int k;
	cin >> k;

	int A = 1;
	int B = 0;

	while (k--) {
		int temp = B;
		B += A;
		A += temp - A;
	}

	cout << A << " " << B;

 }