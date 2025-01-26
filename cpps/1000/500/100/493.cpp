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

class Solution {
    int merge(vector<int>& a, vector<int>& b, int l, int r){
        if(r - l < 1) return 0;
        if(r - l == 1){
            if(a[l] > a[r]) swap(b[l], b[r]);
            return a[l] > a[r] * 2ll;
        }
            
        int mid = l + r >> 1;
        int ans = merge(b, a, l, mid - 1) + merge(b, a, mid, r);

        for(int i = l, j = mid, k = l; k <= r; k++)
            b[k] = j > r || i < mid && a[i] < a[j] ? a[i++] : a[j++];
        
        for(int i = l, j = mid; i < mid; i++){
            while(j <= r && a[i] > 2ll * a[j]) j++;
            
            ans += j - mid;
            if(j <= r) continue;

            ans += (mid - i - 1) * (j - mid);
            break;
        }

        return ans;
    }
public:
    int reversePairs(vector<int>& nums) {
        vector<int> temp(nums);
        return merge(nums, temp, 0, nums.size() - 1);
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "s = ";
        cin >> s;
        auto nums = parse_(s);

        cout << solution.reversePairs(nums) << endl;
    }
    
    return 0;
}