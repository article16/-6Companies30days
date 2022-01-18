int minDifference(int a[], int n)  {
    int i, j, sum = 0, ans = INT_MAX;
    for (i = 0; i < n; i++)sum += a[i];

    bool dp[n + 1][sum + 1];
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= sum; j++) {
            if (i == 0 && j == 0)dp[i][j] = true;
            else if (i == 0)dp[i][j] = false;
            else if (j == 0)dp[i][j] = true;
            else {
                if (j - a[i - 1] >= 0)dp[i][j] = dp[i - 1][j] || dp[i - 1][j - a[i - 1]];
                else dp[i][j] = dp[i - 1][j];
            }
            if (i == n && dp[i][j])ans = min(ans, abs(sum - 2 * j));
        }
    }
    return ans;
}