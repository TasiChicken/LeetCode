#include <iostream>

using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length(), counter;

        for(int i = 0; i < n; i++){
            if(customers[i] == 'Y') continue;

            counter = 1;
            for(int j = i + 1; j < n; j++)
                if((counter += customers[j] == 'Y' ? -1 : 1) < 0) {
                    i = j;
                    break;
                }
            if(counter >= 0) return i;
        }
        return n;
    }
};

int main() {
    while(true) {
        Solution solution;
        string customers;
        cout << "customers = ";
        cin >> customers;

        cout << solution.bestClosingTime(customers) << endl;
    }
    
    return 0;
}