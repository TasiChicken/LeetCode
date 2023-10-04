#include <iostream>
#include <vector>
#include <queue>

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

vector<vector<int>> parse(string s){
    vector<vector<int>> v;
    int last;
    for(int i = 1; i < s.length() - 1; i++)
        if(s[i] == '[') last = i;
        else if(s[i] == ']') v.push_back(parse_(s.substr(last, i - last + 1)));
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

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> mp(numCourses);
        vector<int> re(numCourses, 0);
        for(auto p : prerequisites) mp[p[1]].emplace_back(p[0]), re[p[0]]++;
        
        vector<int> ans;
        for(int i = 0; i < numCourses; i++)
            if(!re[i]) ans.emplace_back(i);

        for(int i = 0; i < ans.size(); i++)
            for(int c : mp[ans[i]])
                if(!--re[c]) ans.push_back(c);
        if(ans.size() != numCourses) return {};
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        int numCourses;
        cout << "numCourses = ";
        cin >> numCourses;
        string s;
        cout << "prerequisites = ";
        cin >> s;
        auto prerequisites = parse(s);

        print(solution.findOrder(numCourses, prerequisites));
    }
    
    return 0;
}