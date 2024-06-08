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
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	
	stack<pair<int, int>> tower; //first는 타워의 길이, second는 타워의 번호
	vector<int> vec;

	tower.push({ 100000001,0 });

	for (int i = 1; i <= n; ++i) {
		cin >> tow;
		while (tower.top().first < tow) {
			tower.pop();
		}
		cout << tower.top().second << " ";
		tower.push({tow,i});
	}
	for (int i = 0; i < vec.size(); ++i) {
		cout << vec[i] << ' ';
	}
}