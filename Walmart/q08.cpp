class Solution {
public:
    int height(int s) {
        double k = (sqrt(8 * s + 1) - 1) / 2;
        return (int)k;
    }
};