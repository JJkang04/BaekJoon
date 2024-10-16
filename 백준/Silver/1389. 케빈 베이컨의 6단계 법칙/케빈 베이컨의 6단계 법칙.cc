#include <iostream>
#include <vector>
#include <queue>

#define X first
#define Y second
using namespace std;

vector<vector<int>> graph;

int n,m;

int kevinBacon(vector<vector<int>>& graph, int Start) {

    //각각의 사람들과의 베이컨 수를 저장하는 벡터
    vector<int> bacon(n+1,0);

    //방문했는지 여부를 저장하는 벡터
    vector<bool> vis(n+1,false);
    vis[Start] = true;

    queue<pair<int,int>> Q;

    for(const auto& a : graph[Start]) {
        Q.push({Start,a});
    }

    while(!Q.empty()) {
        pair<int,int> cur = Q.front(); Q.pop();

        if(vis[cur.Y]) continue;

        else {
            vis[cur.Y] = true;
            bacon[cur.Y] = bacon[cur.X] + 1;

            for(const auto& a : graph[cur.Y]) {
                Q.push({cur.Y,a});
            }

        }

    }
    
    int sum = 0;

    for(const auto& a : bacon) {
        sum+=a;
    }

    return sum;
}   



int main() {

    cin >> n >> m;

    graph.resize(n+1);

    for(int i = 0; i<m; ++i) {
        int a,b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    //베이컨 수를 저장하는 벡터
    vector<int> baconNum(n+1,0);

    for(int i = 1; i<=n; ++i) {

        baconNum[i] = kevinBacon(graph,i);

    }

    int minBacon = baconNum[1];

    int minNum = 0;

    for(int i = n; i>=1; --i) {
        if(baconNum[i] <= minBacon) {
            minBacon = baconNum[i];
            minNum = i;
        }   
    }

    cout << minNum;

    return 0;
}