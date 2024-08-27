#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int main() {
	int firstNum, secondNum, firstDem, secondDem;

	cin >> firstNum >> firstDem;
	cin >> secondNum >> secondDem;

	int resultDem; // 더한 분모

	if (firstDem == secondDem) {
		resultDem = firstDem;
	}
		
	else {
		int bigDem = (firstDem > secondDem) ? firstDem : secondDem;

		int smallDem = (firstDem < secondDem) ? firstDem : secondDem;

		if (bigDem % smallDem == 0) {
			resultDem = bigDem;
		}
		else {
			int i = 2;
			while (true) {
				if (bigDem * i % smallDem == 0) {
					break;
				}
				else {
					i++;
				}
			}
			resultDem = bigDem * i;
		}
	}
		int resultNum;

		resultNum = firstNum * (resultDem / firstDem) + secondNum * (resultDem/secondDem);

		int gcdVal = gcd(resultNum, resultDem);

		cout << resultNum / gcdVal << " " << resultDem / gcdVal;
		return 0;

}