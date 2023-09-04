#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [] (vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        
        int counter = 1, time = pairs[0][1];
        for(int i = 1; i < pairs.size(); i++)
            if(pairs[i][0] > time){
                counter++;
                time = pairs[i][1];
            }
        return counter;
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

vector<vector<int>> parse(string s){
    vector<vector<int>> v;
    int last;
    for(int i = 1; i < s.length() - 1; i++)
        if(s[i] == '[') last = i;
        else if(s[i] == ']') v.push_back(parse_(s.substr(last, i - last + 1)));
    return v;
}

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "pairs = ";
        cin >> s;
        auto pairs = parse(s);
        
        cout << solution.findLongestChain(pairs) << endl;
    }
    
    return 0;
}