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
public:
    int findMinMoves(vector<int>& machines) {
        int sum = 0;
        for(int i : machines)
            sum += i;
        if(sum % machines.size()) return -1;

        int avg = sum / machines.size();
        sum = 0;
        int ans = 0;
        for(int i : machines){
            ans = max(ans, max(abs(sum), i - avg));
            sum += i - avg;
        }
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "machines = ";
        cin >> s;
        auto machines = parse_(s);

        cout << solution.findMinMoves(machines) << endl;
    }
    
    return 0;
}