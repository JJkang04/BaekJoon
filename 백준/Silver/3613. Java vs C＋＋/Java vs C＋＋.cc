#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	getline(cin, str);

	/* 대문자가 속해있으면, 일단 c++ 형식이 아님. 대문자가 있는데, 언더바가 있으면 에러,
	대문자가 없으면, c++ 확정. 대문자가 있고, 언더바도 없고, 첫글자가 소문자면 Java.
	만약 첫글자가 소문자이면 Error */

	int len = str.size();

	vector<int> vec_cap;
	
	vector<int> vec_unb;

	for (int i = 0; i < len; ++i) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			vec_cap.push_back(i);
		}
		if (str[i] == '_') {
			vec_unb.push_back(i);	
		}
	}
	

	if (vec_unb.empty()) {
		if (vec_cap.empty()) { //언더바도 없고, 모두 소문자 -> 그대로 출력하면 됌.
			cout << str;
			return 0;
		}
		else { //언더바는 없지만, 대문자 존재
			if (!(str[0] >= 'a' && str[0] <= 'z')) { //첫번째 글자가 대문자일 때 -> 에러
				cout << "Error!";
				return 0;
			}
			else { //여기까지 만족하면 Java 스타일
				for (int i = 0; i < len; ++i) {//대문자 전에 언더바 넣어주기// aJJ -> a_j_j
					int j = i;
					if (str[j] >= 'A' && str[j] <= 'Z') {
						str.insert(j, "_");
						len++;
						j++;
						str[j] = tolower(str[j]);
					}
				}
				cout << str;			
				return 0;
			}
			

		}
	}

	else if (vec_cap.empty()) {
		 if(vec_unb.empty()) {
			cout << str;
			return 0;
		 }
		 else  { //대문자 없고, 언더바 존재 -> cpp 스타일
			if (*str.rbegin() == '_' || *str.begin() == '_' ) { //처음이나 끝에 언더바-> 에러
				cout << "Error!";
				return 0;
			}
			for (int& i : vec_unb) {
				if (str[i + 1] == '_') { //언더바 다음에 언더바 -> 에러
					cout << "Error!";
					return 0;
				}
				str[i+1] = toupper(str[i + 1]);
			}
			str.erase(remove(str.begin(), str.end(), '_'), str.end());
			cout << str;
			return 0;
		 }
		 
	}

	else {
		cout << "Error!";
		return 0;
	}
}