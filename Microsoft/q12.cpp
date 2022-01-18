class Solution {
public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &a, int k) {
        vector<vector<int> > ans;
        int i, j, s, e, sum, l1, l2, n = a.size();
        sort(a.begin(), a.end());
        for (i = 0; i <= n - 4; i++) {
            if (i > 0 && a[i] == a[i - 1])continue;
            for (j = i + 1; j <= n - 3; j++) {
                if (j > i + 1 && a[j] == a[j - 1])continue;
                s = j + 1; e = n - 1;
                while (s < e) {
                    sum = a[i] + a[j] + a[s] + a[e];
                    if (sum < k)s++;
                    else if (sum > k)e--;
                    else {
                        ans.push_back({a[i], a[j], a[s], a[e]});
                        l1 = a[s]; l2 = a[e];
                        while (a[s] == l1)s++;
                        while (a[e] == l2)e--;
                    }
                }
            }
        }
        return ans;
    }
};