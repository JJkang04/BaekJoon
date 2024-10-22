#include <iostream>
#include <queue>
#include <unordered_set>
#include <cmath>

#define X first
#define Y second
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<int> dp(n + 1, n);
    dp[0] = 0;

    for(int i = 1; i<=n; ++i){
        for(int j = 1; j*j<=i; ++j){
            dp[i] = min(dp[i], dp[i-j*j]+1);
        }
    }

    cout << dp[n];

    return 0;
}