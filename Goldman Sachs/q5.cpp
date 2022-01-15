class Solution {
public:
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
		// code here
		ull dp[n + 1];
		dp[1] = 1;
		ull p2 = 1, p3 = 1, p5 = 1;
		for (ull i = 2; i <= n; i++) {
			ull f2 = 2 * dp[p2];
			ull f3 = 3 * dp[p3];
			ull f5 = 5 * dp[p5];

			ull mn = min(f2, min(f3, f5));
			dp[i] = mn;

			if (f2 == mn)p2++;
			if (f3 == mn)p3++;
			if (f5 == mn)p5++;
		}
		return dp[n];
	}
};