#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>
#define endl '\n'

using namespace std;

typedef long long ll;

int f_array[7] = {};
int m_array[7] = {};

int main() {
	
	int n,k;
	cin >> n >> k;

	bool gen;

	int grade;

	for (int i = 0; i < n; ++i) {
		cin >> gen >> grade;
		if (gen) m_array[grade]++;
		else f_array[grade]++;
	}

	int ans = 0;

	for (int i = 1; i < 7; ++i) {
		if (f_array[i] != 0) ans += ceil(f_array[i] / (k*1.0));
		if (m_array[i] != 0) ans += ceil(m_array[i] / (k*1.0));
	}
	cout << ans;

	return 0;
	
}