class Solution {
public:
  int findPosition(int N , int M , int K) {
    int p = (K + M - 1) % N;
    if (p == 0)return N;
    else return p;
  }
};