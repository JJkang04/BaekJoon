#include <iostream>
#include <vector>
using namespace std;



int main() {
	
	int n;
	cin >> n;

	vector<int> vec = { 0,1 };

	for (int i = 2; i < n+1; ++i) {
		vec.push_back(vec[i - 1] + vec[i - 2]);
	}
	cout << vec[n];
}