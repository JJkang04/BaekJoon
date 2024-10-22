#include <iostream>
#include <queue>
#include <vector>
#include <string>

#define X first
#define Y second
using namespace std;

int n;

int dx[4] = {-1,0,1,0};

int dy[4] = {0,1,0,-1};

vector<vector<char>> board;

// 적록색약 아닌 일반인
int NotGR(vector<vector<char>>& board) {

    vector<vector<bool>> vis(n,vector<bool>(n,false));
    int ans = 0;

    for(int i = 0; i < n; ++i ) {
        for(int j = 0; j < n; ++j) {
            if(vis[i][j]) continue;
            queue<pair<int,int>> Q;
            Q.push({i,j});

            while(!Q.empty()) {
                pair<int,int> cur = Q.front(); Q.pop();
                
                if(vis[cur.X][cur.Y]) continue;
                vis[cur.X][cur.Y] = true;

                for(int i = 0; i < 4; ++i) {
                    int nx = cur.X + dx[i];
                    int ny = cur.Y + dy[i];

                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(vis[nx][ny]) continue;
                    if(board[nx][ny] == board[cur.X][cur.Y]) {
                        Q.push({nx,ny});
                    }
                }
            }
            ans++;
        } 
    }
    return ans;
}

int GR(vector<vector<char>>& board) {

    vector<vector<bool>> vis(n, vector<bool>(n,false));

    int ans = 0;

    for(int i = 0; i < n; ++i ) {
        for(int j = 0; j < n; ++j) {
            if(vis[i][j]) continue;
            queue<pair<int,int>> Q;
            Q.push({i,j});

            while(!Q.empty()) {
                pair<int,int> cur = Q.front(); Q.pop();
                
                if(vis[cur.X][cur.Y]) continue;
                vis[cur.X][cur.Y] = true;

                for(int i = 0; i < 4; ++i) {
                    int nx = cur.X + dx[i];
                    int ny = cur.Y + dy[i];

                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(vis[nx][ny]) continue;
                    if(board[nx][ny] == board[cur.X][cur.Y]) {
                        Q.push({nx,ny});
                    }
                    else if(board[cur.X][cur.Y] == 'R' && board[nx][ny] == 'G') {
                        Q.push({nx,ny});
                    }
                    else if(board[cur.X][cur.Y] == 'G' && board[nx][ny] == 'R') {
                        Q.push({nx,ny});
                    }
                }
            }
            ans++;
        } 
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    board.resize(n, vector<char>(n));

    for(int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        for(int j = 0; j < n; ++j) {
            board[i][j] = str[j];
        }
    }

    cout << NotGR(board) << " " << GR(board);

    return 0;
}