#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second

int n, k;

int board[100002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	fill(board, board + 100001, -1);

	queue<int> q;

	q.push(n);
	
	board[n] = 0;

	while (board[k] == -1) {
		int cur = q.front(); q.pop();
		for (int i : { cur - 1, cur + 1, 2 * cur }) {
			if (i < 0 || i>100000) continue;
			if (board[i] > 0) continue;
			board[i] = board[cur] + 1;
			q.push(i);
		}
	}
	cout << board[k];
}