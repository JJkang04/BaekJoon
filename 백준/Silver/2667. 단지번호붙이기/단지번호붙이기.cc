#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define X first
#define Y second
using namespace std;

vector<vector<int>> Map;

int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

int main() {

    int n;
    cin >> n;

    Map.resize(n,vector<int>(n));

    //모든 집의 위치를 저장하는 큐
    queue<pair<int,int>> Q;

    for(int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        for(int j = 0; j < n; ++j) {
            int k = str[j] - '0';
            Map[i][j] = k;
            if(Map[i][j] == 1) {
                Q.push({i,j});
            }
            }
    }

    //단지 수를 입력하는 벡터
    vector<int> ans;

    //각 집의 방문 여부를 저장하는 벡터
    vector<vector<bool>> vis(n,vector<bool>(n,false));

    while(!Q.empty()) {
        pair<int,int> cur = Q.front(); Q.pop();

        // 방문한 집이면 다음으로 넘어감
        if(vis[cur.X][cur.Y]) continue;


        // 만약 방문하지 않은 집이면, BFS로 그 집과 연결되어 있는 주변 연결 탐색 시작
        else {
            
            // 단지별로 구분해야 하기 때문에, 새로운 큐를 임시로 생성
            queue<pair<int,int>> streakQ;

            streakQ.push({cur.X, cur.Y});

            // 주변에 연결된 새로운 집을 찾을 때마다 +1
            int streak = 0;
            
            vis[cur.X][cur.Y] = true;

            while(!streakQ.empty()) {

            pair<int,int> tempCur = streakQ.front(); streakQ.pop();
            streak++;
            for(int i = 0; i<4; ++i) {
                int nx = dx[i] + tempCur.X;
                int ny = dy[i] + tempCur.Y;

                // 범위 초과 검사
                if(nx <0 || nx >=n || ny < 0 || ny >=n) continue;
                // 집이 맞는지 검사
                if(Map[nx][ny] != 1) continue;
                // 방문한 집인지 검사
                if(vis[nx][ny]) continue;   
                
                // 범위 안, 방문하지 않은 집일 경우 연결되어 있는 집. streakQ에 푸쉬하고 streak++

                streakQ.push({nx,ny});
                vis[nx][ny] = true;
                
            }
            }
            
        ans.push_back(streak);

        }
    }

    sort(ans.begin(),ans.end());

    cout << ans.size() << '\n';

    for(const auto& a : ans) {
        cout << a << '\n';
    }

    return 0;
}