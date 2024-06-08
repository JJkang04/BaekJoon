#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <set> 
#include <algorithm>
#include <list>
#include <stack>
#define endl '\n'

using namespace std;

typedef long long ll;

int n, tow;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	
	stack<pair<int, int>> tower; //first는 타워의 길이, second는 타워의 번호
	vector<int> vec;


	for (int i = 1; i <= n; ++i) {
		cin >> tow;
		while (true) {
			if (tower.empty()) {
				vec.push_back(0);
				break;
			}
			else if(tower.top().first < tow){
				tower.pop();
			}
			else {
				vec.push_back(tower.top().second);
				break;
			}
		}
		tower.push(make_pair(tow, i));
	}
	for (int i = 0; i < vec.size(); ++i) {
		cout << vec[i] << ' ';
	}
}