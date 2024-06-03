#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <set>
#define endl '\n'

using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//가장 큰 원판을 세 번째 탑의 바닥에 놓는 것까지, 이는 그 전과정의 총 횟수와 같다.
	//그리고 가장 큰 원판을 놓는다. (+1) 이후 그 전과정의 총 횟수를 더한다. 3 = 3+1+3 = 2*2+1
	// 2 = 1+1+1


	int n;
	cin >> n;

	vector<int> vec = { 0,1 };

	for (int i = 2; i <= n; ++i) {
		vec.push_back(vec[i - 1] * 2 + 1);
	}
	cout << vec[n] << '\n'; //여기까지가 총 횟수.

	vector<pair<int, int>> hanoi = { make_pair(0,0), make_pair(1,3) };

	int startpoint = 1;	

	for (int i = 2; i <=n; ++i) { //세트에 모조리 넣기 반복문
		for (int j = startpoint; j < vec[i - 1] + startpoint; ++j) { //반복 횟수
			if (hanoi[j] == make_pair(1,3)) {
				hanoi.push_back(make_pair(1, 2));
			}
			else if (hanoi[j] == make_pair(1, 2)) {
				hanoi.push_back(make_pair(1, 3));
			}
			else if (hanoi[j] == make_pair(2, 1)) {
				hanoi.push_back(make_pair(3, 1));
			}
			else if (hanoi[j] == make_pair(2, 3)) {
				hanoi.push_back(make_pair(3, 2));
			}
			else if (hanoi[j] == make_pair(3, 1)) {
				hanoi.push_back(make_pair(2, 1));
			}
			else {
				hanoi.push_back(make_pair(2, 3));
			}
		}

		hanoi.push_back(make_pair(1, 3)); //가운데
		
		startpoint += vec[i-1];
		for (int j = startpoint; j < vec[i - 1] + startpoint; ++j) { //반복 횟수
			if (hanoi[j] == make_pair(1, 3)) {
				hanoi.push_back(make_pair(2,1));
			}
			else if (hanoi[j] == make_pair(1, 2)) {
				hanoi.push_back(make_pair(2,3));
			}
			else if (hanoi[j] == make_pair(2, 1)) {
				hanoi.push_back(make_pair(3,2));
			}
			else if (hanoi[j] == make_pair(2, 3)) {
				hanoi.push_back(make_pair(3,1));
			}
			else if (hanoi[j] == make_pair(3, 1)) {
				hanoi.push_back(make_pair(1,2));
			}
			else {
				hanoi.push_back(make_pair(1,3));
			}
		}
	}
	
	for (int i = 0; i < vec[n]; ++i) {
		cout << hanoi[startpoint + i].first << ' ' << hanoi[startpoint + i].second << '\n';
	}

	return 0;
}