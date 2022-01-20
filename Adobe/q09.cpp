class Solution {
public:
    string nextPalin(string s) {
        int i, j, n = s.length();
        string ans = s.substr(0, n / 2);
        for (i = (n - 4) / 2; i >= 0; i--) {
            if (s[i] < s[i + 1])break;
        }
        reverse(ans.begin() + i + 1, ans.end());
        if (i != -1) {
            for (j = i + 1; j < n / 2; j++) {
                if (ans[j] > ans[i])
                {swap(ans[i], ans[j]); break;}
            }
        }
        string rev = ans;
        reverse(rev.begin(), rev.end());
        if (n & 1)ans += s[n / 2];
        ans += rev;
        return ans > s ? ans : "-1";
    }
};