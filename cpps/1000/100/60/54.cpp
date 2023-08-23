#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int sizes[3];
        sizes[1] = matrix.size();
        if(sizes[1] == 0) return ans;

        sizes[0] = matrix[0].size();
        ans.reserve(sizes[2] = sizes[0] * sizes[1]);

        int margin[2] = {0, 0}, point[2] = {0, 0}, dir = 0;
        while(true){
            ans.push_back(matrix[point[1]][point[0]]);
            if(!--sizes[2]) return ans;

            if(point[dir % 2] + (dir / 2 ? -1 : 1) == (dir / 2 ? margin[dir % 2] / 2 - 1: sizes[dir % 2] - margin[dir % 2] / 2))
                margin[(dir = ++dir % 4) % 2]++;
                
            point[dir % 2] += dir / 2 ? -1 : 1;
        }
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

void print(vector<int> v){
    cout << "[";
    for(int j = 0; j < v.size(); j++){
        cout << v[j];
        if(j != v.size() - 1) cout << ",";    
    }
    cout << "]";
    cout << endl;
}

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "matrix = ";
        cin >> s;
        vector<vector<int>> matrix = parse(s);

        print(solution.spiralOrder(matrix));
    }
    
    return 0;
}