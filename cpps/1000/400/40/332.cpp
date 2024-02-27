#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

vector<string> parse_(string s){
    vector<string> v;
    int last = 1;
    for(int i = 2; i < s.length(); i++)
        if(s[i] == ',' || s[i] == ']') {
            v.push_back(s.substr(last + 1, i - last - 2));
            last = i + 1;
        }
    return v;
}

vector<vector<string>> parse(string s){
    vector<vector<string>> v;
    int last;
    for(int i = 1; i < s.length() - 1; i++)
        if(s[i] == '[') last = i;
        else if(s[i] == ']') v.push_back(parse_(s.substr(last, i - last + 1)));
    return v;
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

#define my_map unordered_map<string, multiset<string>>
class Solution {
    void recursion(vector<string>& ans, string from, my_map& mp){
        while(!mp[from].empty()){
            auto to = *(mp[from].begin());
            mp[from].erase(mp[from].begin());
            recursion(ans, to, mp);
        }
        ans.push_back(from);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
       my_map mp;
        for(auto t : tickets)
            mp[t[0]].insert(t[1]);
        
        vector<string> ans;
        recursion(ans, "JFK", mp);
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "tickets = ";
        cin >> s;
        auto tickets = parse(s);

        print(solution.findItinerary(tickets));
    }
    
    return 0;
}