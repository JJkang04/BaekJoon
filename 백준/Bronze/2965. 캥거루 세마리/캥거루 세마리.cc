#include <iostream>
using namespace std;


int main() {
	int a, b, c;
	
	cin >> a >> b >> c;

	int diff1, diff2;

	diff1 = b - a;
	diff2 = c - b;

	if (diff1 >= diff2) {
		cout << diff1 - 1;
		return 0;
	}
	else {
		cout << diff2 - 1;
		return 0;
	}

	return 0;
}
