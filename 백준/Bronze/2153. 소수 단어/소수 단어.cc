#include <iostream>
#include <vector>
using namespace std;


int main() {
	string str;
	cin >> str;

	int sum = 0;

	for (int i = 0; i<str.size(); ++i) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			sum += str[i] - 'A' + 27;
		}
		else {
			sum += str[i] - 'a' + 1;
		}
	}

	if (sum == 1) {
		cout << "It is a prime word.";
		return 0;
	}

	vector<bool> vec(sum+1, true);
	vec[0] = false;

	for (int p = 2; p * p <= sum; ++p) {
		if (vec[p]) {
			for (int multi = p * p; multi <= sum; multi += p) {
				vec[multi] = false;
			}
		}
	}

	if (vec[sum]) {
		cout << "It is a prime word.";
	}

	else {
		cout << "It is not a prime word.";
	}

	return 0;
}
