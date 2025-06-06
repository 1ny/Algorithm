#include "iostream"
#include "algorithm"
#include "queue"
using namespace std;

#define X first
#define Y second

struct point {
	int x;
	int y;
};

int t, n;
point sang;
point store[100];
point festival;
int visited[100];

int bfs() {
	queue<pair<int, int>> Q;
	Q.push({ sang.x, sang.y });
	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		if (abs(festival.x - cur.X) + abs(festival.y - cur.Y) <= 1000) return 1;
		for (int i = 0; i < n; i++) {
			if (visited[i]) continue;
			if (abs(cur.X - store[i].x) + abs(cur.Y - store[i].y) <= 1000) {
				visited[i] = 1;
				Q.push({ store[i].x, store[i].y });
			}
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while (t--) {
		fill(visited, visited + 100, 0);
		cin >> n;
		cin >> sang.x >> sang.y;
		for (int i = 0; i < n; i++) {
			cin >> store[i].x >> store[i].y;
		}
		cin >> festival.x >> festival.y;

		int result = bfs();
		if (result) cout << "happy" << endl;
		else cout << "sad" << endl;
	}

	return 0;
}
