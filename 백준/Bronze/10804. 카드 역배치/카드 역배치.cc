#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>
#define endl '\n'

using namespace std;

typedef long long ll;

int main() {

	int arr[21] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };

	for (int i = 0; i < 10; ++i) {
		int start, end;
		cin >> start >> end;

		int diff = end - start;

		if (diff % 2 == 0) { //카드 갯수는 홀수
			for (int j = 0; j < diff/2; ++j) {
				int temp = arr[end - j];
				arr[end - j] = arr[start + j];
				arr[start + j] = temp;
			}
		}

		else if (diff % 2 == 1) { //카드 갯수는 짝수
			 for (int j = 0; j < (diff+1) / 2; ++j) {
				int temp = arr[end - j];
				arr[end - j] = arr[start + j];
				arr[start + j] = temp;
			 }
		}
	}

	for (int k = 1; k < 21; ++k) {
		cout << arr[k] << ' ';
	}

	return 0;
}