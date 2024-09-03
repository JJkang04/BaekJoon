#include <iostream>
using namespace std;


int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		string bin1, bin2;
		cin >> bin1;
		cin >> bin2;

		int dist = 0;

		for (size_t i = 0; i < bin1.length(); ++i) {
			if (bin1[i] != bin2[i]) {
				++dist;
			}
		}

		cout << "Hamming distance is " << dist << "." << '\n';
	}
	return 0;
}
