class Solution {
public:
#define ll long long
    string colName (long long int n)
    {
        string ans = "";
        while (n) {
            ll k = n % 26;
            if (k == 0)k = 26;
            n -= k;
            ans += ('A' + k - 1);
            n = n / 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};