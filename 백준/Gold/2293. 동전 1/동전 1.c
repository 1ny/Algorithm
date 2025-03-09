#include <stdio.h>

#define MAX 100001

int n, k;
int arr[MAX];
int dp[MAX];

int main() {
    scanf("%d %d", &n, &k);

    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    dp[0] = 1;
    for(int i=0; i<n; i++) {
        for(int j=arr[i]; j<=k; j++) {
            dp[j] += dp[j-arr[i]];
        }
    }

    printf("%d", dp[k]);
}