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
    int maxProfit(int k, vector<int>& prices) {
        vector<int> bs(k, -prices[0]);
        vector<int> ss(k, 0);
        int n = prices.size(), ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = min(i >> 1, k - 1); j >= 0; j--){
                ans = max(ans, ss[j] = max(ss[j], bs[j] + prices[i]));
                bs[j] = max(bs[j], (j ? ss[j - 1] : 0) - prices[i]);
            }
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        int k;
        cout << "k = ";
        cin >> k;
        string s;
        cout << "prices = ";
        cin >> s;
        auto prices = parse(s);

        cout << solution.maxProfit(k, prices) << endl;
    }
    
    return 0;
}