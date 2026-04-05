#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> s;
        for(int i : candyType)
            s.insert(i);

        return min(s.size(), candyType.size() / 2);
    }
};

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

int main() {
    while(true) {
        Solution solution;
        string s;
        cin >> s;
        auto candyType = parse_(s);

        cout << solution.distributeCandies(candyType) << endl;
    }
    
    return 0;
}