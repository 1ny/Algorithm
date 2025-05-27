#include "iostream"
#include "algorithm"
using namespace std;

#define MAX 1001

int n;
int arr[MAX], dp[MAX];
int minN, maxN;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		arr[i] = x;
	}

	for (int i = 2; i <= n; i++) {
		minN = arr[i];
		maxN = arr[i];
		for (int j = i - 1; j >= 0; j--) {
			if (arr[j+1] > maxN) maxN = arr[j+1];
			if (arr[j+1] < minN) minN = arr[j+1];
			dp[i] = max(dp[i], dp[j] + maxN - minN);
		}
	}

	cout << dp[n];

	return 0;
}