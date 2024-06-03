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

	int avr;
	int cent;

	vector<int> vec(5);

	int sum = 0;

	for (int i = 0; i < 5; ++i) {
		int num;
		cin >> num;
		vec[i] = num;
		sum += num;
	}

	sort(vec.begin(), vec.end());

	avr = sum / 5;

	cent = vec[2];

	cout << avr << '\n' << cent;

	return 0;
}