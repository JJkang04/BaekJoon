#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#define endl '\n'

using namespace std;

typedef long long ll;

int main() {

	int n;

	cin >> n;

	int y_cost = 0, m_cost = 0;

	for (int i = 0; i < n; ++i) {
		int cost;
		cin >> cost;
		y_cost += 10 * ((cost / 30) + 1);
		m_cost += 15 * ((cost / 60) + 1);
	}

	if (y_cost == m_cost) {
		cout << 'Y' << ' ' << 'M' << ' ' << y_cost;
	}
	else if (y_cost > m_cost){
		cout << 'M' << ' ' << m_cost;
	}
	else {
		cout << 'Y' << ' ' << y_cost;
	}
	return 0;
}