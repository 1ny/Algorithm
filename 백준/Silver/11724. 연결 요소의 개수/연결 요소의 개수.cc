#include "iostream"
#include "vector"
#include "queue"
using namespace std;

#define MAX 1001

int n, m;
vector<int> adj[MAX];
int vis[MAX];
int result;

void bfs() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		result++;
		q.push(i);
		vis[i] = 1;
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (int j = 0; j < adj[cur].size(); j++) {
				if (vis[adj[cur][j]]) continue;
				q.push(adj[cur][j]);
				vis[adj[cur][j]] = 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	//for (int i = 1; i <= n; i++) {
	//	for (int j = 0; j < adj[i].size(); j++) {
	//		cout << adj[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	bfs();

	cout << result;

	return 0;
}