#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int findLevel(int n) {
	
	int count = 0;
	
	int num = 0;

	for (int i = 1; num<n; ++i) {
		num += i;
		count++;
	}

	return count;
}

int main() {
	int x;
	cin >> x;

	int level = 0;

	int num = 0;

	int orderInLevel;


	for (int i = 1; num < x; ++i) {
		level++;
		num += i;
	}

	int sumBeforeLevel = 0;

	for (int i = 1; i < level; ++i) {
		sumBeforeLevel += i;
	}

	orderInLevel = x - sumBeforeLevel; //레벨 안에서의 순서. 1이 첫번째

	int denom, numer;

	if (level % 2 == 0) { //레벨이 짝수일때, 첫 시작하는 분자는 레벨과 같음
		numer = 1;
		denom = level;
		
		for (int i = 1; i < orderInLevel; ++i) {
			denom--;
			numer++;
		}
		cout << numer << "/" << denom;
		return 0;
	}
	else { //홀수이면, 분모가 레벨과 같음
		numer = level;
		denom = 1;

		for (int i = 1; i < orderInLevel; ++i) {
			denom++;
			numer--;
		}
		cout << numer << "/" << denom;
		return 0;
	}
}
