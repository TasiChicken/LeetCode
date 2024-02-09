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
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> seq(n, INT_MAX), ptr(primes.size(), 0);
        seq[0] = 1;

        for(int i = 1; i < n; i++){
            for(int j = 0; j < primes.size(); j++)
                seq[i] = min(seq[i], seq[ptr[j]] * primes[j]);
            for(int j = 0; j < primes.size(); j++)
                if(seq[i] == seq[ptr[j]] * primes[j])
                    ptr[j]++;
        }
        return seq.back();
    }
};

int main() {
    while(true) {
        Solution solution;
        int n;
        cout << "n = ";
        cin >> n;
        string s;
        cout << "primes = ";
        cin >> s;
        auto primes = parse_(s);

        cout << solution.nthSuperUglyNumber(n, primes) << endl;
    }
    
    return 0;
}