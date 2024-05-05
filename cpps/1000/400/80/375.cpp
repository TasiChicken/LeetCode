#include <iostream>

using namespace std;

class Solution {
    int cost[200][200];
    int getCost(int l, int r){
        if(l >= r) return 0;
        if(cost[l][r]) return cost[l][r];
        cost[l][r] = INT_MAX;
        for(int i = l; i <= r; i++)
            cost[l][r] = min(cost[l][r], 1 + i + max(getCost(l, i - 1), getCost(i + 1, r)));
        return cost[l][r];
    }
public:
    int getMoneyAmount(int n) {
        return getCost(0, n - 1);
    }
};

int main() {
    while(true) {
        Solution solution;
        int n;
        cout << "n = ";
        cin >> n;
        cout << solution.getMoneyAmount(n) << endl;
    }
    
    return 0;
}