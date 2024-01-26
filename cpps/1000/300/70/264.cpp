#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> nums(n), fs(3), ps = {2, 3, 5};
        nums[0] = 1;
        
        for(int i = 1; i < n; i++){
            nums[i] = INT_MAX;
            for(int j = 0; j < 3; j++)
                nums[i] = min(nums[i], nums[fs[j]] * ps[j]);
            for(int j = 0; j < 3; j++)
                fs[j] += nums[i] == nums[fs[j]] * ps[j];
        }

        return nums[n - 1];
    }
};

int main() {
    while(true) {
        Solution solution;
        int n;
        cout << "n = ";
        cin >> n;
        cout << solution.nthUglyNumber(n) << endl;
    }
    
    return 0;
}