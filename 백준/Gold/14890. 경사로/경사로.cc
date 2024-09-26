#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isCross(vector<pair<int,bool>> vec, int len) {

	// 0번부터 끝까지
	
	for (int i = 0; i < vec.size()-1; ++i) {
		
		//다음 칸이 낮을 경우. 최소 len 만큼의 칸이 남아있어야함, 그리고 그 칸들과의 차이가 1이고, 그 칸들의 높이 일정
		if (vec[i].first > vec[i+1].first) {

			//높이차가 1보다 크면 탈락

			if (vec[i].first - vec[i + 1].first > 1) {
				return false;
			}

			//len만큼의 칸이 남아있지 않으면 탈락

			else if (i > vec.size() - len - 1) {
				return false;
			}

			//다음 칸의 높이차가 1이고, len만큼 전진할 수 있는 상황에서,
			//그 칸들이 높이가 일정하지 않으면 탈락

			for (int j = 1; j < len; ++j) {
				if (vec[i + j].first != vec[i + j + 1].first) {
					return false; //len 범위 안에 높이가 다르면 경사 불가능
				}
			}

			//통과했으면, 경사로를 len만큼 두었으므로 bool값 바꾸기.

			for (int k = 0; k < len; ++k) {
				vec[i + k + 1].second = true;
			}

			//위 세 가지 경우를 통과하면, 경사로로 지나가기 가능.
		}

		else if (vec[i + 1].first == vec[i].first) continue; //같으면 그냥 지나가기

		//다음 칸이 더 클 때.
		else if (vec[i + 1].first > vec[i].first) {

			//현재 칸에 경사로 있으면 그냥 탈락
			if (vec[i].second == true) return false;
			
			//높이차가 1보다 크면 탈락
			
			if (vec[i + 1].first - vec[i].first > 1) return false;

			//지금까지 지나온 블럭의 개수가 len보다 작으면 탈락
			
			else if (i + 1 < len) return false;
			
			// 다음 칸의 높이차가 1이고, 지금까지 지나온 블럭은 최소 len개 만큼 있을 때,
			// 지금까지 지나온 같은 높이의 블럭의 개수가 len을 충족시키는가?

			for (int j = 0; j < len-1; ++j) {
				if (vec[i - j].first != vec[i - j - 1].first) return false; //높이가 다르면 false
				if (vec[i - j].second == true || vec[i - j - 1].second == true) return false; //이미 경사로 설치되어 있음
			}

			// 여기까지 통과하면, 다음 블럭으로 반드시 건너갈 수 있다.
			
		}

	}

	return true;

}

int main() {

	int n, l;
	cin >> n >> l;

	vector<vector<pair<int, bool>>> map(n, vector<pair<int, bool>>(n, make_pair(0, false)));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j].first;
		}
	}

	vector < vector<pair<int, bool>>> road;

	for (const auto& a : map) {
		road.push_back(a);
	}

	for (int i = 0; i < n; ++i) {
		vector<pair<int,bool>> temp;
		for (int j = 0; j < n; ++j) {
			temp.push_back(map[j][i]);
		}
		road.push_back(temp);
	}
	// 길 벡터에 모두 정리 완료

	
	/* 출발할때 작은 길이 있으면 중단하고 다음 반복. 자신보다 높은 길이 
	있을때, 높이 차이가 1보다 크면 중단, 높이 차이가 1이지만 그동안 나왔던 같은 칸들의 개수가 길이보다 짧다면
	중단. 길거나 같다면 경사로 가능. 이런식으로 끝까지 도달하면 성공*/

	int ans = 0;

	for (const auto& a : road) {
		if (isCross(a, l)) {
			ans++;
		}
	}

	cout << ans;

	return 0;
}
