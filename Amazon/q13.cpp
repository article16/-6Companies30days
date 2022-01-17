class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ni, nj, r, c, siz, mins = -1, i, j, m = grid.size(), n = grid[0].size();
        queue<pair<int, int>>q;
        vector<vector<int>> vis( m , vector<int> (n, 0));
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    vis[i][j] = 1;
                    q.push({i, j});
                }
            }
        }
        int x[] = {0, 1, 0, -1};
        int y[] = { -1, 0, 1, 0};
        while (!q.empty()) {
            siz = q.size(); mins++;
            for (i = 0; i < siz; i++) {

                r = q.front().first;
                c = q.front().second;
                q.pop();
                for (j = 0; j < 4; j++) {
                    ni = r + x[j]; nj = c + y[j];
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n && vis[ni][nj] == 0 && grid[ni][nj] == 1) {
                        vis[ni][nj] = 1;
                        grid[ni][nj] = 2;
                        q.push({ni, nj});
                    }
                }
            }
        }
        int cnt = 0;
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
                else if (grid[i][j] == 0)cnt++;
            }
        }
        if (cnt == n * m)return 0;
        return mins;

    }
};