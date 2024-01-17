#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>

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

void print(vector<vector<int>> v){
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

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        sort(buildings.begin(), buildings.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0] || a[0] == b[0] && a[2] > b[2];
        });

        map<int, int> mp;
        vector<vector<int>> ans;
        int right;
        for(auto building : buildings){
            bool isAns = true, isOut = true;
            right = -1;
            for(auto it = mp.rbegin(); it != mp.rend(); ){
                if(it->first >= building[2]){
                    isAns = isAns && it->second < building[0];
                    isOut = isOut && it->second < building[1];
                }
                
                int r = right;
                right = max(right, it->second);

                if(r >= 0 && r < building[0] && it->second > r)
                    ans.push_back({ r, it->first });

                if(it->second < building[0])
                    mp.erase(it->first);
                
                else it++;
            }
            
            if(right >= 0 && right < building[0]) ans.push_back({ right, 0 });
            if(isAns) ans.push_back({ building[0], building[2] });
            if(isOut) mp[building[2]] = max(mp[building[2]], building[1]);
        }

        right = -1;
        for(auto it = mp.rbegin(); it != mp.rend(); it++){
            if(right >= 0 && it->second > right)
                ans.push_back({ right, it->first });
            right = max(right, it->second);
        }
        if(right >= 0) ans.push_back({ right, 0 });

        return ans;
    }
/*Optimized Solution 
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        set<int> s;
        for(auto b : buildings)
            s.insert(b[0]), s.insert(b[1]);

        priority_queue<pair<int, int>> pq;
        vector<vector<int>> ans;
        int ind = 0, size = buildings.size(), h = 0;
        for(auto it = s.begin(); it != s.end(); it++){
            while(ind < size && buildings[ind][0] == *it)
                pq.emplace(buildings[ind][2], buildings[ind][1]), ind++;
            
            while(!pq.empty() && pq.top().second <= *it)
                pq.pop();
            
            int y = pq.empty() ? 0 : pq.top().first;

            if(y != h) ans.push_back({ *it, h = y });
        }
        return ans;
    }
*/
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "buildings = ";
        cin >> s;
        auto buildings = parse(s);
        print(solution.getSkyline(buildings));
    }
    
    return 0;
}