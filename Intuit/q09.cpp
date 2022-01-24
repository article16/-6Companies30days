class Solution {
public:
    void solve(int i, int j, int n, int m, vector<vector<int>>& a, vector<vector<bool>>& vis, int last, bool &f1, bool &f2) {
        if (i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || a[i][j] > last)return;
        if (f1 && f2)return;
        if (i == 0 || j == 0)f1 = true;
        if (i == n - 1 || j == m - 1)f2 = true;

        vis[i][j] = true;
        int x[] = {0, 1, 0, -1};
        int y[] = { -1, 0, 1, 0};
        for (int k = 0; k < 4; k++) {
            solve(i + x[k], j + y[k], n, m, a, vis, a[i][j], f1, f2);
        }
        vis[i][j] = false;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& a) {
        vector<vector<int>>ans;
        int n = a.size(), m = a[0].size();
        vector<vector<bool>>vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                bool f1 = false, f2 = false;
                solve(i, j, n, m, a, vis, INT_MAX, f1, f2);
                if (f1 && f2)ans.push_back({i, j});
            }
        }
        return ans;
    }
};