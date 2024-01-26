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

void print(vector<int> v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        cout << v[i];
        if(i != v.size() - 1) cout << ",";
    }
    cout << "]";
    cout << endl;
}


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int a = 0;
        for(int n : nums)
            a ^= n;

        int diff = 1;
        while(!(diff & a)) diff <<= 1;

        int b = a = 0;
        for(int n : nums)
            if(diff & n) a ^= n;
            else b ^= n;
        return {a, b};
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "nums = ";
        cin >> s;
        auto nums = parse_(s);

        print(solution.singleNumber(nums));
    }
    
    return 0;
}