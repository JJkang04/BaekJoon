#include <iostream>
#include <vector>
using namespace std;

int main() {

	int n;
	cin >> n;

	int len = 1;

	for (int i = 0; i < n; ++i) {
		len *= 2;
	}

	len++;

	cout << len * len;

	return 0;
}