class Solution {
public:
    int minSubArrayLen(int target, vector<int>& a) {
        int ans = INT_MAX, s = 0, e = 0, n = a.size(), sum = a[0];
        while (e < n) {
            while (s <= e && sum - a[s] >= target) {
                sum -= a[s];
                s++;
            }
            if (sum >= target)ans = min(ans, e - s + 1);
            e++;
            if (e < n)sum += a[e];
        }
        return ans == INT_MAX ? 0 : ans;
    }
};