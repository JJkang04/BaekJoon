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

#define X first
#define Y second

using namespace std;

typedef long long ll;

int n, h;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	cin >> h;

	stack<pair<int, int>> oasis;

	ll ans = 0;

	oasis.push({ h,0 });

	n--;
	////////
	while (n--) {
		cin >> h;
		int count = 0;
		while (!oasis.empty() && oasis.top().first <= h) { //스택에 하나가 들어갔을 때 스택이 비거나, 자기보다 큰 걸 만날때까지 진행
			if (oasis.top().X == h) { //같은 것을 만났을때 우선 처리
				count = oasis.top().Y + 1;
				ans += (oasis.top().Y)+1; //앞에 있던 같은 요소들과의 쌍
				oasis.pop();
			}
			else { //작은 것을 만났을 때
					ans += oasis.top().Y; //만약 자기보다 작은것인데, 중복해서 나온 경우 쌍이 그 중복만큼
					oasis.pop(); //이후 팝
					ans++; //팝했으면 그 요소와 자신의 쌍 하나 추가
			}
		} //종료 : 스택이 비거나 큰 것을 만났을 때
		if (oasis.empty()) {
			oasis.push({ h,count });
		}
		else {
			oasis.push({ h,count });
			ans++;
		}
	}

	cout << ans;

	return 0;
}