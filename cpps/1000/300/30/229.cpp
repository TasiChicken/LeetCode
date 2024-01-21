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
    vector<int> majorityElement(vector<int>& nums) {
        int num1, count1 = 0, num2, count2 = 0;
        for(auto num : nums)
            if(!count1 && num != num2) num1 = num, count1++;
            else if(!count2 && num != num1) num2 = num, count2++;
            else if(num == num1) count1++;
            else if(num == num2) count2++;
            else count1--, count2--;

        int least = nums.size() / 3;
        count1 = count2 = 0;
        for(auto num : nums)
            if(num == num1) count1++;
            else if(num == num2) count2++;

        vector<int> ans;
        if(count1 > least) ans.push_back(num1);
        if(count2 > least) ans.push_back(num2);
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "nums = ";
        cin >> s;
        auto nums = parse_(s);
        print(solution.majorityElement(nums));
    }
    
    return 0;
}