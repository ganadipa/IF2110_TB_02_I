#include <stdio.h>

int dp[5];

int main(void) {
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i < 5; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    for (int i = 0; i < 5; i++) {
        printf("%d\n", dp[i]);
    }
}