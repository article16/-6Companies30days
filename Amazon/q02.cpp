class Solution {
public:
    int longestMountain(vector<int>& a) {
        int i, s = 0, n = a.size(), ans = 0;
        if (n < 3)return 0;
        if (a[1] > a[0])s = 0;
        else s = -1;
        for (i = 1; i < n - 1; i++) {
            if (a[i] <= a[i - 1] && a[i] <= a[i + 1]) {
                if (s != -1)ans = max(ans, i - s + 1);
                s = i;
            }
            if (a[i] == a[i + 1])s = -1;
        }
        if (s != -1 && a[n - 1] < a[n - 2])ans = max(ans, i - s + 1);
        return ans;
    }
};