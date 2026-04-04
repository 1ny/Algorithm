#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

// 좌표 집합을 (0,0) 기준으로 정규화하고 정렬하는 함수
vector<pair<int, int>> normalize(vector<pair<int, int>> pos) {
    int minX = 60, minY = 60;
    for (auto p : pos) {
        minX = min(minX, p.first);
        minY = min(minY, p.second);
    }
    for (auto& p : pos) {
        p.first -= minX;
        p.second -= minY;
    }
    sort(pos.begin(), pos.end());
    return pos;
}

// 90도 회전 함수
vector<pair<int, int>> rotate(vector<pair<int, int>> pos) {
    for (auto& p : pos) {
        int temp = p.first;
        p.first = p.second;
        p.second = -temp;
    }
    return normalize(pos);
}

// BFS를 이용해 조각(또는 빈 공간) 추출
vector<pair<int, int>> bfs(int x, int y, vector<vector<int>>& board, int target, vector<vector<bool>>& visited) {
    vector<pair<int, int>> pos;
    queue<pair<int, int>> q;
    int n = board.size();

    q.push({x, y});
    visited[x][y] = true;
    
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        pos.push_back(cur);

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if (!visited[nx][ny] && board[nx][ny] == target) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
    return normalize(pos);
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int n = game_board.size();
    vector<vector<pair<int, int>>> blank_list; // game_board의 빈 공간들
    vector<vector<pair<int, int>>> puzzle_list; // table의 퍼즐 조각들
    
    vector<vector<bool>> v1(n, vector<bool>(n, false));
    vector<vector<bool>> v2(n, vector<bool>(n, false));

    // 1. game_board에서 빈 공간(0) 추출
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (game_board[i][j] == 0 && !v1[i][j]) {
                blank_list.push_back(bfs(i, j, game_board, 0, v1));
            }
        }
    }

    // 2. table에서 퍼즐 조각(1) 추출
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (table[i][j] == 1 && !v2[i][j]) {
                puzzle_list.push_back(bfs(i, j, table, 1, v2));
            }
        }
    }

    int total_score = 0;
    vector<bool> puzzle_used(puzzle_list.size(), false);

    // 3. 빈 공간마다 맞는 퍼즐 찾기
    for (auto& blank : blank_list) {
        bool found = false;
        for (int i = 0; i < puzzle_list.size(); i++) {
            if (puzzle_used[i]) continue;
            if (blank.size() != puzzle_list[i].size()) continue;

            vector<pair<int, int>> curr_puzzle = puzzle_list[i];
            
            // 4번 회전시키며 비교
            for (int r = 0; r < 4; r++) {
                if (blank == curr_puzzle) {
                    total_score += blank.size();
                    puzzle_used[i] = true;
                    found = true;
                    break;
                }
                curr_puzzle = rotate(curr_puzzle);
            }
            if (found) break;
        }
    }

    return total_score;
}