#include "iostream"
#include "queue"
#include "tuple"
#include "cstring"
using namespace std;

#define MAX 1001
#define MAX_P 10

int n, m, p;
char board[MAX][MAX];
int pCnt[MAX_P];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int result[MAX_P];
queue <tuple<int, int, int>> Q[MAX_P];
int isMove;

void bfs(int v, queue <tuple<int, int, int>>* nextq) {
	while (!Q[v].empty()) {
		auto cur = Q[v].front();
		Q[v].pop();
		if (get<2>(cur) == pCnt[v]) {
			nextq->push({ get<0>(cur), get<1>(cur), 0 });
			continue;
		}
		for (int i = 0; i < 4; i++) {
			int nx = get<0>(cur) + dx[i];
			int ny = get<1>(cur) + dy[i];
			int nc = get<2>(cur) + 1;
			//if (nc > pCnt[board[get<0>(cur)][get<1>(cur)] - '0']) continue;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] != '.') continue;
			board[nx][ny] = board[get<0>(cur)][get<1>(cur)];
			Q[v].push({nx, ny, nc});
			isMove = 1;
		}
	}
}

int main() {
	cin >> n >> m >> p;
	for (int i = 1; i <= p; i++) {
		cin >> pCnt[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] != '.' && board[i][j] != '#') {
				Q[board[i][j] - '0'].push({ i, j, 0 });
			}
		}
	}

	int cnt = 0;
	while (1) {
		isMove = 0;
		for (int v = 1; v <= p; v++) {
			queue <tuple<int, int, int>> nextq;
			bfs(v, &nextq);
			Q[v] = nextq;
		}
		if (!isMove) break;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//cout << board[i][j] << " ";
			if (board[i][j] >= '1' && board[i][j] <= '9') {
				result[board[i][j] - '0']++;
			}
		}
		//cout << endl;
	}

	for (int i = 1; i <= p; i++) {
		cout << result[i] << " ";
	}

	return 0;
}