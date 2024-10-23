#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define X first
#define Y second
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<vector<int>> graph(n);
    
    for(int i = 0; i<n; ++i) {
        for(int j = 0; j<n; ++j) {
        int num;
        cin >> num;

        if(num == 1) {
            graph[i].push_back(j);
        }
    }
    }

    vector<vector<int>> ans(n, vector<int>(n, 0));

    for(int i = 0; i < n; ++i) {
        //그래프의 i번째 노드가 비어있으면 패스
        if(graph[i].empty()) continue; 

        queue<int> q;

        //i번째 노드에서 갈 수 있는 노드들을 큐에 넣어줌
        for(const int& j : graph[i]) {
            q.push(j);
        }

        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            
            if(ans[i][cur] == 1) continue;

            ans[i][cur] = 1;

            //현재 노드에서 갈 수 있는 노드들을 큐에 넣어줌
            for(const int& j : graph[cur]) {
                q.push(j);
            }
        }
    }

    for(int i = 0; i<n; ++i) {
        for(int j = 0; j<n; ++j) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;

}
