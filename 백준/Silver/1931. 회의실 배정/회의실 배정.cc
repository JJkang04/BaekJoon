#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> vec(n);

    for (int i = 0; i < n; i++) {
        cin >> vec[i].first >> vec[i].second;
    }
    
    sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second < b.second;
        });

    int count = 0;
    int time = 0;

    for (auto& meeting : vec) {
        if (meeting.first >= time) {
            time = meeting.second;
            count++;
        }
    }

    cout << count;

    return 0;
}