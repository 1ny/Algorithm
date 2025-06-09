#include "iostream"
#include "algorithm"
using namespace std;

#define MAX 100000

int n;
int cost[MAX][3];
int testCnt;
int dp[MAX][3];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while (1) {
		testCnt++;
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
		}

		dp[0][0] = MAX;
		dp[0][1] = cost[0][1];
		dp[0][2] = cost[0][1] + cost[0][2];
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				dp[i][j] = cost[i][j] + dp[i - 1][j];
				if (j != 0) {
					dp[i][j] = min(dp[i][j], cost[i][j] + dp[i - 1][j - 1]);
					dp[i][j] = min(dp[i][j], cost[i][j] + dp[i][j - 1]);
				}
				if (j != 2) dp[i][j] = min(dp[i][j], cost[i][j] + dp[i - 1][j + 1]);
			}
		}

		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j < 3; j++) {
		//		cout << dp[i][j] << " ";
		//	}
		//	cout << endl;
		//}

		cout << testCnt << ". " << dp[n-1][1] << endl;
	}

	return 0;
}

/*
13 7 12
14 20 13
28 16 
*/