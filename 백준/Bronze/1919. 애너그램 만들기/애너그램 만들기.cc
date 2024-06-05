#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <set>
#include <algorithm>
#define endl '\n'

using namespace std;

typedef long long ll;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s1, s2;
	cin >> s1;
	cin >> s2;

	int len_1 = s1.size();
	int len_2 = s2.size();

	
	if (len_1 != len_2) {
		string tmp = (len_1 > len_2) ? s1 : s2;
		string tmpm = (len_1 < len_2) ? s1 : s2;
		s1 = tmp;
		s2 = tmpm;
	}


	int array[27] = {};

	int count = 0;

	for (const char& c : s1) {
		array[c - 'a']++;
	}

	for (const char& c : s2) {
		if (array[c - 'a'] > 0) {
			array[c - 'a']--;
		}
		else {
			count++;
		}
	}

	int srt_size = s2.size();

	int accessible_size = srt_size - count; //짧은 문자열 기준 긴 문자열에 속해있는 문자열의 길이

	int diff = s1.size() - accessible_size;

	cout << diff + count;
	return 0;
}