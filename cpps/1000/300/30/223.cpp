#include <iostream>

using namespace std;

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area = (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1);
        int x = min(ax2, bx2) - max(ax1, bx1), y = min(ay2, by2) - max(ay1, by1);
        if(x <= 0 || y <= 0) return area;
        return area - x * y;
    }
};

int main() {
    while(true) {
        Solution solution;
        int ax1, ay1, ax2, ay2, bx1, by1, bx2, by2;
        cout << "ax1 = ";
        cin >> ax1;
        cout << "ay1 = ";
        cin >> ay1;
        cout << "ax2 = ";
        cin >> ax2;
        cout << "ay2 = ";
        cin >> ay2;
        cout << "bx1 = ";
        cin >> bx1;
        cout << "by1 = ";
        cin >> by1;
        cout << "bx2 = ";
        cin >> bx2;
        cout << "by2 = ";
        cin >> by2;
        cout << solution.computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2) << endl;
    }
    
    return 0;
}