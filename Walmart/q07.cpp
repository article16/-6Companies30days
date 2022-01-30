class Solution {
public:
    vector<int> find3Numbers(vector<int> a, int n) {
        vector<int>ans(3);
        int j = -1, low = 0, mx = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > mx) {
                if (i != 0)low = ans[j];
                ans[++j] = a[i];
                mx = a[i];
                if (j == 2)break;
            }
            else {
                if (a[i] > low) {
                    ans[j] = a[i];
                    mx = a[i];
                }
            }
        }
        if (j != 2)ans.clear();
        return ans;
    }
};