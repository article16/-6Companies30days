class Solution {
public:
    string amendSentence (string s)
    {
        string ans = "", x = "";
        int i, l = s.length();
        s[0] = tolower(s[0]);
        for (i = 0; i < l; i++) {
            char c = s[i];
            if (isupper(c)) {
                ans += x; ans += " ";
                x = tolower(c);
            }
            else x += c;
        }
        ans += x;
        return ans;
    }
};