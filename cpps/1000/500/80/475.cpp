#include <iostream>
#include <vector>
#include <algorithm>

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

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int i = 0, ans = abs(houses[0] - heaters[0]);
        for(int h : houses){
            while(i < heaters.size() - 1 && heaters[i + 1] < h)
                i++;
            if(h <= heaters[i] + ans) continue;
            if(i == heaters.size() - 1) return houses.back() - heaters.back();
            ans = min(heaters[i + 1] - h, h - heaters[i]);
        }
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "houses = ";
        cin >> s;
        auto houses = parse_(s);
        cout << "heaters = ";
        cin >> s;
        auto heaters = parse_(s);

        cout << solution.findRadius(houses, heaters) << endl;
    }
    
    return 0;
}