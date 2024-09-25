#include <iostream>
#include <vector>
#include <algorithm>

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

void print(vector<string> v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        cout << '\"' << v[i] << '\"';
        if(i != v.size() - 1) cout << ",";
    }
    cout << "]";
    cout << endl;
}

class Solution {
    struct DictTreeNode {
        DictTreeNode *next[26] = {};
        bool ending = false;
    } *head = new DictTreeNode;

    bool check(string& s, int idx = 0){
        auto node = head;
        for(int i = idx; i < s.size() - (idx == 0); i++){
            node = node->next[s[i] - 'a'];
            if(!node) return false;
            if(node->ending && (i == s.size() - 1 || check(s, i + 1)))
                return true;
        }
        return false;
    }
    void insert(string& s){
        auto node = head;
        for(auto c : s){
            if(!node->next[c - 'a']) 
                node->next[c - 'a'] = new DictTreeNode;
            node = node->next[c - 'a'];
        }
        node->ending = true;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), [&](const string& a, const string& b) {
            return a.size() < b.size();
        });

        vector<string> ans;
        for(auto s : words)
            if(check(s))
                ans.push_back(s);
            else insert(s);
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

        auto ans = solution.findAllConcatenatedWordsInADict(words);
        print(ans);
    }
    
    return 0;
}