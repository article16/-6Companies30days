int maxProfit(int K, int N, int A[]) {
    int dp[K + 1][N];
    for (int t = 0; t <= K; t++) {
        int mx = INT_MIN;
        for (int d = 0; d < N; d++) {
            if (t == 0 || d == 0)dp[t][d] = 0;
            else {
                mx = max(mx, dp[t - 1][d - 1] - A[d - 1]);
                dp[t][d] = max(dp[t][d - 1], mx + A[d]);
            }
        }
    }
    return dp[K][N - 1];
}