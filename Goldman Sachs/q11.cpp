#define ll long long
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    vector<int>ans(2);
    ll  b, x, y, z, i, n = A.size(), s = 0, s2 = 0;
    for (i = 0; i < n; i++) {
        b = A[i];
        s += b;
        s2 += b * b;
    }
    x = (n * (n + 1)) / 2 - s;
    y = (n * (n + 1) * (2 * n + 1)) / 6 - s2;
    z = y / x;
    ans[0] = (z - x) / 2; ans[1] = (z + x) / 2;
    return ans;
}
