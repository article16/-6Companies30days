class Solution {
#define ll long long
public:
  long long squaresInChessBoard(long long N) {
    ll i, ans = 1;
    for (i = 2; i <= N; i++) {
      ans += i * i;
    }
    return ans;
  }
};