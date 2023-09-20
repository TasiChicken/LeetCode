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
    int maximumGap(vector<int>& nums) {
        int ma = nums[0], mi = nums[0], s = nums.size(), i;
        for(i = 1; i < s; i++)
            if(ma < nums[i]) ma = nums[i];
            else if(mi > nums[i]) mi = nums[i];
        if(ma == mi) return 0;
        
        auto so = new int[s][2];
        for(i = 0; i < s; i++) so[i][0] = so[i][1] = -1;

        unsigned long long index;
        for(i = 0; i < s; i++){
            index = (unsigned long long)(nums[i] - mi) * (s - 1) / (ma - mi);
            if(so[index][0] == -1) so[index][0] = so[index][1] = nums[i];
            else if(so[index][0] > nums[i]) so[index][0] = nums[i];
            else if(so[index][1] < nums[i]) so[index][1] = nums[i];
        }

        int ans = 0, cur;
        for(i = 0; i < s; i++) 
            if(so[i][0] != -1){
                cur = so[i++][1];
                break;
            }

        for(; i < s; i++){
            if(so[i][0] == -1) continue;
            ans = max(ans, so[i][0] - cur);
            cur = so[i][1];
        }
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "nums = ";
        cin >> s;
        auto nums = parse(s);

        cout << solution.maximumGap(nums) << endl;
    }
    
    return 0;
}