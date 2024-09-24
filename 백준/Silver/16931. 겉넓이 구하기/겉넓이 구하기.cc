#include <iostream>
#include <string>
#include <vector>
using namespace std;


int dx[4] = { 1,-1,0,0 }; // 동 서 남 북

int dy[4] = { 0,0,-1,1 }; // 동 서 남 북 

int main() {

	int n, m;
	cin >> n >> m;

	/* 한 블록 씩 기준으로 삼고, 옆 네 방향, 위를 검사.  밑은 반드시 막혀 있음 */

	vector<vector<int>> vec(n, vector<int>(m));

	int count = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> vec[i][j];
			count += (6 * vec[i][j] - 2 * (vec[i][j] - 1)); // 위쪽, 아래쪽 계산
		}
	}

	for (int i = 0; i < n; ++i) { //제일 위(0), 밑(n-1) 열의 경우 북 / 남 존재x

		for (int j = 0; j < m; ++j) { // 제일 왼쪽(0), 오른쪽 (m-1) 행의 경우 서 / 동 존재x

			if (i != 0) { //북쪽 검사

				count -= (vec[i - 1][j] >= vec[i][j] ? vec[i][j] : vec[i - 1][j]);
			
			}

			if (i != n - 1) { //남쪽 검사

				count -= (vec[i + 1][j] >= vec[i][j] ? vec[i][j] : vec[i + 1][j]);
			}

			if (j != 0) { //서쪽 검사

				count -= (vec[i][j-1] >= vec[i][j] ? vec[i][j] : vec[i][j-1]);
			}

			if (j != m - 1) { //동쪽 검사

				count -= (vec[i][j+1] >= vec[i][j] ? vec[i][j] : vec[i][j+1]);
			}

		}
	}
	
	cout << count;

	return 0;
}