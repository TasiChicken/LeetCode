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

void print(vector<string> v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        cout << '\"' << v[i] << '\"';
        if(i != v.size() - 1) cout << ",";
    }
    cout << "]";
    cout << endl;
}

class Solution {
    const string medal[3] = {"Gold", "Silver", "Bronze"};
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int, int>> temp;
        for(int i = 0; i < score.size(); i++)
            temp.emplace_back(score[i], i);
        sort(temp.begin(), temp.end());
        
        vector<string> ans(temp.size());
        for(int i = 0; i < (int)temp.size() - 3; i++)
            ans[temp[i].second] = to_string(temp.size() - i);
        
        for(int i = 1; i <= 3; i++)
            if(temp.size() >= i) 
                ans[temp[temp.size() - i].second] = medal[i - 1] + " Medal";

        return ans;

    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "score = ";
        cin >> s;
        auto score = parse_(s);

        print(solution.findRelativeRanks(score));
    }
    
    return 0;
}