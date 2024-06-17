#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <set> 
#include <algorithm>
#include <list>
#include <stack>
#include <queue>
#define endl '\n'

typedef long long ll;

using namespace std;
#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용
int board[502][502];
bool vis[502][502]; // 해당 칸을 방문했는지 여부를 저장

int n, m; // n = 행의 수, m = 열의 수

int dx[4] = { 1,0,-1,0 };

int dy[4] = { 0,1,0,-1 }; // 상하좌우 네 방향을 의미

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;

    int k;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    int countD = 0;
    int maxA = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == 0 || vis[i][j]) continue; //보드가 0이거나 이미 방문한 칸이면 continue
            
            int count = 1; //그림의 크기를 뒤의 while문을 통해 구함.
            
            countD++; //만약 for문이 진행이 되면, 그림이 하나 더 만들어진 것.
            
            vis[i][j] = 1;

            
            queue<pair<int, int>> Q;

            Q.push({ i,j });

            while (!Q.empty()) {
                pair<int, int> cur = Q.front(); Q.pop();
                int nx, ny;                    
                for (int dir = 0; dir < 4; ++dir) {
                    nx = dx[dir] + cur.X;
                    ny = dy[dir] + cur.Y;
                    if (board[nx][ny] == 0 || vis[nx][ny]) continue;
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    vis[nx][ny] = 1;
                    Q.push({ nx,ny });
                    count++;
                }
            }

            if (count > maxA) {
                maxA = count;
            }

        }
    }

    cout << countD << '\n' << maxA;
    return 0;
}