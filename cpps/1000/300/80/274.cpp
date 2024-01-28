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
        int bucket[1001] = {0}, sum = 0, g = 0;
        for(int n : citations)
            bucket[n]++, g = max(g, n);
        
        for(int i = g; i >= 0; i--)
            if((sum += bucket[i]) >= i) return i;
        return -1;
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