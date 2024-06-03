#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <set>
#include <algorithm>
#define endl '\n'

using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<int> vec(9);

	for (int i = 0; i < 9; ++i) {
		int h;
		cin >> h;
		vec[i] = h;
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < 9; ++i) {
		for (int j = i + 1; j < 9; ++j) {
			int sum = 0;
			for (int k = 0; k < 9; ++k) {
				if (k == i || k == j) {
					continue;
				}
				else {
					sum += vec[k];
				}
			}
			if (sum == 100) {
				for (int l = 0; l < 9; ++l) {
					if (l == i || l == j) {
						continue;
					}
					cout << vec[l] << '\n';
				}
				return 0;
			}
		}
	}

	return 0;
}