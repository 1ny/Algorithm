#include <iostream>
#include <string>
#include <vector>

#define MAX 101

using namespace std;
int win[MAX][MAX];

int solution(int n, vector<vector<int>> results) {
    ios::sync_with_stdio();
    cin.tie(0);
    
    int answer = 0;
    
    for(auto a : results) {
        win[a[0]][a[1]] = 1;
    }
    
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            if(k == i) continue;
            if(!win[i][k]) continue;
            for(int j=1; j<=n; j++) {
                if(win[k][j]) win[i][j] = 1;
            }
        }
    }
    
    for(int i=1; i<=n; i++) {
        int cnt = 0;
        for(int j=1; j<=n; j++) {
            if(i == j) continue;
            if(win[i][j] || win[j][i]) cnt++;
        }
        if(cnt == n-1) answer++;
    }
    
    return answer;
}