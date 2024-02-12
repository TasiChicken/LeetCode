#include <iostream>
#include <vector>

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

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> bits(words.size());
        
        for(int i = 0; i < words.size(); i++)
            for(char c : words[i])
                bits[i] |= 1 << c - 'a';

        int ans = 0;
        for(int i = 0; i < words.size(); i++)
            for(int j = i + 1; j < words.size(); j++){
                if(bits[i] & bits[j]) continue;
                ans = max(ans, (int)(words[i].size() * words[j].size()));
            }
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "words = ";
        cin >> s;
        auto words = parse_(s);

        cout << solution.maxProduct(words) << endl;
    }
    
    return 0;
}