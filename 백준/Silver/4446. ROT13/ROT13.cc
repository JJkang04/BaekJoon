#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#define endl '\n'

using namespace std;

typedef long long ll;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string str;


	char vow[9] = { 'a' ,'i' ,'y', 'e' ,'o' ,'u','a','i','y'};

	char con[30] = { 'b', 'k' ,'x', 'z' ,'n', 'h' ,'d' ,'c', 'w', 'g', 'p', 'v' ,'j', 'q' ,'t' ,'s', 'r', 'l', 'm','f','b','k','x','z','n','h','d','c','w','g'};

	while (getline(cin, str)) {
		for (int i = 0; i < str.size(); ++i) {
			if (isalpha(str[i]) == false) { //알파벳인지 확인
				continue;
			}

			bool is_upper = false;
			
			if (isupper(str[i])) {
				is_upper = true;
				str[i] = tolower(str[i]);
			}
			bool is_vowel = false;
			
			if (str[i] == 'a' || str[i] == 'i' || str[i] == 'y' || str[i] == 'e' || str[i] == 'o' || str[i] == 'u') {
				is_vowel = true;
			}
			if (is_vowel) { //모음일 경우
				for (int j = 0; j < 6; ++j) {
					if (str[i] == vow[j]) {
						str[i] = vow[j + 3];
						break;
					}
				}
			}
			else { //자음일 경우
				for (int j = 0; j < 20; ++j) {
					if (str[i] == con[j]) {
						str[i] = con[j + 10];
						break;
					}
				}
			}

			if (is_upper) {
				str[i] = toupper(str[i]);
			}
		}
		cout << str << '\n';
	}
	return 0;
}