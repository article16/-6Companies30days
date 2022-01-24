class Solution
{
public:
    void solve(int i, string &s, int k, int n, string &ans, string srt) {
        if (k == 0 || i == n - 1) {
            if (s > ans)ans = s;
            return;
        }
        char ch = srt[i];
        if (s[i] == ch)solve(i + 1, s, k, n, ans, srt);
        else {
            for (int j = i + 1; j < n; j++) {
                if (s[j] == ch) {
                    swap(s[j], s[i]);
                    solve(i + 1, s, k - 1, n, ans, srt);
                    swap(s[j], s[i]);
                }
            }
        }
    }
    string findMaximumNum(string s, int k)
    {
        string ans = "", srt = s;
        sort(srt.begin(), srt.end(), greater<char>());
        int n = s.length();
        solve(0, s, k, n, ans, srt);
        return ans;
    }
};