#include <iostream>
#include <cmath>
#include <string>
using namespace std;

bool isVowel(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

string moduleDiary(const string& input) {
	string result;
	for (size_t i = 0; i < input.length(); ++i) {
		result += input[i];
		if (isVowel(input[i]) && i+2 < input.length() && input[i+1] == 'p' && isVowel(input[i+2])) {
			i += 2;
		}
	}
	return result;
}


int main() {
	string str;
	getline(cin, str);

	string ans = moduleDiary(str);
	cout << ans;
}