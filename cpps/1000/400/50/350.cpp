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
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mp(1001);
        for(int num : nums1)
            mp[num]++;

        vector<int> ans;
        for(int num : nums2)
            if(mp[num]) ans.push_back(num), mp[num]--;
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

        print(solution.intersect(nums1, nums2));
    }
    
    return 0;
}