#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int M, N, H;
int box[100][100][100];
int days[100][100][100];

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

bool isValid(int x, int y, int z) {
    return x >= 0 && x < M && y >= 0 && y < N && z >= 0 && z < H;
}

int main() {
    cin >> M >> N >> H;
    
    queue<tuple<int, int, int>> q;
    bool allRipe = true;

    for (int h = 0; h < H; ++h) {
        for (int n = 0; n < N; ++n) {
            for (int m = 0; m < M; ++m) {
                cin >> box[h][n][m];
                if (box[h][n][m] == 1) {
                    q.push({m, n, h});
                    days[h][n][m] = 0;
                } else if (box[h][n][m] == 0) {
                    allRipe = false;
                }
            }
        }
    }

    if (allRipe) {
        cout << 0 << endl;
        return 0;
    }

    int maxDays = 0;

    while (!q.empty()) {
        auto [x, y, z] = q.front();
        q.pop();

        for (int i = 0; i < 6; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if (isValid(nx, ny, nz) && box[nz][ny][nx] == 0) {
                box[nz][ny][nx] = 1;
                days[nz][ny][nx] = days[z][y][x] + 1;
                maxDays = max(maxDays, days[nz][ny][nx]);
                q.push({nx, ny, nz});
            }
        }
    }

    for (int h = 0; h < H; ++h) {
        for (int n = 0; n < N; ++n) {
            for (int m = 0; m < M; ++m) {
                if (box[h][n][m] == 0) {
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
    }

    cout << maxDays << endl;
    return 0;
}
