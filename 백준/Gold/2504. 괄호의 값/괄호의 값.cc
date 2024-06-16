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

#define X first
#define Y second

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;

	getline(cin, str);

	stack<pair<char, int>> s;

	int ans = 0; 

	for (int i = 0; i < str.size(); ++i) {

		if (s.empty()) {
			if (str[i] == ')' || str[i] == ']') {
				cout << 0;
				return 0;
			}
			else {
				s.push({ str[i],0 });
			}
		}

		else if (str[i] == '(' || str[i] == '[') {
			s.push({ str[i],0 });
		}

		else if (str[i] == ')') {

			if (s.top().X == '[') {
				cout << 0;
				return 0;
			}

			else if (s.top().X == '(') { //() 완성

				if (s.size() == 1) { //스택에 남은게 ( 하나일때
					if (s.top().Y == 0) { //만약 0이면 -> 안에 들어있던게 없을 경우
						ans += 2; //바로 2 더하기
					}
					else { //0이 아닐때 -> 안에 들어있던게 있고 pop된 경우
						ans += 2 * s.top().Y; //ans에 안에 들어있던 것들 * 2 더하기
					}
					s.pop(); //이후 pop -> empty
				}

				else { //스택에 남은게 더 있을 때 -> 감싸져있는 상태
					if (s.top().Y == 0) { //안에 들어있던게 없는 상태
						s.pop();
						s.top().Y += 2; //팝하고 그 전 괄호에 2더하기
					}
					else { //안에 들어있던게 있던 상태
						int tmp = s.top().Y;
						s.pop();
						s.top().Y += 2 * tmp; //그 전 괄호에 지금까지 계산 *2 더하기
					}
				}
			}
		}

		else if (str[i] == ']') {
			if (s.top().X == '(') {
				cout << 0;
				return 0;
			}
			else if(s.top().X == '[') { //[] 완성
				if (s.size() == 1) { //스택에 남은게 ( 하나일때
					if (s.top().Y == 0) { //만약 0이면 -> 안에 들어있던게 없을 경우
						ans += 3; //바로 2 더하기
					}
					else { //0이 아닐때 -> 안에 들어있던게 있고 pop된 경우
						ans += 3 * s.top().Y; //ans에 안에 들어있던 것들 * 2 더하기
					}
					s.pop(); //이후 pop -> empty
				}

				else { //스택에 남은게 더 있을 때 -> 감싸져있는 상태
					if (s.top().Y == 0) { //안에 들어있던게 없는 상태
						s.pop();
						s.top().Y += 3; //팝하고 그 전 괄호에 2더하기
					}
					else { //안에 들어있던게 있던 상태
						int tmp = s.top().Y;
						s.pop();
						s.top().Y += 3 * tmp; //그 전 괄호에 지금까지 계산 *2 더하기
					}
				}
			}
		}

	}

	if (!s.empty()) {
		cout << 0;
		return 0;
	}
	else {
		cout << ans;
		return 0;
	}

}
