class Solution {
public:
  /*You are required to complete this method */
  int atoi(string s) {
    int i, l = s.length(), n = 0, f = 0;
    if (s[0] == '-') {f = 1; s = s.substr(1, l - 1);}
    for (char c : s) {
      if (!isdigit(c))return -1;
      n = n * 10 + (c - '0');
    }
    return (f) ? -n : n;
  }
};