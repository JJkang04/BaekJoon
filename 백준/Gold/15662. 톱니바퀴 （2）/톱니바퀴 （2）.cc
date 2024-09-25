#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 시작 기어를 기준으로 오른쪽과 왼쪽으로 확장. 왼쪽으로 향하는 쪽은 왼쪽으로만. 반대도 똑같이(중첩되지 않게)

void rotateGear(vector<vector<int>>& gear, int dir, int num);

int main() {
	
	int t; // 기어 개수
	cin >> t;

	vector<vector<int>> gear(t, vector<int>(8,0));

	for (int i = 0; i < t; ++i) {
		string str;
		cin >> str;
		for (int j = 0; j < 8; ++j) {
			gear[i][j] = str[j] - '0';
		}
	} // 벡터 초기화

	int k; // 회전 횟수
	cin >> k;

	for (int i = 0; i < k; ++i) {
		
		int num, dir;

		cin >> num >> dir;
		
		int curGear = num -1; //현재 영향받는 기어의 번호. 인덱스로 다루니 마이너스 1

		int curDir = dir; // curGear가 움직이는 방향
		
		rotateGear(gear, dir, curGear); //일단 회전
		
		while (curGear >= 1) { // 1번 인덱스 기어까지만 봄. 0번부턴 왼쪽 존재 x

			if (gear[curGear][6 + curDir] == gear[curGear-1][2]) //dir이 1이면 시계방향이니 7번과 연관 
				//같으면 멈춤. 영향 없음
			{
				break;
			}

			else {
				//다르면 다른 방향으로 회전
				rotateGear(gear, (curDir == 1 ? -1 : 1), curGear - 1);
				curDir = (curDir == 1 ? -1 : 1); //왼쪽 기어가 움직인 방향 업데이트
			}

			curGear--; // 현재 기어 왼쪽으로 업데이트

		}

		curGear = num -1;

		curDir = dir;

		while (curGear <= t-2) {

			if (gear[curGear][2 + curDir] == gear[curGear + 1][6]) {
				break;
			}

			else {
				rotateGear(gear, (curDir == 1 ? -1 : 1), curGear + 1);
				curDir = (curDir == 1 ? -1 : 1);
			}

			curGear++;
		}

	}

	int ans = 0;

	for (int i = 0; i < t; ++i) {
		if (gear[i][0] == 1) {
			ans++;
		}
	}

	cout << ans;
	return 0;

}

void rotateGear(vector<vector<int>>& gear, int dir, int num) { // 기어의 회전을 구현한 함수

	if (dir == 1) { //시계방향으로 회전

		int tmp = gear[num][7]; // 마지막 값 저장

		for (int i = 7; i >= 1; --i) {
			gear[num][i] = gear[num][i - 1];
		}

		gear[num][0] = tmp;
	}

	else if (dir == -1) { // 반시계방향으로 회전

		int tmp = gear[num][0];

		for (int i = 0; i <= 6; ++i) {
			gear[num][i] = gear[num][i + 1];
		}

		gear[num][7] = tmp;
	}

}