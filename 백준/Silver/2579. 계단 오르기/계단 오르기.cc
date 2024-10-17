#include <iostream>
#include <vector>

#define X first
#define Y second
using namespace std;

int stair[302];
int sumScore[302][3];
int n;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for(int i = 1; i<=n; ++i) cin >> stair[i];

    if(n == 1) {
        cout << stair[1];
        return 0;
    }

    sumScore[1][1] = stair[1];
    sumScore[1][2] = 0;
    sumScore[2][1] = stair[2];
    sumScore[2][2] = stair[1] + stair[2];

    for(int i = 3; i<=n; ++i) {
        sumScore[i][1] = max(sumScore[i-2][1],sumScore[i-2][2]) + stair[i];
        sumScore[i][2] = sumScore[i-1][1] + stair[i]; 
    }

    cout << max(sumScore[n][1],sumScore[n][2]);
    return 0;
}