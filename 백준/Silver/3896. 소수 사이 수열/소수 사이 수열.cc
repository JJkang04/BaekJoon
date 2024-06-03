#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int t;
	cin >> t;

	vector<bool> vec(1299709, true);

	vec[0] = vec[1] = false;

	for (int j = 2; j * j <= 1299708; ++j) {
		if (vec[j]) {
			for (int k = j * j; k <= 1299708; k += j) {
				vec[k] = false;
			}
		}
	}

	for (int i = 0; i < t; ++i) {

		int n;

		cin >> n;

		if (vec[n]) {
			cout << 0 << '\n';
		}

		else {
			int startNum = 0;
				
			int endNum = 0;
				
				for(int j = n-1; j>=2; --j) {
					if (vec[j]) {
						startNum = j;
						break;
					}
				}
				
				for (int k = n; k >= n; ++k) {
					if (vec[k]) {
						endNum = k;
						break;
					}
				}
				cout << endNum - startNum << '\n';
			}
		}

	return 0;

}