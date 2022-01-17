void matchPairs(char nuts[], char bolts[], int n) {
    map<char , int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[nuts[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        if (mp.find(bolts[i]) != mp.end())
        {
            nuts[i] = bolts[i];
        }
    }
    sort(nuts , nuts + n);
    sort(bolts , bolts + n);
}