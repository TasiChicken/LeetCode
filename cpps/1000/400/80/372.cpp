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
    int pow(int a, int b){
        int ans = 1;
        while (b--)
            ans = (ans * (a % 1337)) % 1337;
        return ans;        
    }
public:
    int superPow(int a, vector<int>& b) {
        int ans = 1;
        for(int i = b.size() - 1; i >= 0; i--){
            ans = ans * pow(a, b[i]) % 1337;
            a = pow(a, 10) % 1337;
        }
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        int a;
        cout << "a = ";
        cin >> a;
        string s;
        cout << "b = ";
        cin >> s;
        auto b = parse_(s);

        cout << solution.superPow(a, b) << endl;
    }
    
    return 0;
}