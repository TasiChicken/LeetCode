#include <bits/stdc++.h>

using namespace std;

class Solution {
    int dist_squ(vector<int>& p1, vector<int>& p2){
        int res = 0;
        for(int i = 0; i < 2; i++)
            res += (p2[i] - p1[i]) * (p2[i] - p1[i]);
        return res;
    }
    int inner_prod(vector<int>& p1, vector<int>& p2, vector<int>& p3){
        int res = 0;
        for(int i = 0; i < 2; i++)
            res += (p2[i] - p1[i]) * (p3[i] - p2[i]);
        return res;
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int d2 = dist_squ(p1, p2);
        int d3 = dist_squ(p1, p3);
        int d4 = dist_squ(p1, p4);

        if(d2 == d3) swap(d3, d4), swap(p3, p4);
        if(d4 == d3) swap(d3, d2), swap(p3, p2);

        if(d2 != d4) return false;
        if(d3 <= d4) return false;

        if(dist_squ(p2, p3) != d2) return false;
        if(dist_squ(p4, p3) != d2) return false;

        if(inner_prod(p1, p2, p3)) return false;
        if(inner_prod(p2, p3, p4)) return false;
        if(inner_prod(p3, p4, p1)) return false;
        if(inner_prod(p4, p1, p2)) return false;

        return true;
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
        vector<vector<int>> p;

        for(int i = 0; i < 4; i++){
            cin >> s;
            p.push_back(parse_(s));
        }

        cout << solution.validSquare(p[0], p[1], p[2], p[3]) << endl; 
    }
    
    return 0;
}