#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define MAX 201
#define X first
#define Y second

queue <int> q;
int visited[MAX];

void dfs(int n, int cur, vector<vector<int>> computers) {
    visited[cur] = 1;
    
    for(int next=0; next < n; next++) {
        if(computers[cur][next] && !visited[next]) {
            dfs(n, next, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0; i<n; i++) {
        if(visited[i]) continue;
        dfs(n, i, computers);
        answer++;
    }
    
    return answer;
}
/*
1 1 0
1 1 0
0 0 1

1 1 0
1 1 1
0 1 1

1 1 0 0
1 1 0 0
0 0 1 0
0 0 0 1

1 1 0 0
1 1 1 0
0 1 1 0
0 0 0 1
*/