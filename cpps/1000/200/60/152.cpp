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
    int getAns(int *vals, int *neg, int nptr){
        if(nptr == 0) return vals[0];
        if(nptr == 1) return max(neg[0], max(vals[0] ? vals[0] : neg[0], vals[1] ? vals[1] : neg[0]));
                
        for(int i = 0; i < 4; i++) if(!vals[i]) vals[i] = 1;
        if(nptr == 2) return vals[0] * vals[1] * vals[2] * neg[0] * neg[1];
        return max(vals[0] * vals[1] * vals[2] * neg[0] * neg[1], vals[1] * vals[2] * vals[3] * neg[1] * neg[2]);
    }
public:
    int maxProduct(vector<int>& nums){
        int *vals = new int[4], *neg = new int[3], vptr, nptr, ans = nums[0];
        
        vals[0] = vptr = nptr = 0;
        for(int n : nums)
            if(n > 0) vals[vptr] = vals[vptr] ? vals[vptr] * n : n;
            else if(!n) {
                ans = max(ans, max(0, getAns(vals, neg, nptr)));
                vals[0] = vptr = nptr = 0;
            }
            else{
                if(nptr >= 3) {
                    for(int i = 1; i < 4; i++) if(!vals[i]) vals[i] = 1;
                    vals[vptr = nptr = 1] *= vals[2] * vals[3] * neg[1] * neg[2];
                }
                vals[++vptr] = 0, neg[nptr++] = n;
            }
        return max(ans, getAns(vals, neg, nptr));
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "nums = ";
        cin >> s;
        auto nums = parse(s);

        cout << solution.maxProduct(nums) << endl;
    }
    
    return 0;
}