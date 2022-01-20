class Solution {
public:
#define ll long long
    ll numOfWays(int n, int x)
    {
        const ll mod = 1e9 + 7;
        ll dp[n + 1];
        memset(dp, 0, sizeof(dp));

        dp[0] = dp[1] = 1;

        int maxLimit = pow(n, 1.0 / x);

        for (int i = 2; i <= maxLimit; i++) {
            int curr = pow(i, x);

            for (int j = n; j >= curr; j--) {
                dp[j] = (dp[j] + dp[j - curr]) % mod;
            }
        }

        return dp[n];
    }
};