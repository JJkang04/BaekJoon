#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define X first
#define Y second
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> map(n, vector<char>(m));

    vector<vector<bool>> vis(n, vector<bool>(m, false));

    queue<pair<int,int>> Q;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            map[i][j] = s[j];
            if(map[i][j] == 'I'){
                Q.push({i,j});
            }
        }
        
    }

    int cnt = 0;

    while(!Q.empty()) {

        pair<int,int> cur = Q.front(); Q.pop();
        
        if(vis[cur.X][cur.Y]) continue;

        if(map[cur.X][cur.Y] == 'P') {
            cnt++;
        }

        vis[cur.X][cur.Y] = true;

        for(int i = 0; i < 4; ++i) {
            int nx = dx[i] + cur.X;
            int ny = dy[i] + cur.Y;

            if(nx <0 || nx >= n || ny < 0 || ny >= m) continue;
            if(vis[nx][ny] || map[nx][ny] == 'X') continue;

            Q.push({nx,ny});
        }
    }

    if(cnt == 0) {
        cout << "TT";
    }
    else {
        cout << cnt;
    }

    return 0;
}