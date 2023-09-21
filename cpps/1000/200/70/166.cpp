#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(!numerator) return "0";
        string ans = numerator > 0 ^ denominator > 0 ? "-" : "";
        long long n = labs(numerator);
        long long d = labs(denominator);

        ans += to_string(n / d);
        n %= d;
        if(!n) return ans;
        ans += '.';

        int len = ans.length();
        unordered_map<long long, int> mp;
        while(n){
            auto m = mp.find(n);
            if(m != mp.end()) return ans.substr(0, m->second) + '(' + ans.substr(m->second, len - m->second + 1) + ')';

            mp[n] = len++;
            n *= 10;
            ans += n / d + '0';
            n %= d;
        }
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        int numerator, denominator;
        cout << "numerator = ";
        cin >> numerator;
        cout << "denominator = ";
        cin >> denominator;

        cout << solution.fractionToDecimal(numerator, denominator) << endl;
    }
    
    return 0;
}