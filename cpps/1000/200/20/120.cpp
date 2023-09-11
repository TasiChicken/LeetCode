#include <iostream>
#include <vector>

using namespace std;

vector<int> parse(string s){
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
        else if(s[i] == ']') v.push_back(parse(s.substr(last, i - last + 1)));
    return v;
}

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle, int layer = 0, int index = 0) {
        for(int i = triangle.size() - 2; i >= 0; i--){
            for(int j = 0; j <= i; j++)
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
        return triangle[0][0];
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "triangle";
        cin >> s;
        auto triangle = parse(s);

        cout << solution.minimumTotal(triangle) << endl;
    }
    
    return 0;
}