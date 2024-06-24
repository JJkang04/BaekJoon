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
#define Y second

int r, c;

string board[1002];

int timeJ[1002][1002];

int timeF[1002][1002];

int dirx[4] = {1,0,-1,0 };
int diry[4] = { 0,1,0,-1 };

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> r >> c;

    

    for (int i = 0; i < r; ++i) {
        fill(timeJ[i], timeJ[i] + c, -1);
        fill(timeF[i], timeF[i] + c, -1);
    }

    for (int i = 0; i < r; ++i) {
        cin >> board[i];
    }
    
    queue<pair<int, int>> F;

    queue<pair<int, int>> J;
    
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (board[i][j] == 'F') {
                F.push({ i,j });
                timeF[i][j] = 0;
            }
            if (board[i][j] == 'J') {
                J.push({ i,j });
                timeJ[i][j] = 0;
            }
        }
    }
     
    while (!F.empty()) {
        pair<int, int> cur = F.front(); F.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = dirx[i] + cur.X;
            int ny = diry[i] + cur.Y;

            if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
            if (board[nx][ny] == '#' || timeF[nx][ny] >= 0) continue;
            timeF[nx][ny] = timeF[cur.X][cur.Y] + 1;
            F.push({ nx,ny });
        }
    }
   
    while (!J.empty()) {
       pair<int,int> cur = J.front(); J.pop();

       for (int i = 0; i < 4; ++i) {
           int nx = cur.X + dirx[i];
           int ny = cur.Y + diry[i];

           if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
               cout << timeJ[cur.X][cur.Y] + 1;
               return 0;
           }

           if (board[nx][ny] == '#' || timeJ[nx][ny] >= 0) continue;
           if (timeF[nx][ny] != -1 && timeF[nx][ny] <= timeJ[cur.X][cur.Y] + 1) continue;

           timeJ[nx][ny] = timeJ[cur.X][cur.Y] + 1;
           J.push({ nx,ny });
       }
    }
    cout << "IMPOSSIBLE";
    return 0;
}