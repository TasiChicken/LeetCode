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
    bool greater(vector<int>& nums1, vector<int>& nums2, int i1, int i2){
        if(i1 == nums1.size()) return false;
        if(i2 == nums2.size()) return true;
        if(nums1[i1] != nums2[i2]) return nums1[i1] > nums2[i2];
        return greater(nums1, nums2, i1 + 1, i2 + 1);
    }
    vector<int> merge(vector<int>& nums1, vector<int>& nums2){
        vector<int> ans;
        ans.reserve(nums1.size() + nums2.size());

        int i1 = 0, i2 = 0;
        while(i1 < nums1.size() || i2 < nums2.size()){
            if(greater(nums1, nums2, i1, i2)) ans.push_back(nums1[i1++]);
            else ans.push_back(nums2[i2++]);
        }
        return ans;
    }
    vector<int> max_sub(vector<int> nums, int k){
        vector<int> ans;
        ans.reserve(k);
        
        for(int i = 0; i < nums.size(); i++){
            while(!ans.empty() && nums[i] > ans.back() && nums.size() - i > k - ans.size()) ans.pop_back();
            if(ans.size() < k) ans.push_back(nums[i]);
        }
        return ans;
    }
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans;
        for(int i = max((int)(k - nums2.size()), 0); i <= min((int)nums1.size(), k); i++){
            auto a = max_sub(nums1, i), b = max_sub(nums2, k - i);
            auto temp = merge(a, b);
            if(greater(temp, ans, 0, 0)) ans = temp;
        }
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "nums1 = ";
        cin >> s;
        auto nums1 = parse_(s);
        cout << "nums2 = ";
        cin >> s;
        auto nums2 = parse_(s);
        int k;
        cout << "k = ";
        cin >> k;

        print(solution.maxNumber(nums1, nums2, k));
    }
    
    return 0;
}