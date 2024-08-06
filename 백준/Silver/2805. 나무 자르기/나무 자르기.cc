#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> vec(n);

    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    int low = 0;
    int high = vec.back();
    int ans = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        long long total = 0;

        for (const int& i : vec) {
            if (i > mid) {
                total += i - mid;
            }
        }

        if (total >= m) {
            ans = mid; // 현재 높이로도 충분히 얻을 수 있음
            low = mid + 1; // 더 높은 높이로 시도
        } else {
            high = mid - 1; // 높이를 낮춰야 함
        }
    }

    cout << ans;
    return 0;
}
