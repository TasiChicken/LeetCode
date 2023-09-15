#include <iostream>
#include <vector>

using namespace std;

vector<int> parse(string s){
    vector<int> v;
    int last = 1;
    for(int i = 2; i < s.length(); i++)
        if(s[i] == ',' || s[i] == ']') {
            v.push_back(stoi(s.substr(last, i - last)));
            last = i + 1;
        }
    return v;
}

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), sum = 0, index = 0, tempSum = 0;
        
        for(int i = 0; i < n; i++){
            if(tempSum < 0) sum += tempSum, tempSum = 0, index = i;
            tempSum += gas[i] - cost[i];
        }

        return tempSum < 0 || sum + tempSum < 0 ? -1 : index;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "gas = ";
        cin >> s;
        auto gas = parse(s);
        cout << "cost = ";
        cin >> s;
        auto cost = parse(s);

        cout << solution.canCompleteCircuit(gas, cost) << endl;
    }
    
    return 0;
}