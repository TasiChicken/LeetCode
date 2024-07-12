#include <iostream>
#include <vector>
#include <unordered_map>

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

vector<double> parse_vd(string s){
    vector<double> v;
    int last = 1;
    for(int i = 2; i < s.length(); i++)
        if(s[i] == ',' || s[i] == ']') {
            v.push_back(stod(s.substr(last, i - last)));
            last = i + 1;
        }
    return v;
}

void print(vector<double> v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        cout << v[i];
        if(i != v.size() - 1) cout << ",";
    }
    cout << "]";
    cout << endl;
}

class Solution {
    unordered_map<int, int> mp;
    double frac[40][40];
    int size = 0;
    int getidx(const string& s, bool distri = true){
        int hash = 0;
        for(char c : s)
            hash = hash * 27 + c - 'a' + 1;
        
        if(mp.find(hash) == mp.end()){
            if(!distri) return -1;
            mp[hash] = size++;
        } 
        return mp[hash];
    }
    void update_frac(int a, int b){
        for(int i = 0; i < size; i++)
            if(frac[a][i] && !frac[b][i]){
                frac[b][i] = frac[b][a] * frac[a][i];
                frac[i][b] = frac[i][a] * frac[a][b];
                update_frac(b, i);
            }
            else if(frac[b][i] && !frac[a][i]){
                frac[a][i] = frac[a][b] * frac[b][i];
                frac[i][a] = frac[i][b] * frac[b][a];
                update_frac(a, i);
            }
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i = 0; i < 40; i++)
            for(int j = 0; j < 40; j++)
                frac[i][j] = i == j;

        for(int i = 0; i < equations.size(); i++){
            int a = getidx(equations[i][0]), b = getidx(equations[i][1]);
            frac[a][b] = values[i];
            frac[b][a] = 1 / values[i];
            update_frac(a, b);
        }

        vector<double> ans;
        for(auto& q : queries){
            int a = getidx(q[0], false), b = getidx(q[1], false);
            if(a == -1 || b == -1 || !frac[a][b])
                ans.push_back(-1);
            else ans.push_back(frac[a][b]);
        }
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "equations = ";
        cin >> s;
        auto equations = parse(s);
        cout << "values = ";
        cin >> s;
        auto values = parse_vd(s);
        cout << "queries = ";
        cin >> s;
        auto queries = parse(s);
        
        print(solution.calcEquation(equations, values, queries));
    }
    
    return 0;
}