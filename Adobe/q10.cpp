vector<string> winner(string arr[], int n)
{
    map<string, int>mp;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        mp[arr[i]]++;
        mx = max(mx, mp[arr[i]]);
    }
    for (auto x : mp) {
        if (x.second == mx)return {x.first, to_string(x.second)};
    }
}