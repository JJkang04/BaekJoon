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

#define X first
#define Y second

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	stack<pair<int,int>> nge; //X는 크기. Y는 인덱스
	
	nge.push({ 1000001,0 });

	int n;
	cin >> n;

	int a;

	vector<int> vec(n+1,-1);

	for(int i =1; i<=n; ++i)  {

		cin >> a; //a로 인해 pop되는 것들은 Y를 a로 고치기.
		while (nge.top().X < a) {
			vec[nge.top().Y] = a;
			nge.pop();
		}
		nge.push({ a,i });
	}

	for (int j = 1; j < vec.size(); ++j) {
		cout << vec[j] << " ";
	}

	return 0;
}