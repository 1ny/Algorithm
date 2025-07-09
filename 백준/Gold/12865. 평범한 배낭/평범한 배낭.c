#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 101
#define MAX_K 100002

int n, k;
int w[MAX], v[MAX];
dp[MAX][MAX_K];

int my_max(int x, int y) {
	if (x > y) return x;
	else return y;
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &w[i], &v[i]);
	}

	for (int i = w[0]; i <= k; i++) {
		dp[0][i] = v[0];
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j >= w[i]) dp[i][j] = my_max(dp[i][j], dp[i - 1][j-w[i]] + v[i]);
		}
	}

	//for (int i = 0; i < n; i++) {
	//	for (int j = 1; j <= k; j++) {
	//		printf("%d ", dp[i][j]);
	//	}
	//	printf("\n");
	//}

	printf("%d", dp[n-1][k]);

	return 0;
}
