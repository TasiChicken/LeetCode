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
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int n : nums)
            sum += n;
        if(sum & 1) return 0;
        sum >>= 1;
        
        for(int n : nums)
            if(n >= sum) 
                return n == sum;

        vector<bool> subset(sum, false), temp;
        for(int n : nums){
            temp = subset;
            for(int i = 0; i < sum; i++)
                if(temp[i]){
                    if(i + n < sum)
                        subset[i + n] = true;
                    if(subset.back())
                        return true;
                }
            subset[n - 1] = true;
        }
        return false;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "nums = ";
        cin >> s;
        auto nums = parse_(s);

        cout << solution.canPartition(nums) << endl;
    }
    
    return 0;
}