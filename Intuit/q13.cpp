class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int i, j, n = grid.size(), ans = 0, k, temp;
        vector<int>zero(n);
        for (i = 0; i < n; i++) {
            for (j = n - 1; j >= 0; j--) {
                if (grid[i][j] != 0)break;
            }
            zero[i] = n - j - 1;
        }
        for (i = 0; i <= n - 2; i++) {
            if (zero[i] >= n - i - 1)continue;
            for (j = i + 1; j < n; j++) {
                if (zero[j] >= n - i - 1)break;
            }
            if (j == n)return -1;
            int last = zero[i];
            zero[i] = zero[j];
            for (k = i + 1; k <= j; k++) {
                temp = zero[k];
                zero[k] = last;
                last = temp;
            }
            ans += j - i;
        }
        return ans;
    }
};