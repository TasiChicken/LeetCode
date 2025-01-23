#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area) {
        for(int i = sqrt(area); i >= 1; i--)
            if(area % i == 0)
                return {area / i, i};
        return {};
    }
};

int main() {
    while(true) {
        Solution solution;
        int area;
        cout << "area = ";
        cin >> area;

        auto ans = solution.constructRectangle(area);
        cout << '[' << ans[0] << ',' << ans[1] << ']' << endl;
    }
    
    return 0;
}