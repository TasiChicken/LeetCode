#include <iostream>
#include <vector>

using namespace std;

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
    vector<int> findAnagrams(string s, string p) {
        vector<int> mp(26);
        for(char c : p)
            mp[c - 'a']++;
        
        int l = 0, r = 0;
        vector<int> ans;
        while(r < s.size()){
            while(l < r && mp[s[r] - 'a'] <= 0)
                mp[s[l++] - 'a']++;
            while(r < s.size() && mp[s[r] - 'a'] > 0)
                mp[s[r++] - 'a']--;
            if(l == r) l++, r++;
            else if(r - l == p.size()) ans.push_back(l);
        }
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s, p;
        cout << "s = ";
        cin >> s;
        cout <<  "p = ";
        cin >> p;

        print(solution.findAnagrams(s, p));
    }
    
    return 0;
}