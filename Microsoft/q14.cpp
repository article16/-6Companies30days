class Solution {
public:
    int minSteps(int D) {
        int sum = 0, step = 0;
        while (sum < D || (sum - D) % 2 != 0) {
            step++;
            sum += step;
        }
        return step;
    }
};