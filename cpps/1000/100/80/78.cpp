#include <iostream>
#include <vector>

using namespace std;

class Solution {
    void recursion(vector<int>& nums, vector<vector<int>>& ans, vector<int>& v, int size, int n, int index = 0){
        if(!n) return ans.push_back(v);

        for(int i = index; i < size; i++){
            v.push_back(nums[i]);
            recursion(nums, ans, v, size, n - 1, i + 1);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        int size = nums.size();
        v.reserve(size);

        for(int i = 0; i <= size; i++)
            recursion(nums, ans, v, size, i);
        return ans;
    }
};

void print(vector<vector<int>> v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        cout << "[";
        for(int j = 0; j < v[i].size(); j++){
            cout << v[i][j];
            if(j != v[i].size() - 1) cout << ",";    
        }
        cout << "]";
        if(i != v.size() - 1) cout << ",";
    }
    cout << "]";
    cout << endl;
}

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

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "nums =";
        cin >> s;
        auto nums = parse(s);
        
        print(solution.subsets(nums));
    }
    
    return 0;
}