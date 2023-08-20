#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int size = candidates.size();
        record.reserve(size);
        combinationSum(candidates, target, size);
        return ans;
    }
private:
    vector<vector<int>> ans;
    vector<int> record;
    void combinationSum(vector<int>& candidates, int target, int index) {
        if(target < candidates[0]) return;
        
        int num = 0;
        for (int i = index - 1; i >= 0; i--) {
            if (num == candidates[i]) continue;
            num = candidates[i];
            if (target < num) continue;

            record.push_back(num);
            if (target == num) ans.emplace_back(record);
            else combinationSum(candidates, target - num, i);
            record.pop_back();
        }
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
        string s;
        cout << "candidates = ";
        cin >> s;
        vector<int> candidates = parse(s);
        int target;
        cout << "target = ";
        cin >> target;

        Solution solution;
        print(solution.combinationSum2(candidates, target));
    }
    
    return 0;
}