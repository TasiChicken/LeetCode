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

vector<vector<int>> parse(string s){
    vector<vector<int>> v;
    int last;
    for(int i = 1; i < s.length() - 1; i++)
        if(s[i] == '[') last = i;
        else if(s[i] == ']') v.push_back(parse_(s.substr(last, i - last + 1)));
    return v;
}

class Solution {
    void replace(vector<int>& ws, int num){
        int l = 1, r = ws.size() - 1;
        while(l <= r){
            mid = l + r >> 1;
            if(ws[mid] >= num && ws[mid - 1] < num) {
                ws[mid] = num;
                return;
            }

            if(ws[mid] > num) r = mid - 1;
            else l = mid + 1;
        }
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1];
        });

        vector<int> ws(1, envelopes[0][1]);
        for(int i = 1; i < envelopes.size(); i++)
            if(envelopes[i][1] > ws.back()) ws.push_back(envelopes[i][1]);
            else if(envelopes[i][1] < ws[0]) ws[0] = envelopes[i][1];
            else replace(ws, envelopes[i][1]);
        return ws.size();
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "envelopes = ";
        cin >> s;
        auto envelopes = parse(s);

        cout << solution.maxEnvelopes(envelopes) << endl;
    }
    
    return 0;
}