#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <set>
#define endl '\n'

using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> vec = { 0,1,2 };

	for (int i = 3; i <= n; i++) {
		int num = (vec[i - 1] + vec[i - 2]) % 10007;
		vec.push_back(num);
	}

	cout << vec[n];

	return 0;
}