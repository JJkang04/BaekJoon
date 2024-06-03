#include <iostream>
#include <vector>
using namespace std;

int main() {

	int n, k;
	cin >> n >> k;

	vector<bool> vec(n + 1, true);

	vec[0] = vec[1] = false;

	int count_erase = 0;

	for (int i = 2; i<= n; i++) {
		if (vec[i]) {
			vec[i] = false;
			count_erase++;
			if (count_erase == k) {
				cout << i;
				return 0;
			}
			for (int j = i * i; j <= n; j += i) {
				if (vec[j]) {
					vec[j] = false;
					count_erase++;
					if (count_erase == k) {
						cout << j;
						return 0;
					}
				}
			}
		}
	}

	return 0;
}