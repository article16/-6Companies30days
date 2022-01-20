class Solution
{
public:
    void solve(string str, int s, int e, int n, vector<string>&ans) {
        if (s > n || e > s)return;
        if (s == e && s + e == 2 * n) {
            ans.push_back(str);
            return;
        }

        solve(str + "(", s + 1, e, n, ans);
        solve(str + ")", s, e + 1, n, ans);
    }
    vector<string> AllParenthesis(int n)
    {
        vector<string>ans;
        solve("", 0, 0, n, ans);
        return ans;
    }
};