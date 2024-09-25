#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	
	int n, m , r; 
	cin >> n >> m >> r;

	// n과 m 작은 수는 반드시 짝수. 작은 짝수 / 2 만큼 반복해야 함.



	vector<vector<int>> vec(n, vector<int>(m));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> vec[i][j]; //벡터 초기화
		}
	}

	for (int k = 0; k < r; ++k) {

		for (int i = 0; i < ((n < m ? n : m) / 2); ++i) { //2면 한번, 4면 두번....

			// i 번째 행은 밑으로 이동. n - 1 - 2 * i 번째 열은 오른쪽
			// m - 1 - i 번째 행은 위로 이동. i 번째 열은 왼쪽 이동

			//시작 지점 따로 저장, 이후 진행하고 마지막에 붙여 넣기

			int startPoint = vec[i][i];

			//윗 변 반복문 진행.
			for (int up = i; up < m - i - 1; up++) {
				vec[i][up] = vec[i][up + 1];
			}

			//오른쪽 변 반복문 진행.
			for (int right = i; right < n - 1 - i; right++) {
				vec[right][m - i - 1] = vec[right + 1][m - i - 1];
			}

			//밑 변 반복문 진행
			for (int down = m - 1 - i; down >= 1 + i; down--) {
				vec[n - 1 - i][down] = vec[n - 1 - i][down - 1];
			}

			//왼쪽 변 반복문 진행
			for (int left = n - i - 1; left >= 1 + i; left--) {
				vec[left][i] = vec[left - 1][i];
			}

			vec[i + 1][i] = startPoint;

		}

	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << vec[i][j] << " ";
		}
		cout << '\n';
	}


	return 0;
}
