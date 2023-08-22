#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> ans;
        ans.push_back(nums);

        int i, n, j, k;
        unordered_set<int> set;
        for(i = 0; i < size; i++){
            int curSiz = ans.size();
            for(j = 0; j < curSiz; j++){
                set.clear();
                for(k = i + 1; k < size; k++){
                    if(ans[j][i] == ans[j][k] || set.count(ans[j][k])) continue;

                    set.insert(ans[j][k]);
                    ans.push_back(ans[j]);
                    swap(ans.back()[i], ans.back()[k]);
                }
            }
        }
        return ans;
    }
};

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

void print(vector<vector<int>> v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        cout << "[";
        for(int j = 0; j < v[i].size(); j++){
            cout <<v[i][j];
            if(j != v[i].size() - 1) cout << ",";    
        }
        cout << "]";
        if(i != v.size() - 1) cout << ",";
    }
    cout << "]";
    cout << endl;
}

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "nums = ";
        cin >> s;
        vector<int> nums = parse(s);

        print(solution.permuteUnique(nums));
    }
    
    return 0;
}