class Solution
{
public:
    void solve(int i, string str, int a[], int n, unordered_map<int, string>&mp, vector<string>&ans) {
        if (i == n) {
            ans.push_back(str);
            return;
        }
        string s = mp[a[i]];
        for (int j = 0; j < s.length(); j++) {
            str.push_back(s[j]);
            solve(i + 1, str, a, n, mp, ans);
            str.pop_back();
        }
    }
    vector<string> possibleWords(int a[], int N)
    {
        unordered_map<int, string>mp;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";

        vector<string>ans;
        solve(0, "", a, N, mp, ans);
        return ans;
    }
};