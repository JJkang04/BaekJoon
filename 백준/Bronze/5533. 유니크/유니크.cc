#include <iostream>
#include <vector>
using namespace std;


int main() {
	int n;
	cin >> n;

	vector<vector<int>> vec(3, vector<int>(n));
	vector<int> total(n,0); //점수 넣는 벡터

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> vec[j][i];
		}
	}

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j <n; ++j) {
			if (vec[i][j] == 0) {
				continue;
			}
			else {
				int temp = vec[i][j];
				for (int k = 0; k < n; ++k) {
					if (k == j) continue;
					if (vec[i][k] == temp) {
						vec[i][j] = vec[i][k] = 0;
					}
				}
			}
		}
	}

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < n; ++j) {
			if (vec[i][j] != 0) {
				total[j] += vec[i][j];
			}
		}
	}

	for (const int& i : total) {
		cout << i << '\n';
	}
	return 0;
 }