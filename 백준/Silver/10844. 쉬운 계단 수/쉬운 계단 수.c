#include <stdio.h>

#define MAX 101

int n;
int dp[MAX][10];

int main() {
    scanf("%d", &n);

    for(int i=0; i<=9; i++) {
        dp[1][i] = 1;
    }

    dp[2][0] = 1;
    for(int i=2; i<=n; i++) {
        for(int j=0; j<=9; j++) {
            if(i==2 && j == 0) continue;
            if(j == 9) dp[i][j] = dp[i-1][j-1]%1000000000; 
            else if(j == 0) dp[i][j] = dp[i-1][j+1]%1000000000;
            else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%1000000000;
        }
    }

    // for(int j=0; j<=9; j++) {
    //     printf("[%d] %d\n", j, dp[n][j]);
    // }
    
    long long int sum = 0;
    for(int j=1; j<=9; j++) {
        sum += dp[n][j];
    }

    printf("%lld", sum%1000000000);
}