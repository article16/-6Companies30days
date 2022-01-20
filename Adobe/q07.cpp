int maxCoins(vector<int>&a, int n)
{
    if (n == 1)return a[0];
    int dp[n][n];
    int pre[n + 1] = {0};
    int i, j, g, x, y;
    for (i = 1; i <= n; i++)pre[i] = pre[i - 1] + a[i - 1];
    for (g = 0; g < n; g++) {
        i = 0; j = g;
        while (j < n) {
            if (g == 0)dp[i][j] = a[i];
            else {
                x = a[j] + pre[j] - pre[i] - dp[i][j - 1];
                y = a[i] + pre[j + 1] - pre[i + 1] - dp[i + 1][j];
                dp[i][j] = max(x, y);
            }

            i++; j++;
        }
    }
    return dp[0][n - 1];
}