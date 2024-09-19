#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m, x, y, k;
	cin >> n >> m >> x >> y >> k;

	vector<vector<int>> board(n, vector<int>(m));

	for(int i = 0; i<n; ++i) { // 벡터를 이용한 보드 초기화
		for (int j = 0; j < m; ++j) {
			cin >> board[i][j];
		}
	}

	int front = 0;
	int back = 5;
	int up = 1;
	int down = 4;
	int right = 2;
	int left = 3; //주사위 면 숫자를 인덱스로 관리

	vector<int> dice{ 0,0,0,0,0,0 };

	vector<int> cur = { x,y }; //주사위의 현재 위치를 나타내는 벡터

	for (int i = 0; i < k; ++i) {
		
		int order;
		
		cin >> order;

		if (order == 1) { //동쪽으로 이동
			
			if (cur[1] + 1 >= m) { //범위 넘음 검사
				continue;
			}
			
			else {
				cur[1]++;
				int temp = right;
				right = down;
				down = left;
				left = up;
				up = temp;
				
				if (board[cur[0]][cur[1]] == 0) { //이동한 위치의 숫자가 0이면 바닥면 숫자 -> 칸
					board[cur[0]][cur[1]] = dice[down];
				}

				else {
					dice[down] = board[cur[0]][cur[1]];
					board[cur[0]][cur[1]] = 0;
				}

				cout << dice[up] << '\n'; //윗 면 숫자 출력
			}
		}
		
		else if (order == 2) {
			
			if (cur[1] == 0) {
				continue; //y가 0이면 왼쪽이 존재하지 않음
			}

			else {
				cur[1]--;
				int temp = left;
				left = down;
				down = right;
				right = up;
				up = temp;

				if (board[cur[0]][cur[1]] == 0) {
					board[cur[0]][cur[1]] = dice[down];
				}
				else {
					dice[down] = board[cur[0]][cur[1]];
					board[cur[0]][cur[1]] = 0;
				}
				cout << dice[up] << '\n'; //윗 면 숫자 출력
			}
		}
		
		else if (order == 3) { //북쪽
			
			if (cur[0] == 0) {
				continue;
			}

			else {
				cur[0]--;
				int temp = front;
				front = down;
				down = back;
				back = up;
				up = temp;

				if (board[cur[0]][cur[1]] == 0) {
					board[cur[0]][cur[1]] = dice[down];
				}
				else {
					dice[down] = board[cur[0]][cur[1]];
					board[cur[0]][cur[1]] = 0;
				}
				cout << dice[up] << '\n'; //윗 면 숫자 출력
			}
		}

		else if (order == 4) { //남쪽
			
			if (cur[0] == n - 1) {
				continue;
			}

			else {
				cur[0]++;
				int temp = front;
				front = up;
				up = back;
				back = down;
				down = temp;

				if (board[cur[0]][cur[1]] == 0) {
					board[cur[0]][cur[1]] = dice[down];
				}
				else {
					dice[down] = board[cur[0]][cur[1]];
					board[cur[0]][cur[1]] = 0;
				}
				cout << dice[up] << '\n'; //윗 면 숫자 출력
			}
		}
	}

	return 0;

 }