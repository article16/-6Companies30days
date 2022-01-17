int isValid(vector<vector<int>> mat) {
    set<int>s1, s2;
    int i, j, r, c;

    for (i = 0; i < 9; i++) {
        s1.clear();
        s2.clear();
        for (j = 0; j < 9; j++) {
            if (mat[i][j] != 0) {
                if (s1.find(mat[i][j]) != s1.end())return 0;
                else s1.insert(mat[i][j]);
            }
            if (mat[j][i] != 0) {
                if (s2.find(mat[j][i]) != s2.end())return 0;
                else s2.insert(mat[j][i]);
            }
        }
    }

    for (i = 0; i <= 6; i += 3) {
        for (j = 0; j <= 6; j += 3) {
            s1.clear();
            for (r = i; r <= i + 2; r++) {
                for (c = j; c <= j + 2; c++) {
                    if (mat[r][c] != 0) {
                        if (s1.find(mat[r][c]) != s1.end())return 0;
                        else s1.insert(mat[r][c]);
                    }
                }
            }
        }
    }

    return 1;
}