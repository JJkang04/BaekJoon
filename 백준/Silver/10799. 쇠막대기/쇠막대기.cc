#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <set> 
#include <algorithm>
#include <list>
#include <stack>
#include <queue>
#define endl '\n'

#define X first
#define Y second

using namespace std;

typedef long long ll;

deque<char> deq;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;

	getline(cin, str);


	deq.push_back(str[0]);

	int ans = 0;

	int countPipeBefore = 0;

	int countAllPipe = 0;



	for(int i = 1; i<str.size(); ++i) {

		if (deq.empty()) {
			deq.push_back(str[i]);
		}

		else if (str[i] == '(') {
			if (deq.back() == '(') {
				countPipeBefore++;
			}
			else { //back = ')' ->
				deq.push_back(str[i]);
			}
		}

		else { // blank = ')'
			if (deq.back() == '(') {//반드시 레이저
				ans += countPipeBefore;
				deq.push_back(str[i]);
			}

			else { //back = ')', 반드시 파이프 닫
				countPipeBefore--;
				deq.push_back(str[i]);
				countAllPipe++;
			}
		}
	}

	ans += countAllPipe;

	cout << ans;
}
