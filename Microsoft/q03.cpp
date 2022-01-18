void rotate(vector<vector<int> >& a)
{
    int temp, i, I, j, s, e, n = a.size();
    for (i = 0; i < n; i++) {
        s = 0; e = n - 1;
        while (s < e) {
            temp = a[i][s];
            a[i][s] = a[i][e];
            a[i][e] = temp;
            s++; e--;
        }
    }
    for (i = 1; i < n; i++) {
        j = 0; I = i;
        while (I < n) {
            temp = a[I][j];
            a[I][j] = a[j][I];
            a[j][I] = temp;
            I++; j++;
        }
    }
}