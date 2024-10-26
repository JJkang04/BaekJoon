#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define X first
#define Y second
using namespace std;

int dice[6] = {1, 2, 3, 4, 5, 6};

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> snakesAndLadders(101, 0);

    for(int i = 0; i < n + m; ++i) {
        int x, y;
        cin >> x >> y;
        snakesAndLadders[x] = y;
    }

    vector<int> dist(101, -1);

    queue<int> q;

    q.push(1);

    dist[1] = 0;

    while(!q.empty()) {
        int cur = q.front(); q.pop();

        for(int i = 0; i < 6; ++i) {
            int next = cur + dice[i];
            if(next > 100) continue;
            if(snakesAndLadders[next] != 0) {
                next = snakesAndLadders[next];
            }
            if(dist[next] != -1) continue;
            dist[next] = dist[cur] + 1;
            q.push(next);
        }
    }

    cout << dist[100];
    
}
