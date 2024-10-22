#include <iostream>
#include <queue>
#include <vector>
#include <string>

#define X first
#define Y second
using namespace std;

int funD(int regi) {
    if (regi >= 5000) {
        return regi * 2 % 10000;
    } else {
        return regi * 2;
    }
}

int funS(int regi) {
    if (regi == 0) {
        return 9999;
    } else {
        return regi - 1;
    }
}

int funL(int regi) {
    
    int d1 = (regi / 1000) % 10;

    int d2 = (regi / 100) % 10;

    int d3 = (regi / 10) % 10;

    int d4 = regi % 10;

    return d2 * 1000 + d3 * 100 + d4 * 10 + d1;
}

int funR(int regi) {
    
    int d1 = (regi / 1000) % 10;

    int d2 = (regi / 100) % 10;

    int d3 = (regi / 10) % 10;

    int d4 = regi % 10;


    return d4 * 1000 + d1 * 100 + d2 * 10 + d3;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int A, B;
        cin >> A >> B; // A는 초기 값, B는 최종 값

        bool vis[10000] = {false};

        queue<pair<int, string>> Q;
        Q.push({A, ""});

        vis[A] = true;

        while (true) {
            pair<int, string> cur = Q.front();
            Q.pop();

            int D, S, L, R;
            
            D = funD(cur.X);
            
            if(D == B) {
                cout << cur.Y + "D" << '\n';
                break;
            }
            
            if(!vis[D]) {
                vis[D] = true;
                Q.push({D,cur.Y+"D"});
            }

            S = funS(cur.X);
            
            if(S == B) {
                cout << cur.Y + "S" << '\n';
                break;
            }

            if(!vis[S]) {
                vis[S] = true;
                Q.push({S,cur.Y+"S"});
            }
            
            L = funL(cur.X);
            
            if(L == B) {
                cout << cur.Y + "L" << '\n';
                break;
            }
            
            if(!vis[L]) {
                vis[L] = true;
                Q.push({L, cur.Y + "L"});
            }
            
            R = funR(cur.X);
            
            if(R == B) {
                cout << cur.Y + "R" << '\n';
                break;
            }

            if(!vis[R]) {
                vis[R] = true;
                Q.push({R,cur.Y+"R"});
            }
        }
    }

    return 0;
}