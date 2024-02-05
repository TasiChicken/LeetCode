#include <iostream>
#include <vector>

using namespace std;

vector<int> parse_(string s){
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
        int size = prices.size();
        vector<int> own(size), sell(size), rest(size);
        own[0] = -prices[0];

        for(int i = 1; i < prices.size(); i++){
            own[i] = max(own[i - 1], rest[i - 1] - prices[i]);
            sell[i] = own[i - 1] + prices[i];
            rest[i] = max(rest[i - 1], sell[i - 1]);
        }

        return max(sell.back(), rest.back());
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "prices = ";
        cin >> s;
        auto prices = parse_(s);

        cout << solution.maxProfit(prices) << endl;
    }
    
    return 0;
}