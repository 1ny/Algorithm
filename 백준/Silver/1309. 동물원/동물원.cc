#include "iostream"
#include "algorithm"
#include "cmath"
using namespace std;

#define MAX 100000

int n;
int dp[MAX + 1];
int sum;

int main() {
	cin >> n;

	dp[0] = 0;
	dp[1] = 3;
	dp[2] = 7;
	sum = 10;
	if (n <= 2) {
		cout << dp[n] % 9901;
		return 0;
	}
	for (int i = 3; i <= n; i++) {
		dp[i] = (2 * dp[i - 1] + dp[i - 2]) % 9901;
	}

	cout << dp[n];

	return 0;
}

/*
[1] (1) + (2*1) = 3
[2] (1) + (2*2) + 2 = 7
[3] (1) + (2*3) + 2 + (2*2-1 + 2/1) * 2 = 17
[4] (1) + (2*4) + 10 + (6-1 + 5)*2 = 
*/