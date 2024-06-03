#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;



int main() {
	
	int avr;

	map<int, int > map;

	int sum = 0;

	for (int i = 0; i < 10; ++i) {
		int num;
		cin >> num; 
		sum += num;
		map[num]++;
	}

	avr = sum / 10;

	vector<pair<int, int>> freq(map.begin(), map.end());


	sort(freq.begin(), freq.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
		return a.second < b.second;	
		});

	cout << avr << '\n';
	cout << freq.rbegin()->first;



	return 0;
}