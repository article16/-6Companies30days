public:
void dfs(int i, int j, int n, int m, int &ans, vector<vector<int>>&vis, vector<vector<int>>&grid) {
    if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0 || vis[i][j] == 1)return;
    vis[i][j] = 1;
    ans++;
    int x[] = {0, 1, 1, 1, 0, -1, -1, -1};
    int y[] = { -1, -1, 0, 1, 1, 1, 0, -1};
    for (int k = 0; k < 8; k++) {
        dfs(i + x[k], j + y[k], n, m, ans, vis, grid);
    }

}
int findMaxArea(vector<vector<int>>& grid) {
    int ans, ANS = 0, i, j, n = grid.size(), m = grid[0].size();
    vector<vector<int>>vis(n, vector<int>(m, 0));
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            ans = 0;
            if (grid[i][j] == 1 && vis[i][j] == 0)
                dfs(i, j, n, m, ans, vis, grid);
            ANS = max(ANS, ans);
        }
    }
    return ANS;
}