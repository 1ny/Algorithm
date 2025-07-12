#include "iostream"
#include "vector"
#include "stack"
#include "string.h"
using namespace std;

#define MAX 20002

int k;
int v, e;
vector<int> adj[MAX];
int depth[MAX];
bool is_binGraph = true;
int cycle_num;

// 사이클이면서 사이클 정점 개수가 홀수일 때

void dfs(int st) {
	stack<int> s;
	s.push(st);
	depth[st] = 0;
	while (!s.empty()) {
		auto cur = s.top();
		s.pop();
		for (int i = 0; i < adj[cur].size(); i++) {
			int nxt = adj[cur][i];
			if (depth[nxt] >= 0 && (depth[cur] + 1) - depth[nxt] != 2) {
				cycle_num = (depth[cur] + 1) - depth[nxt];
				if (cycle_num % 2 == 1) is_binGraph = false;
				//cout << "cycle!!(" << nxt << ") -> ";
				continue;
			}
			if (depth[nxt] >= 0) continue;
			//cout << nxt << " -> ";
			s.push(nxt);
			depth[nxt] = depth[cur] + 1;
		}
	}
}
//1 2 3 4 5 6 7
//0 1

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> k;
	while (k--) {
		is_binGraph = true;
		memset(depth, -1, sizeof(depth));
		cin >> v >> e;
		for (int i = 1; i <= v; i++) {
			adj[i].clear();
		}
		for (int i = 0; i < e; i++) {
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		for (int i = 1; i <= v; i++) {
			if (depth[i] >= 0) continue;
			//cout << i << " -> ";
			dfs(i);
			//cout << endl;
		}

		if (is_binGraph) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}