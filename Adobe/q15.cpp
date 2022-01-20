class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i, j, k;
        vector<int>v1, v2;
        version1 += "."; version2 += ".";
        string x = "";
        for (char c : version1) {
            if (c == '.') {
                v1.push_back(stoi(x));
                x = "";
            }
            else x += c;
        }
        x = "";
        for (char c : version2) {
            if (c == '.') {
                v2.push_back(stoi(x));
                x = "";
            }
            else x += c;
        }
        for (i = 0; i < min(v1.size(), v2.size()); i++) {
            if (v1[i] > v2[i])return 1;
            else if (v1[i] < v2[i])return -1;
        }
        j = k = i;
        while (j < v1.size() && v1[j] == 0)j++;
        while (k < v2.size() && v2[k] == 0)k++;
        if (j < v1.size())return 1;
        else if (k < v2.size())return -1;
        return 0;
    }
};