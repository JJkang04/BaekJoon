#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	int h, w;
	cin >> h >> w;

	

	vector<vector<char>> vec(h, vector<char>(w));

	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			cin >> vec[i][j];
		}
	}

	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			
			bool neverCloud = true;
			
			if (vec[i][j] == 'c') {
				cout << 0 << " ";
			}
			else if (vec[i][j] == '.') {
				if (j == 0) {
					cout << -1 << " ";
				}
				else {
					for (int m = j-1; m >= 0; --m) {
						if (vec[i][m] == 'c') {
							cout << j - m << " ";
							neverCloud = false;
							break;
						}
					}
					if (neverCloud) {
						cout << -1 << " ";
					}
				}
			}
		}
		cout << '\n';
	}
	return 0;
 }