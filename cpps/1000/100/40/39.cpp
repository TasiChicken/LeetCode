#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target, int max = 40) {
        vector<vector<int>> ans;
        if(target < 2) return ans;

        for (int i : candidates) {
            if(i > max) continue;
            if (target == i) {
                ans.emplace_back(1, i);
                continue;
            }

            auto get = combinationSum(candidates, target - i, i);
            for(auto v : get){
                v.push_back(i);
                ans.push_back(v);
            }
        }

        return ans;
    }
/* Optimized Solution
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        record.reserve(target / candidates[0]);
        combinationSum(candidates, target, candidates.size() - 1);
        return ans;
    }
private:
    vector<vector<int>> ans;
    vector<int> record;
    void combinationSum(vector<int>& candidates, int target, int index) {
        if(target < candidates[0]) return;
        for (int i = index; i >= 0; i--) {
            int num = candidates[i];
            if (target < num) continue;

            record.push_back(num);
            if (target == num) ans.emplace_back(record);
            else combinationSum(candidates, target - num, i);
            record.pop_back();
        }
    }
*/
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
        string s;
        cout << "candidates = ";
        cin >> s;
        vector<int> candidates = parse(s);
        int target;
        cout << "target = ";
        cin >> target;

        Solution solution;
        print(solution.combinationSum(candidates, target));
    }
    
    return 0;
}