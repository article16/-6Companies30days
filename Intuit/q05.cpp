class Solution {
public:
    bool possible(int tar, int m, int n, vector<int>& a) {
        int cnt = 0, i = 0, s = 0;
        while (i < n) {
            if (a[i] > tar)return false;
            s += a[i];
            if (s > tar) {
                cnt++; s = 0;
            }
            else i++;
        }
        cnt++;
        return (cnt <= m);
    }
    int splitArray(vector<int>& a, int m) {
        int i, n = a.size(), s = 0, ans;
        for (int x : a)s += x;
        int low = 0, high = s, mid;
        while (low <= high) {
            mid = (low + high) / 2;
            if (possible(mid, m, n, a)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;

    }
};