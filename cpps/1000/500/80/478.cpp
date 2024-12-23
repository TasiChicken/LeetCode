#include <bits/stdc++.h>

using namespace std;

class Solution {
    double radius, x_center, y_center;
public:
    Solution(double radius, double x_center, double y_center) {
        this->radius = radius;
        this->x_center = x_center;
        this->y_center = y_center;
    }
    
    vector<double> randPoint() {
        double radius = (double)rand() / RAND_MAX * this->radius;
        double angle = (double)rand() / RAND_MAX * 2 * M_PI;
        
        vector<double> ans(2);
        ans[0] = x_center + radius * cos(angle);
        ans[1] = y_center + radius * sin(angle);
        return ans;
    }
};