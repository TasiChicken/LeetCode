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
        int profit = 0, s = 0, b1 = -prices[0], b2 = b1;
        for(int i = 1; i < prices.size(); i++){
            profit = max(profit, b2 + prices[i]);
            b2 = max(b2, s - prices[i]);
            s = max(s, b1 + prices[i]);
            b1 = max(b1, -prices[i]);
            profit = max(profit, s);
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