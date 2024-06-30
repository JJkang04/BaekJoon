#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second

int m, n;

int board[1002][1002];

int dist[1002][1002];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n;

	queue<pair<int, int>> q;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				q.push({ i,j });
			}
			else if (board[i][j] == 0) {
				dist[i][j] = -1;
			}
		}
	}

	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();
		int nx, ny;
		for (int i = 0; i < 4; ++i) {
			nx = dx[i] + cur.X;
			ny = dy[i] + cur.Y;

			if (nx < 0 || ny < 0 || nx >= n|| ny >= m) continue;
			if (dist[nx][ny] >= 0) continue;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			q.push({ nx,ny });
		}
	}

	int ans = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (dist[i][j] == -1) {
				cout << -1;
				return 0;
			}
			ans = max(ans, dist[i][j]);
		}
	}

	cout << ans;
	return 0;
}