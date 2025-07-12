#include "iostream"
#include "vector"
#include "queue"
#include "string.h"
using namespace std;

#define MAX 102

int n, m;
vector<int> adj[MAX];
int dist[MAX];
int bacon[MAX];
int result = 999999999;
int result_mem;

void bfs(int st) {
	queue<int> q;
	q.push(st);
	dist[st] = 0;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (int i = 0; i < adj[cur].size(); i++) {
			int nxt = adj[cur][i];
			if (dist[nxt] >= 0 && dist[nxt] <= dist[cur] + 1) continue;
			q.push(nxt);
			dist[nxt] = dist[cur] + 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		bacon[st] += dist[i];
	}

	if (bacon[st] < result) {
		result = bacon[st];
		result_mem = st;
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

	for (int i = 1; i <= n; i++) {
		memset(dist, -1, sizeof(dist));
		bfs(i);
	}

	cout << result_mem;

	return 0;
}