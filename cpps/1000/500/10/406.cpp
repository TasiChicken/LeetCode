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
    struct ListNode {
        ListNode* next = nullptr;
        int val, ori, cur;
        ListNode(int val, int ori, int cur) :
            val(val), ori(ori), cur(cur) {}
    };
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](auto& a, auto& b){
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });

        ListNode* dummyHead = new ListNode(0, 0, 0), *node = dummyHead;
        for(auto& p : people)
            node = node->next = new ListNode(p[0], p[1], p[1]);

        vector<vector<int>> ans;
        for(int i = 0; i < people.size(); i++){
            ListNode* prev = dummyHead;
            node = dummyHead->next;
            while(node->cur){
                node->cur--;
                prev = node;
                node = node->next;
            }
            ans.push_back({node->val, node->ori});
            prev->next = node->next;
        }
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "people = ";
        cin >> s;
        auto people = parse(s);
        
        print(solution.reconstructQueue(people));
    }
    
    return 0;
}