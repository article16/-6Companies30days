vector<int> spirallyTraverse(vector<vector<int> > A, int m, int n)
{
    int i, t = 0, b = m - 1, l = 0, r = n - 1, dir = 0;
    vector<int>ans;
    while (t <= b && l <= r) {
        if (dir == 0) {
            for (i = l; i <= r; i++)ans.push_back(A[t][i]);
            t++;
        }
        else if (dir == 1) {
            for (i = t; i <= b; i++)ans.push_back(A[i][r]);
            r--;
        }
        else if (dir == 2) {
            for (i = r; i >= l; i--)ans.push_back(A[b][i]);
            b--;
        }
        else {
            for (i = b; i >= t; i--)ans.push_back(A[i][l]);
            l++;
        }
        dir = (dir + 1) % 4;
    }
    return ans;
}