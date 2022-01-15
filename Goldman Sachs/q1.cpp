class Solution {
public:
    string sorted(string s) {
        sort(s.begin(), s.end());
        return s;
    }
    vector<vector<string> > Anagrams(vector<string>& string_list) {

        vector<vector<string> > ans;
        map<string, vector<string>>mp;
        for (auto s : string_list) {
            mp[sorted(s)].push_back(s);
        }
        for (auto s : mp)ans.push_back(s.second);
        return ans;
    }
};