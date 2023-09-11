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
    int maxProfit(vector<int>& prices) {
        int profit = 0, buy = prices[0];
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] < buy) buy = prices[i];
            else profit = max(profit, prices[i] - buy);
        }
        return profit;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "prices = ";
        cin >> s;
        auto prices = parse(s);

        cout << solution.maxProfit(prices) << endl;
    }
    
    return 0;
}