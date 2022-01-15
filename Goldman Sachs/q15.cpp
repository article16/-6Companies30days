bool canPair(vector<int> a, int k) {
    int i, n = a.size(), rem;
    if (n & 1)return false;
    unordered_map<int, int>mp;

    for (i = 0; i < n; i++) {
        rem = ((a[i] % k) + k) % k;
        mp[rem]++;
    }

    for (i = 0; i < n; i++) {
        rem = ((a[i] % k) + k) % k;
        if (2 * rem == k) {if (mp[rem] % 2 != 0)return false;}
        else if (rem == 0) {if (mp[rem] % 2 != 0)return false;}
        else if (mp[rem] != mp[k - rem])return false;
    }
    return true;
}