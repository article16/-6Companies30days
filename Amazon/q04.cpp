string matrixChainOrder(int p[], int n) {
    int i, j, g, js, sml, cost, smlj;
    string x, alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    vector<vector<pair<int, string>>> dp(n - 1, vector<pair<int, string>>(n - 1, {0, ""}));
    for (g = 0; g <= n - 2; g++) {
        i = 0; j = g;
        while (j <= n - 2) {
            if (g == 0) {
                dp[i][j] = {0, alph.substr(i, 1)};
            }
            else if (g == 1) {
                x = "("; x += alph.substr(i, 2); x += ")";
                dp[i][j] = {p[i]*p[i + 1]*p[i + 2], x};
            }
            else {
                sml = INT_MAX; smlj = -1;
                for (js = i; js < j; js++) {
                    cost = p[i] * p[js + 1] * p[j + 1] + dp[i][js].first + dp[js + 1][j].first;
                    if (cost < sml) {
                        sml = cost;
                        smlj = js;
                    }
                }
                x = "("; x += dp[i][smlj].second;
                x += dp[smlj + 1][j].second; x += ")";
                dp[i][j] = {sml, x};
            }
            i++; j++;
        }

    }
    return dp[0][n - 2].second;
}