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
    void merge(vector<int>& ans, vector<pair<int, int>>& p_nums, pair<int, int>* temp, int l, int r){
        if(l >= r) return;

        int mid = l + r >> 1;
        merge(ans, p_nums, temp, l, mid);
        merge(ans, p_nums, temp, mid + 1, r);

        for(int i = 0; i <= mid - l; i++)
            temp[i] = p_nums[i + l];

        int r_idx = mid + 1, cnt = 0, idx = l;
        for(int i = 0; i <= mid - l; i++){
            while(r_idx <= r && p_nums[r_idx].first < temp[i].first) p_nums[idx++] = p_nums[r_idx++], cnt++;

            p_nums[idx++] = temp[i];
            ans[temp[i].second] += cnt;
        }
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int s = nums.size();
        vector<int> ans(s);
        vector<pair<int, int>> p_nums;
        p_nums.reserve(s);
        for(int i = 0; i < s; i++)
            p_nums.emplace_back(nums[i], i);

        merge(ans, p_nums, new pair<int, int>[s / 2 + 1], 0, s - 1);
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

        print(solution.countSmaller(nums));
    }
    
    return 0;
}