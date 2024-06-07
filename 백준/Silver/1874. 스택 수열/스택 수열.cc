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


stack<int> stk;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;

	cin >> n;

	vector<int> tar_vec(n); //목표 수열 저장 벡터
	vector<char> ans_vec; // 답변 저장 벡터
	vector<int> trash; //pop된  

	for (int i = 0; i < n; ++i) {
		cin >> tar_vec[i];
	}

	int target = 0; //만약 target 보다 큰 숫자가 stk에서 pop되면 수열 만들기 실패

	int num = 1;
	while (true) {
		if (stk.empty()) { //스택이 비어 있으면 num을 push
			stk.push(num++); 
			ans_vec.push_back('+');
		}
		else if(stk.top() > tar_vec[target]) {
			cout << "NO";
			return 0;
		}
		else if(stk.top() == tar_vec[target]) {
			ans_vec.push_back('-');
			target++;
			stk.pop();
			if (target == n) {
				break;
			}
		}
		else {
			stk.push(num++);
			ans_vec.push_back('+');
		}
	}

	for (const char& c : ans_vec) {
		cout << c << '\n';
	}
	
	return 0;

}