#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;

		int firstVal = 26*26 * (str[0] - 'A') + 26 * (str[1] - 'A') + (str[2] - 'A');
		string s = str.substr(4);
		int secondVal = stoi(s);

		if (abs(firstVal - secondVal) <= 100) {
			cout << "nice" << '\n';
		}
		else {
			cout << "not nice" << '\n';
		}
	}
	return 0;
}