#include <iostream>
#include <vector>
#include <unordered_map>

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
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> mp;
        int n = nums1.size();
        for(int i = 0; i < n; i++)       
            for(int j = 0; j < n; j++)
                mp[nums1[i] + nums2[j]]++;
        int ans = 0;
        for(int i = 0; i < n; i++)       
            for(int j = 0; j < n; j++){
                int num = nums3[i] + nums4[j];
                if(mp.find(-num) != mp.end())
                    ans += mp[-num];
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
        cout << "nums3 = ";
        cin >> s;
        auto nums3 = parse_(s);
        cout << "nums4 = ";
        cin >> s;
        auto nums4 = parse_(s);

        cout << solution.fourSumCount(nums1, nums2, nums3, nums4) << endl;
    }
    
    return 0;
}