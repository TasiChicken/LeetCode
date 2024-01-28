#include <iostream>
#include <vector>

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
    int hIndex(vector<int>& citations) {
        int n = citations.size(), l = 1, r = n, m;
        if(citations[0] >= n) return n;

        while(l <= r){
            m = l + r >> 1;
            if(citations[n - m] >= m) l = m + 1;
            else r = m - 1;
        }
        return l - 1;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "citations = ";
        cin >> s;
        auto citations = parse_(s);

        cout << solution.hIndex(citations) << endl;
    }
    
    return 0;
}