#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	int k;
	cin >> k;

	int stuNum;

	for (int i = 0; i < k; ++i) {
		cin >> stuNum;
		vector<int> vec(stuNum);
		for (int j = 0; j < stuNum; ++j) {
			cin >> vec[j];
		}

		sort(vec.begin(), vec.end(), greater<int>());

		int gap = 0;

		for (int j = 0; j < stuNum - 1; ++j) {
			if (vec[j] - vec[j+1] > gap) {
				gap = vec[j] - vec[j+1];
			}
		}

		cout << "Class " << i + 1 << '\n';
		cout << "Max " << vec[0] << ", " << "Min " <<
			vec.back() << ", " << "Largest gap " << gap << '\n';



	}
 }