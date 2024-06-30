#include <iostream>
#include <vector>
#include <unordered_map>

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
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_map<long long, int> mp;
        for(auto& rec : rectangles){
            mp[((long long)rec[0] << 20) + rec[1]]++;
            mp[((long long)rec[2] << 20) + rec[3]]++;
            mp[((long long)rec[0] << 20) + rec[3]]--;
            mp[((long long)rec[2] << 20) + rec[1]]--;
        }
        
        int cnt = 0;
        for(auto& m : mp)
            if(m.second)
                if(abs(m.second) == 1)
                    cnt++;
                else return false;
        return cnt == 4;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "rectangles";
        cin >> s;
        auto rectangles = parse(s);

        cout << solution.isRectangleCover(rectangles) << endl;
    }
    
    return 0;
}