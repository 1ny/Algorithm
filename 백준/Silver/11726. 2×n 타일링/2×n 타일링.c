#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int n;
int dp[MAX];

int main() {
    scanf("%d", &n);

    dp[0] = 1;
    dp[1] = 2;
    for(int i=2; i<n; i++) {
        dp[i] = (dp[i-1] + dp[i-2])%10007;
    }

    printf("%d", dp[n-1]);
}