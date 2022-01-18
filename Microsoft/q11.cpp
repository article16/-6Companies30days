string bin(int n) {
    string s = "";
    while (n) {
        int k = n % 2;
        s += ('0' + k);
        n = n / 2;
    }
    reverse(s.begin(), s.end());
    return s;
}
vector<string> generate(int N)
{
    vector<string>ans;
    for (int i = 1; i <= N; i++) {
        ans.push_back(bin(i));
    }
    return ans;
}