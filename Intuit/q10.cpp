class Solution {
public:
    void dfs(int i, vector<bool>&vis, vector<int>adj[]) {
        vis[i] = true;
        for (auto x : adj[i]) {
            if (!vis[x])
                dfs(x, vis, adj);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int i, j, n = isConnected.size(), cnt = 0;
        vector<int>adj[n];
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (i != j && isConnected[i][j])adj[i].push_back(j);
            }
        }
        vector<bool>vis(n, false);
        for (i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, vis, adj);
                cnt++;
            }
        }
        return cnt;
    }
};