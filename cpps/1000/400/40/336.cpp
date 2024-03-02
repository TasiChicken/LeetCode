#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
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

void print(vector<vector<int>> v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        cout << "[";
        for(int j = 0; j < v[i].size(); j++){
            cout << v[i][j];
            if(j != v[i].size() - 1) cout << ",";    
        }
        cout << "]";
        if(i != v.size() - 1) cout << ",";
    }
    cout << "]";
    cout << endl;
}

class Solution {
    struct TrieNode
    {
        int index = -1;
        TrieNode* nodes[26] = {nullptr};
    };
    void insert_rev(TrieNode* head, string& s, int index){
        for(int i = s.size() - 1; i >= 0; i--){
            if(!head->nodes[s[i] - 'a']) 
                head->nodes[s[i] - 'a'] = new TrieNode();
            head = head->nodes[s[i] - 'a'];
        }
        head->index = index;
    }
    bool isPal(string& s, int l, int r){
        while(l < r)
            if(s[l++] != s[r--])
                return false;
        return true;
    }
    void findAll(TrieNode* node, vector<int>& res){
        if(!node) return;
        if(node->index != -1) res.push_back(node->index);

        for(int i = 0; i < 26; i++)
            findAll(node->nodes[i], res);
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        TrieNode* head = new TrieNode();
        for(int i = 0; i < words.size(); i++)
            insert_rev(head, words[i], i);

        vector<vector<int>> ans;
        for(int i = 0; i < words.size(); i++){
            auto node = head;
            for(int j = 0; node && j < words[i].size(); j++){
                if(node->index != -1 && node->index != i && isPal(words[i], j, words[i].size() - 1))
                    ans.push_back({i, node->index});
                
                node = node->nodes[words[i][j] - 'a'];
            }

            vector<int> res;
            findAll(node, res);
            for(int r : res)
                if(r != i && isPal(words[r], 0, words[r].size() - words[i].size() - 1))
                    ans.push_back({i, r});
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

        print(solution.palindromePairs(words));
    }
    
    return 0;
}