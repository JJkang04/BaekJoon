#include <iostream>
#include <vector>
using namespace std;



int main() {
	
	int E, S, M;
	cin >> E >> S >> M;

	int e = 1, s = 1, m = 1;

	int year = 1;

	while (true) {
		if (E == e && S == s && M == m) {
			break;
		}
			year++;
			
			if (e == 15) {
				e = 1;
			}
			else {
				e++;
			}

			if (s == 28) {
				s = 1;
			}
			else {
				s++;
			}

			if (m == 19) {
				m = 1;
			} 
			else {
				m++;
			}
	}
	cout << year;
	return 0;
}