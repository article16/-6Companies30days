class Solution {
public:
    bool winnerOfGame(string colors) {
        int i, n = colors.length(), c1 = 0, c2 = 0, a = 0, b = 0;
        for (i = 0; i < n; i++) {
            if (colors[i] == 'B') {
                if (c1 > 2)a += c1 - 2;
                c1 = 0; c2++;
            }
            else {
                if (c2 > 2)b += c2 - 2;
                c2 = 0; c1++;
            }
        }
        if (c1 > 2)a += c1 - 2; if (c2 > 2)b += c2 - 2;
        return a > b;
    }
};