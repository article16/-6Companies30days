string encode(string s)
{
  int i, l = s.length(), cnt = 1;
  string ans = "";
  for (i = 0; i < l; i++) {
    if (i == l - 1 || s[i] != s[i + 1]) {
      ans += s[i];
      ans += to_string(cnt);
      cnt = 1;
    }
    else cnt++;
  }
  return ans;
}