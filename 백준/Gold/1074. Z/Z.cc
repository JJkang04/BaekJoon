#include <iostream>
#include <cmath>
using namespace std;

int main() {
	

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int N;

	long long int r, c;
	
	cin >> N >> r >> c;

	r++;
	c++; // 0행 / 0열 다루기 어려움.

	long long int len = pow(2, N); // 한 행과 열의 길이. 사이클 돌 때 마다 1/2


	long long int total = len * len; // 총 블럭의 개수. 사이클 돌 때 마다 1/4


	/* 1/4로 나눠서, 어디에 속하는지 찾기. 그 찾은 부분을 다시 1/4로 나누기.
	나눌때마다 속하지 않는 부분 중에 전 경로에 속하는 블록들 개수 더하기. (지나온 부분)
	*/

	long long int ans = 0; //정답. 지나온 부분에 존재하는 블럭들 플러스

	int quarter = 0; // 1/4로 나눴을 때 속하는 구역
	
	long long int half = len / 2;
	
	while (true) {

		if (r > half && c > half) quarter = 4;
		else if (r > half && c <= half) quarter = 3;
		else if (r <= half && c > half) quarter = 2;
		else if (r <= half && c <= half) quarter = 1;

		switch (quarter) { //quarter에 따라서 지나온 블럭들 더하기
		case 1: 
			ans += 0;
			break;
		case 2: 
			ans += (total / 4); 
			c -= half;
			break;
		case 3: 
			ans += (total / 2); 
			r -= half;
			break;
		case 4: 
			ans += (total * 3 / 4); 
			c -= half; 
			r -= half;
			break;
		}

		total /= 4; // 총 블록 업데이트

		if (total == 1) { // total이 1이면 종료
			break;
		}

		half /= 2;
	}

	cout << ans;
	return 0;
 }