class Solution {
public:
    double radius, x_center, y_center;
    Solution(double radius, double x_center, double y_center) {
        this->radius = radius;
        this->x_center = x_center;
        this->y_center = y_center;
    }

    vector<double> randPoint() {
        double len = sqrt((double) rand() / RAND_MAX) * radius;
        double deg = (double) rand() / RAND_MAX * 2 * M_PI;
        double x = x_center + len * cos(deg);
        double y = y_center + len * sin(deg);
        return {x, y};
    }
};