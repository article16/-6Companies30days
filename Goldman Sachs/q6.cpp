class Solution {
public:
    string gcdOfStrings(string s1, string s2) {
        int i, j, l1 = s1.length(), l2 = s2.length();
        string k, ans = "";
        for (i = 0; i < min(l1, l2); i++) {
            if (s1[i] != s2[i])break;
        }
        if (i == 0)return ans;
        while (l1 % i != 0 || l2 % i != 0) {
            i--;
            if (i == 0)return ans;
        }
        k = s1.substr(0, i);
        for (j = 0; j < l1; j += i) {
            if (s1.substr(j, i) != k)return ans;
        }
        for (j = 0; j < l2; j += i) {
            if (s2.substr(j, i) != k)return ans;
        }
        return k;
    }
};