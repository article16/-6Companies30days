bool check(int i, string s) {
	if (s[i - 1] == '0')return false;
	string x = s.substr(i - 1, 2);
	int n = stoi(x);
	return (n >= 1 && n <= 26);
}
int CountWays(string s) {
	int i, n = s.length(), mod = 1e9 + 7;
	int dp[n] = {0};
	if (s[0] == '0')return 0;
	dp[0] = 1;
	for (i = 1; i < n; i++) {
		if (s[i] == '0' && s[i - 1] == '0')return 0;
		if (i == 1) {
			if (s[i] == '0') {
				if (check(i, s))dp[i] = 1;
				else return 0;
			}
			else {
				if (check(i, s))dp[i] = 2;
				else dp[i] = 1;
			}
		}
		else {
			if (s[i] == '0') {
				if (check(i, s))dp[i] = dp[i - 2];
				else return 0;
			}
			else {
				if (check(i, s))dp[i] = (dp[i - 2] + dp[i - 1]) % mod;
				else dp[i] = dp[i - 1];
			}
		}
		//cout<<dp[i]<<endl;
	}
	return dp[n - 1];
}