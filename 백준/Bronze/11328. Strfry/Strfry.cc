#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>
#define endl '\n'

using namespace std;

typedef long long ll;



int n;

int main() {
	
	cin >> n;

	for (int i = 0; i < n; ++i) {
		string f, s;
		int alpha[26] = {};
		cin >> f >> s;
		if (f.size() != s.size()) {
			cout << "Impossible" << '\n';
			continue;
		}
		bool strfry = true;
		for (const char& c : f) {
			alpha[c - 'a']++;
		}
		for (const char& c : s) {
			if (alpha[c - 'a'] == 0)
			{
				strfry = false;
			}
			else {
				alpha[c - 'a']--;
			}
		}
		if (strfry) {
			cout << "Possible" << '\n';
		}
		else {
			cout << "Impossible" << '\n';
		}
	}


	return 0;
	
}