#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>
#define endl '\n'

using namespace std;

typedef long long ll;

int a[100001] = {};

bool b[2000001] = {};

int n, x;

int main() {
	
	int ans = 0;

	cin >> n;
	
	for (int i = 0; i < n; ++i) cin >> a[i];

	cin >> x;

	for (int i = 0; i < n; ++i) {
		if (x - a[i] > 0 && b[x - a[i]]) ans++;
		else {
			b[a[i]] = true;
		}
	}
	cout << ans;

	return 0;
	
}