#include <stdio.h>

#define MAX 31

int n;
int t[MAX], p[MAX];
int dp[MAX];

int max(int x, int y) {
    if(x > y) return x;
    else return y;
}

int main() {
    int result = 0;
    scanf("%d", &n);

    for(int i=1; i<=n; i++) {
        scanf("%d %d", &t[i], &p[i]);
    }

    for(int i=1; i<=n; i++) {
        if(t[i] > 1) {
            int jump = i+t[i]-1;
            dp[i] = max(dp[i-1], dp[i]);
            dp[jump] = max(dp[i-1] + p[i], dp[jump]);
        } else {
            dp[i] = max(dp[i-1] + p[i], dp[i]);
        }
       
        if(dp[i] > result) result = dp[i];
    }

    printf("%d", result);
}