#include <iostream>
#include <deque>
#include <vector>
#include <cmath>
using namespace std;


int main() {
	string oct;
	cin >> oct;
	
	deque<char> deq;

	vector<int> vec;

	for (size_t i = 0; i < oct.size(); ++i) {
		deq.push_back(oct[i]);
	}

	

	while (deq.size() % 3 != 0) {
		deq.push_front('0');
	}

	int count = 0;

	int sum = 0;

	for (size_t i = 0; i < deq.size(); ++i) {
		if (deq[i] == '1') {
			int s = 2 - i % 3;
			sum += pow(2, s);
		}
		count++;
		if (count % 3 == 0) {
			vec.push_back(sum);
			sum = 0;
		}
	}

	for (const int& i : vec) {
		cout << i;
	}
	return 0;
}
