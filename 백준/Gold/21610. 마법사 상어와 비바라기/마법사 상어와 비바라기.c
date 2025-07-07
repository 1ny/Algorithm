#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 51

int n, m;
int dx[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int board[MAX][MAX];
int gureum[MAX][MAX];
int result;
int temp[MAX][MAX];

void edong(int dir, int cnt) {
	for (int c = 0; c < cnt; c++) {
		memset(temp, 0, sizeof(temp));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (!gureum[i][j]) continue;
				int nx = dx[dir] + i;
				int ny = dy[dir] + j;
				if (nx <= 0) nx = n;
				else if (nx > n) nx = 1;
				if (ny <= 0) ny = n;
				else if (ny > n) ny = 1;
				temp[nx][ny] = 1;
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				gureum[i][j] = temp[i][j];
			}
		}

		//for (int i = 1; i <= n; i++) {
		//	for (int j = 1; j <= n; j++) {
		//		printf("%d ", gureum[i][j]);
		//	}
		//	printf("\n");
		//}
		//printf("\n");
	}
}

int main() {
	scanf("%d %d", &n, &m);
	gureum[n][1] = gureum[n][2] = gureum[n - 1][1] = gureum[n - 1][2] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &board[i][j]);
		}
	}

	for (int i = 0; i < m; i++) {
		int di, si;
		scanf("%d %d", &di, &si);

		// 1. di 방향으로 si 만큼 이동
		edong(di-1, si);

		// 2. 구름 있는 칸에 1씩 증가
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (!gureum[i][j]) continue;
				board[i][j]++;
			}
		}

		// 3. 구름 사라짐
		memcpy(temp, gureum, sizeof(temp));
		memset(gureum, 0, sizeof(gureum));
		
		// 4. 물복사버그 (대각선 탐색)
		int cnt;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (!temp[i][j]) continue;
				cnt = 0;
				for (int c = 0; c < 4; c++) {
					int nx = dx[c * 2 + 1] + i;
					int ny = dy[c * 2 + 1] + j;
					if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
					if (!board[nx][ny]) continue;
					cnt++;
				}

				board[i][j] += cnt;
			}
		}

		// 5. 물의 양이 2 이상이면서 이전에 구름없던 곳에 -2 & 구름 생김
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (board[i][j] < 2 || temp[i][j]) continue;
				gureum[i][j] = 1;
				board[i][j] -= 2;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			result += board[i][j];
		}
	}

	printf("%d", result);

	return 0;
}

/*



*/