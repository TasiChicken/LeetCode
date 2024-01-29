#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
    string get_word(string& s, int& from){
        if(from >= s.size()) return "";

        int start = from;
        while(from < s.size() && s[from] != ' ') from++;
        return s.substr(start, from++ - start);
    }
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;
        int from = 0;
        for(int i = 0; i < pattern.size(); i++, from){
            string word = get_word(s, from);
            if(word.empty()) return false;
            
            auto it = mp.find(pattern[i]);
            if(it != mp.end()){
                if(it->second != word) return false;
            }
            else{
                for(it = mp.begin(); it != mp.end(); it++)
                    if(it->second == word) return false;
                mp[pattern[i]] = word;
            }
        }

        return from >= s.size();
    }
};

int main() {
    while(true) {
        Solution solution;
        string pattern, s;
        cout << "pattern = ";
        cin >> pattern;
        cin.ignore(); // Ignore the newline character left in the buffer
        cout << "s = ";
        getline(cin, s);

        cout << solution.wordPattern(pattern, s) << endl;
    }
    
    return 0;
}