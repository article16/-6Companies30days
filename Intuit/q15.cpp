class Solution {
public:
#define ll long long
    bool possible(int k, int h, vector<int>& piles) {
        double K = k;
        ll cnt = 0;
        for (int x : piles)cnt += ceil(x / K);
        return cnt <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        ll n = piles.size(), s = 0;
        for (int x : piles)s += x;
        ll low = 1, high = s, ans;
        while (low <= high) {
            ll mid = (low + high) / 2;
            if (possible(mid, h, piles)) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};