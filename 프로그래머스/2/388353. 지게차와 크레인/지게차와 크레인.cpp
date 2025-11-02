#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int removed[52][52];
int answer = 0;

int bfs(vector<string> storage, int x, int y) {
    int visited[52][52] = {0,};
    queue<pair<int, int>> q;
    memset(visited, 0, sizeof(visited));
    q.push({x, y});
    visited[x][y] = 1;
    while(!q.empty()) { 
        pair<int,int> cur = q.front(); q.pop();
        int curX = cur.first, curY = cur.second;
        for(int d=0; d<4; d++) {
            int nx = curX + dx[d];
            int ny = curY + dy[d];
            if(!removed[nx][ny] || visited[nx][ny]) continue;
            if(nx <= 0 || (nx >= storage.size() - 1) || ny <= 0 || (ny >= storage[0].length() - 1)) return 1;
            q.push({nx, ny});
            visited[nx][ny] = 1;
        }
    }
    return 0;
}

void jigae(vector<string> storage, char request) {
    int temp[52][52] = {0,};
    for(int x=0; x<storage.size(); x++) {
        for(int y=0; y<storage[0].length(); y++) {
            if(storage[x][y] != request || removed[x][y]) continue;
            if(x <= 0 || (x >= storage.size() - 1) || y <= 0 || (y >= storage[0].length() - 1)) {
                answer--;
                temp[x][y] = 1;
                continue;
            }
            
            if(bfs(storage, x, y)) {
                answer--;
                temp[x][y] = 1;
            }
        }
    }
    
    for(int i=0; i<storage.size(); i++) {
        for(int j=0; j<storage[0].length(); j++) {
            if(temp[i][j]) {
                removed[i][j] = 1;
            }
        }
    }
}

void crain(vector<string> storage, char request) {
    for(int x = 0; x<storage.size(); x++) {
        for(int y=0; y<storage[0].length(); y++) {
            if(removed[x][y]) continue;
            if(storage[x][y] == request){
                answer--;
                removed[x][y] = 1;
            }
        }
    }
}

int solution(vector<string> storage, vector<string> requests) {
    answer = storage.size() * storage[0].length();
    // cout << answer << endl;
    
    for(int i=0; i<requests.size(); i++) {
        if(requests[i].length() == 1) {
            jigae(storage, requests[i][0]);
        } else {
            crain(storage, requests[i][0]);
        }
        // cout << answer << endl;
        
        // for(int x = 0; x<5; x++) {
        //     for(int y=0; y<5; y++) {
        //         cout << removed[x][y] << " ";
        //     }
        //     cout << endl;
        // }
    }
    
    return answer;
}