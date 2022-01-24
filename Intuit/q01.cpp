int minDifference(int a[], int n)  {
	int i, j, s = 0, ans = INT_MAX;
	for (i = 0; i < n; i++)s += a[i];
	bool dp[n + 1][s + 1];
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= s; j++) {
			if (j == 0)dp[i][j] = true;
			else if (i == 0)dp[i][j] = false;
			else {
				dp[i][j] = dp[i - 1][j];
				if (j - a[i - 1] >= 0)dp[i][j] |= dp[i - 1][j - a[i - 1]];
			}
			if (i == n && dp[i][j])ans = min(ans, abs(s - 2 * j));
			//cout<<dp[i][j]<<" ";
		}
		//cout<<endl;
	}
	return ans;
}