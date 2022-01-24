class Solution {
public:
    void solve(string s, int i, int j, vector<vector<char>>& board, vector<vector<bool>>& vis,
               int n, int m, string word, bool &ans) {

        if (i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || ans)return;
        if (word[s.length()] != board[i][j])return;

        s += board[i][j];
        if (s == word) {
            ans = true;
            return;
        }

        vis[i][j] = true;
        int x[] = {0, 1, 0, -1};
        int y[] = { -1, 0, 1, 0};
        for (int k = 0; k < 4; k++) {
            solve(s, i + x[k], j + y[k], board, vis, n, m, word, ans);
        }
        vis[i][j] = false;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>>vis(n, vector<bool>(m, false));
        bool ans = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                solve("", i, j, board, vis, n, m, word, ans);
                if (ans)return ans;
            }
        }
        return ans;
    }
};