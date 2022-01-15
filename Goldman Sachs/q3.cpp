#define ll long long
class Solution {
public:
  int countSubArrayProductLessThanK(const vector<int>& a, int n, ll k) {
    ll i = 0, j = 0, p = 1, ans = 0;
    while (i < n) {
      p *= a[i];
      while (j <= i && p >= k) {p /= a[j]; j++;}
      if (p < k)ans += i - j + 1;
      i++;
    }
    return ans;
  }
};