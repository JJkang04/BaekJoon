#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 굳이 시뮬레이션을 전부 돌릴 필요 없음. 일정 횟수 회전하면 같아지는 분기를 나눠서, 찾기만 하기.

void rotateArray(vector<vector<int>>& vec, int sizeN, int sizeM, int sp) {
	
	int small = (sizeN < sizeM ? sizeN : sizeM);

	int temp = vec[sp][sp];


	//윗변 반복문

	for (int i = 0; i < sizeM - 1; ++i) {
		vec[sp][i + sp] = vec[sp][i + sp + 1];
	}

	//오른쪽변 반복문
	
	for (int i = 0; i < sizeN - 1; ++i) {
		vec[sp + i][sizeM + sp - 1] = vec[sp + i + 1][sizeM + sp - 1];
	}

	//아래변 반복문

	for (int i = sp + sizeM - 1; i >= sp + 1; --i) {
		vec[sizeN + sp - 1][i] = vec[sizeN + sp - 1][i - 1];
	}

	//왼쪽변 반복문

	for (int i = sizeN + sp - 1; i >= sp + 1; --i) {
		vec[i][sp] = vec[i - 1][sp];
	}

	vec[sp + 1][sp] = temp;

}

int main() {

	int n, m;
	long int r;

	cin >> n >> m >> r;

	// n과 m 작은 수는 반드시 짝수. 작은 짝수 / 2 만큼 반복해야 함.

	// 영향받는 블럭의 개수만큼 회전하면 원상복구. 이를 이용해서 r의 크기 줄이기

	

	vector<vector<int>> vec(n, vector<int>(m));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> vec[i][j]; //벡터 초기화
		}
	}

	for (int j = 0; j < ((n < m ? n : m) / 2); ++j) { //2면 한번, 4면 두번....

		int rot = 2 * (n-2*j) + 2 * (m-2*j) - 4; //같아지는 회전 횟수

		int rotateNum = r % rot;

		for (int i = 0; i < rotateNum; ++i) { //rotateNum만큼만 회전 진행

			rotateArray(vec, (n - j * 2), (m - j * 2), j);

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
