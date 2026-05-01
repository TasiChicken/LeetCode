#include <bits/stdc++.h>

using namespace std;

class Solution {
    struct TreeNode{
        int idx;
        vector<TreeNode*> next;
        TreeNode() : idx(-1), next(vector<TreeNode*>(26 * 2 + 1, nullptr)) {}
    } *root = new TreeNode();
    int char2num(char c){
        if(c >= 'A' && c <= 'Z') return c - 'A';
        if(c >= 'a' && c <= 'z') return c - 'a' + 26;
        return 26 * 2;
    }
    void insert_string(string s, int idx){
        auto node = root;
        for(auto c : s){
            int n = char2num(c);
            
            if(!node->next[n]) 
                node->next[n] = new TreeNode();

            node = node->next[n];
        }
        node->idx = idx;
    }
    int find_string(string s){
        auto node = root;
        for(auto c : s){
            int n = char2num(c);
            
            if(!node->next[n]) 
                return -1;

            node = node->next[n];
        }
        return node->idx;
    }
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        for(int i = 0; i < list1.size(); i++)
            insert_string(list1[i], i);

        int sum = INT_MAX;
        vector<string> res;

        for(int i = 0; i < list2.size(); i++){
            int idx = find_string(list2[i]);

            if(idx == -1)
                continue;

            idx += i;
            if(idx > sum) continue;
            if(idx < sum) res.clear();
            res.push_back(list2[i]);
            sum = min(sum, idx);
        }

        return res;
    }
};

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

int main() {
    while(true) {
        Solution solution;
        string l1, l2;
        getline(cin, l1);
        getline(cin, l2);
        auto a = parse_(l1), b = parse_(l2);

        print(solution.findRestaurant(a, b));
    }
    
    return 0;
}
