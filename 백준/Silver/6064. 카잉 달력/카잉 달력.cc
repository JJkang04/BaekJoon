#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define X first
#define Y second
using namespace std;

int M, N, x, y;

int KaingCalender(int M, int N, int x, int y) {
    while (x <= M * N) {
        if ((x - 1) % N + 1 == y) {
            return x;
        }
        x += M;
    }
    return -1;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;  
    cin >> t;

    for(int i = 0; i < t; ++i) {
        cin >> M >> N >> x >> y;

        int ans;

        ans = KaingCalender(M,N,x,y);

        cout << ans << '\n';
    }

    
    return 0;
}