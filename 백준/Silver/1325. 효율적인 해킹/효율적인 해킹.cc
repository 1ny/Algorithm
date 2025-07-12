#include "iostream"
#include "vector"
#include "queue"
#include "string.h"
using namespace std;

#define MAX 10002

int n, m;
vector<int> adj[MAX];
int vis[MAX];
int num[MAX];
int maxCnt;

void bfs(int st) {
	int cnt = 0;
	queue<int> q;
	q.push(st);
	vis[st] = 1;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (int i = 0; i < adj[cur].size(); i++) {
			int nxt = adj[cur][i];
			if (vis[nxt]) continue;
			q.push(nxt);
			vis[nxt] = 1;
			cnt++;
		}
	}

	num[st] = cnt;
	if (num[st] > maxCnt) maxCnt = num[st];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		memset(vis, 0, sizeof(vis));
		bfs(i);
	}

	for (int i = 1; i <= n; i++) {
		if (num[i] == maxCnt) cout << i << " ";
	}

	return 0;
}