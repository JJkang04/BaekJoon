#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


int main() {
	
	int n;
	cin >> n;
	
	vector<int>	vec(n);

	for (int i = 0; i < n; ++i) {
		cin >> vec[i];
	}

	vector<int> sVec = vec;

	sort(sVec.begin(), sVec.end());

	sVec.erase(unique(sVec.begin(), sVec.end()),sVec.end());

	map<int, int> map;
	for (int i = 0; i < sVec.size(); ++i) {
		map[sVec[i]] = i;
	}

	for (int i = 0; i < n; ++i) {
		cout << map[vec[i]] << " ";
	}
	return 0;
 }