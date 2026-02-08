#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define MAX 105

int INF = 0x3f3f3f3f;
int n, m;
int board[MAX][MAX];
int result[MAX][MAX];

int main() {
	ios::sync_with_stdio();
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	//fill(result, result + 1+n, INF);
	memset(result, INF, sizeof(result));
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		result[a][b] = min(c, result[a][b]);
	}

	for (int i = 1; i <= n; i++) {
		result[i][i] = 0;
	}

	// k를 지나는 i -> j 의 최소 거리 = result[i][k] + result[k][j]
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (k == i) continue;
			for (int j = 1; j <= n; j++) {
				if (j == k || j == i) continue;
				result[i][j] = min(result[i][k] + result[k][j], result[i][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (result[i][j] >= INF) result[i][j] = 0;
			cout << result[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}