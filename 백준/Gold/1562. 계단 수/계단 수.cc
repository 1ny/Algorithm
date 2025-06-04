#include "iostream"
#include "algorithm"
using namespace std;

#define MAX 100

int n;
int dp[10][MAX+1][0x3ff+1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	 
	for (int i = 1; i <= 9; i++) {
		dp[i][1][1 << i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int p = 0; p <= 0x3ff; p++) {
				if (j > 0) dp[j][i][p | (1 << j)] += dp[j - 1][i - 1][p];
				if (j < 9) dp[j][i][p | (1 << j)] += dp[j + 1][i - 1][p];
				dp[j][i][p | (1 << j)] %= 1000000000;
			}
		}
	}

	long long result = 0;
	for (int i = 0; i <= 9; i++) {
		result += dp[i][n][0x3ff];
		result %= 1000000000;
	}

	cout << result;

	return 0;
}

/*
23 43
210 
321 121 101
232 432 
  1 2 3 4 5 6 7 ..n
0 0 1 1
1 1 1 3
2 1 2 3
3 1 2
4 1 2
5 1 2
6 1 2
7 1 2
8 1 2
9 1 2
*/