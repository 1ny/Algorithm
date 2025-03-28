#include <stdio.h>
#include <stdlib.h>

#define MAX 1001

int n;  // 간식 개수
int arr[MAX];
int dp[MAX];
int maxScore;

int main() {
    scanf("%d", &n);

    for(int i=1; i<=n; i++) {
        scanf("%d", &arr[i]);
    }

    dp[1] = arr[1];
    for(int i=2; i<=n; i++) {
        int max = 0;    // 1~i 중 최대 평점
        for(int j=1; j<i; j++) {
            if(arr[i] > arr[j] && dp[j] > max) max = dp[j];
        }
        dp[i] = max + arr[i];
        if(dp[i] > maxScore) maxScore = dp[i];
    }

    printf("%d", maxScore);
}