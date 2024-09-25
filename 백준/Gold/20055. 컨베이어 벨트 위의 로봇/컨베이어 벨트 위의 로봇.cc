#include <iostream>
#include <string>
#include <vector>
using namespace std;

void beltMoving(vector<pair<int, bool>>& belt) { //로봇과 벨트가 회전하는 동작을 하는 함수
	
	auto pair = belt.back();

	for (int i = belt.size() - 1; i >= 1; --i) { //앞 벨트에서 뒤 벨트로 반복
		belt[i] = belt[i - 1];
	}

	belt.front() = pair;
}

int main() {

	int n, k; // 2n은 벨트의 길이, k는 종료되는 기준
	
	cin >> n >> k;

	vector<pair<int,bool>> belt(2 * n,make_pair(0,false)); //벨트의 각 칸마다 내구도와 로봇의 유무

	for (int i = 0; i < 2 * n; ++i) {
		cin >> belt[i].first;
	}

	int count = 0; //내구도가 0이 된 칸의 개수
	
	int level = 0;
	
	while (count < k) {

		level++; //몇 번째 단계 수행 중인지 체크.

		beltMoving(belt); //1번 동작 수행

		if (belt[n - 1].second == true) {
			belt[n - 1].second = false; // 벨트가 회전했을 때 내리는 위치에 존재 체크
		}

		for (int i = n - 2; i >= 0; --i) { // 로봇의 이동 구현
			
			if (belt[i].second == true) { // 로봇이 있는 블록

				if (belt[i + 1].first != 0) { // 다음 블록의 내구도가 0이 아니라면

					if (belt[i + 1].second != true) { //만약 다음 블록에 로봇이 없다면
						
						belt[i].second = false; // 현재 블록 로봇 없애고

						belt[i + 1].second = true; // 다음 블록 로봇 생김

						belt[i + 1].first--; //내구도 깎기
						
						if (belt[i + 1].first == 0) { //내구도 0되면 count 증가
						count++;
						}
					}
				}
			}
		}

		if (belt[n - 1].second == true) {
			belt[n - 1].second = false; // 만약 내리는 위치에 로봇이 올라가면 로봇 그냥 없애기
		}

		if (belt[0].first != 0) { // 올리는 위치 작동 수행

			belt[0].second = true;
			belt[0].first--;

			if (belt[0].first == 0) {
				count++;
			}

		}

		if (count >= k) {
			break;
		}
	}

	cout << level;
	return 0;
}
