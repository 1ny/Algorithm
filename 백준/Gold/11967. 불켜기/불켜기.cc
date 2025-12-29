#include "iostream"
#include "vector"
#include "queue"
#include "cstring"
using namespace std;

#define MAX_N 101
#define X first
#define Y second

int board[MAX_N][MAX_N]; // 0: 꺼짐, 1: 켜짐
int visited[MAX_N][MAX_N];
int N, M;
vector<pair<int, int>> v[MAX_N][MAX_N];
queue<pair<int, int>> q;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int result;

// 이동할 때마다 불킬 수 있는 방 불 키기
int TurnOn(int x, int y) {
	int onFlg = 0;
	while (!v[x][y].empty()) {
		pair<int, int> avail = v[x][y].back();
		//cout << avail.first << " " << avail.second << endl;
		board[avail.first][avail.second] = 1;
		v[x][y].pop_back();
		onFlg = 1;
	}

	return onFlg;
}

// 이동할 수 있는 칸 이동하기
void bfs() {
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int d = 0; d < 4; d++) {
			int nx = cur.X + dx[d];
			int ny = cur.Y + dy[d];

			if (nx <= 0 || ny <= 0 || nx > N || ny > N) continue;
			if (!board[nx][ny] || visited[nx][ny]) continue;
			q.push({ nx, ny });
			visited[nx][ny] = 1;
			if (TurnOn(nx, ny)) {
				memset(visited, 0, sizeof(visited));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio();
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		v[x][y].push_back({ a,b });
	}

	board[1][1] = 1;
	TurnOn(1, 1);
	q.push({ 1,1 });

	bfs();
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			//cout << board[i][j] << " ";
			if (board[i][j]) result++;
		}
		//cout << endl;
	}

	cout << result;

	return 0;
}
