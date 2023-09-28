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

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> mp(numCourses, vector<int>(1, 0));
        for(auto p : prerequisites) mp[p[1]].emplace_back(p[0]), mp[p[0]][0]++;
        queue<int> q;
        for(int i = 0; i < numCourses; i++)
            if(!mp[i][0]) q.emplace(i);
        
        int count = 0, num;
        while(q.size()){
            count++;
            num = q.front();
            q.pop();
            for(int i = 1; i < mp[num].size(); i++)
                if(!--mp[mp[num][i]][0]) q.push(mp[num][i]);
        }
        return count == numCourses;
    }
/*Optimized Solution (Maybe)
    bool possible(vector<vector<int>>& mp, vector<int>& dp, int i){
        if(dp[i]) return dp[i] > 0;
        dp[i] = -1;
        for(auto m : mp[i])
            if(!possible(mp, dp, m)) return false;
        return dp[i] = 1;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> mp(numCourses);
        for(auto p : prerequisites) mp[p[0]].emplace_back(p[1]);
        vector<int> dp(numCourses, 0);
        for(int i = 0; i < numCourses; i++)
            if(!possible(mp, dp, i)) return false;
        return true;
    }
*/
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

        cout << solution.canFinish(numCourses, prerequisites) << endl;
    }
    
    return 0;
}