#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(!n) return true;

        for(int i = 0; i < flowerbed.size(); i++){
            if(flowerbed[i]) continue;

            if(i != 0 && flowerbed[i - 1]) continue;
            if(i != flowerbed.size() - 1 && flowerbed[i + 1]) continue;

            if(--n == 0) return true;
            i++;
        }

        return false;
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
        cin >> s;
        int n;
        cin >> n;
        auto f = parse_(s);

        cout << solution.canPlaceFlowers(f, n) << endl;
    }
    
    return 0;
}