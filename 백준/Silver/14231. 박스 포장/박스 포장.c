#include <stdio.h>
#include <stdlib.h>

#define MAX 100001

int n; // 박스의 개수 n
int Ai[MAX];
int dp[MAX];
int result = 1;

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &Ai[i]);
    }

    dp[1] = 1;
    for(int i=2; i<=n; i++) {
        int max = 0;
        for(int j=1; j<i; j++) {
            if(Ai[j] < Ai[i] && dp[j] > max) max = dp[j];
        }
        dp[i] = max + 1;
        if(dp[i] > result) result = dp[i];
        // printf("%d ", dp[i]);
    }

    printf("%d", result);
}