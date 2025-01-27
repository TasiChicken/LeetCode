#include <bits/stdc++.h>

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
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> s(1, nums2.back());
        unordered_map<int, int> mp;
        for(int i = nums2.size() - 2; i >= 0; i--)
            if(s[0] > nums2[i]){
                int l = 0, r = s.size() - 1;
                while(l < r){
                    int mid = l + r + 1 >> 1;
                    if(s[mid] > nums2[i]) l = mid;
                    else r = mid - 1;
                }

                mp[nums2[i]] = s[l];
                
                s.resize(l + 1), s.push_back(nums2[i]);
            }
            else s.clear(), s.push_back(nums2[i]);
        
        vector<int> ans(nums1.size());
        for(int i = 0; i < ans.size(); i++)
            ans[i] = mp.find(nums1[i]) == mp.end() ? -1 : mp[nums1[i]];
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

        print(solution.nextGreaterElement(nums1, nums2));
    }
    
    return 0;
}