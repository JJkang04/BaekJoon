#include <iostream>
using namespace std;



int main() {
	
	int max_num = 0;

	int numOfP = 0;

	for (int i = 0; i < 10; ++i) {
		int offnum, onnum;
		
		cin >> offnum >> onnum;

		numOfP -= offnum;
		
		if (numOfP > max_num) {
			max_num = numOfP;
		}
		
		numOfP += onnum;
		
		if (numOfP > max_num) {
			max_num = numOfP;
		}


	}
	
	cout << max_num;

	return 0;
}