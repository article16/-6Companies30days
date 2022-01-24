bool check(int n) {
    if (n == 0)return false;
    while (n) {
        int a = n % 10;
        if (a != 9)return false;
        n = n / 10;
    }
    return true;
}
int missingNumber(const string& s)
{
    int l, len, i, n = s.length(), num, f, ans = -1;
    string x;
    if (n == 1)return -1;
    for (l = 1; l <= min(6, n); l++) {
        len = i = l; f = 0;
        num = stoi(s.substr(0, l));
        while (i <= n - len) {
            if ((check(num)) && i <= n - len - 1)x = s.substr(i, ++len);
            else x = s.substr(i, len);
            if (stoi(x) == num + 1) {
                num = num + 1;
            }
            else if (stoi(x) == num + 2) {
                if (f) {ans = -1; break;}
                ans = num + 1;
                num = num + 2;
                f = 1;
            }
            else if (check(num + 1) && i <= n - len - 1) {
                x = s.substr(i, ++len);
                if (stoi(x) == num + 2) {
                    ans = num + 1;
                    num = num + 2;
                }
            }
            else {ans = -1; break;}

            i += len;
        }
        if (i != n) {ans = -1; continue;}
        return ans;
    }
    return -1;
}