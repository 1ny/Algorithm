#include <bits/stdc++.h>
using namespace std;

#define MAX 300001
vector<int> adj[MAX];
vector<int> indegree(MAX, 0);
queue<int> q;

long long solution(vector<int> a, vector<vector<int>> edges) {
    int n = a.size();
    long long answer = 0;

    // ✅ 초기화 (중요!)
    for(int i=0;i<n;i++) adj[i].clear();
    fill(indegree.begin(), indegree.begin()+n, 0);
    while(!q.empty()) q.pop();

    long long sum = 0;
    for(int i=0;i<n;i++) sum += a[i];
    if(sum != 0) return -1;

    for(auto &e : edges) {
        int u = e[0], v = e[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
        indegree[u]++; indegree[v]++;
    }

    for(int i=0;i<n;i++)
        if(indegree[i] == 1) q.push(i);

    vector<long long> w(n);
    for(int i=0;i<n;i++) w[i] = a[i];

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        if(indegree[cur] == 0) continue; // 이미 제거된 노드면 스킵

        int nxt = -1;
        for(int c : adj[cur]) {
            if(indegree[c] > 0) { nxt = c; break; } // 살아있는 이웃 1개
        }

        // ✅ 마지막 노드(부모 없음)
        if(nxt == -1) { indegree[cur] = 0; continue; }

        answer += llabs(w[cur]);
        w[nxt] += w[cur];
        w[cur] = 0;

        indegree[cur] = 0;          // ✅ 제거 표시
        if(--indegree[nxt] == 1) q.push(nxt);
    }

    return answer;
}
