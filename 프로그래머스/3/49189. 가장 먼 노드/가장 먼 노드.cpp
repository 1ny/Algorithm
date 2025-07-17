#include <cstring>
#include <vector>
#include <queue>
using namespace std;

#define MAX 20001

vector<int> adj[MAX];
int dist[MAX];
int max_dist;

void bfs() {
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(int i=0; i<adj[cur].size(); i++) {
            int nxt = adj[cur][i];
            if(dist[nxt] >= 0) continue;
            q.push(nxt);
            dist[nxt] = dist[cur] + 1;
            if(dist[nxt] > max_dist) max_dist = dist[nxt];
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    for(int i=0; i<edge.size(); i++) {
        adj[edge[i][0]].push_back(edge[i][1]);
        adj[edge[i][1]].push_back(edge[i][0]);
    }
    
    memset(dist, -1, sizeof(dist));
    bfs();
    
    for(int i=1; i<=n; i++) {
        if(dist[i] == max_dist) answer++;
    }
    
    return answer;
}