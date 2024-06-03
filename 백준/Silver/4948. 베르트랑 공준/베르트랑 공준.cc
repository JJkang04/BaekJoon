#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#define endl '\n'

using namespace std;

typedef long long ll;


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	while (true) {
		int n;
		cin >> n;
		
		if (n == 0) {
			break;
		}

		vector<bool> isPrime(2*n+1, true); //탐색 범위가 2n까지이므로 벡터의 크기는 2n+1
		
		isPrime[0] = isPrime[1] = false; //0과 1은 기본적으로 false 처리 - 에라토스테네스의 체

		int countPrime = 0;

		for (ll i = 2; i <= 2 * n; ++i) {
			if (isPrime[i]) { //여기서 true인 것이 소수. 이 수의 배수(2n보다 작거나 같은)을 false처리
				if (i > n) { //n보다 큰 것을 count. 어차피 끝 범위는 2n으로 정해져 있기 때문에.
					countPrime++;
				}
				for (ll j = i * i; j <= 2 * n; j += i) { //제곱하면 int 범위보다 커질 수 있기 때문에 long long으로 지정.
					isPrime[j] = false;
				}
			}
		}
		cout << countPrime << '\n';
	}

	return 0;
}
