#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> mp;
        vector<vector<string>> ans;
        for(string str : strs){
            auto temp = str;
            sort(temp.begin(), temp.end());
            int& index = mp[temp];
            if(index == 0) index = ans.size() + 1, ans.push_back(vector<string>());
            ans[index - 1].push_back(str);
        }
        return ans;
    }
};

vector<string> parse(string s){
    vector<string> v;
    int last;
    bool isTar = false;
    for(int i = 1; i < s.length() - 1; i++)
        if(s[i] == '\"') {
            if(isTar) v.push_back(s.substr(last + 1, i - last - 1)), isTar = false;
            else isTar = true;
            last = i;
        }
    return v;
}

void print(vector<vector<string>> v){
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

int main() {
    while(true) {
        Solution solution;
        
        string s;
        cout << "strs = ";
        cin >> s;
        vector<string> strs = parse(s);
        
        print(solution.groupAnagrams(strs));
    }
    
    return 0;
}