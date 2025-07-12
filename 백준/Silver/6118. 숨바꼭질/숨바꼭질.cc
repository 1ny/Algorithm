#include "iostream"
#include "vector"
#include "queue"
#include "string.h"
using namespace std;

#define MAX 20002

int n, m;
vector<int> adj[MAX];
int dist[MAX];

void bfs() {
	queue<int> q;
	q.push(1);
	dist[1] = 0;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (int i = 0; i < adj[cur].size(); i++) {
			int nxt = adj[cur][i];
			if (dist[nxt] >= 0) continue;
			q.push(nxt);
			dist[nxt] = dist[cur] + 1;
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

	memset(dist, -1, sizeof(dist));
	bfs();

	int max_dist = 0;
	int max_idx = 0;
	int max_cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (dist[i] > max_dist) {
			max_dist = dist[i];
			max_idx = i;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (dist[i] == max_dist) max_cnt++;
	}

	cout << max_idx << " " << max_dist << " " << max_cnt;

	return 0;
}