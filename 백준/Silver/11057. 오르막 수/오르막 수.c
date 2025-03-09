#include <stdio.h>

#define MAX 1001

int n;
long long int dp[MAX][11];

int main() {
    int sum = 0;
    scanf("%d", &n);

    for(int i=1; i<=n; i++) {
        dp[i][0] = 1;
        for(int j=1; j<=9; j++) {
            dp[i][j] = (dp[i][j-1] + dp[i-1][j])%10007;
        }
    }

    for(int i=0; i<=9; i++) {
        sum+=dp[n][i];
    }

    printf("%d", sum%10007);
}