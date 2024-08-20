#include <iostream>
#include <vector>
#include <list>
#include <queue>

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
    int diff(string& a, string& b){
        int cnt = 0;
        for(int i = 0; i < a.size() && cnt < 2; i++)
            cnt += a[i] != b[i];
        return cnt;
    }
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        list<string> bank_list(bank.begin(), bank.end());
        queue<pair<string, int>> q;
        q.push({startGene, 0});

        while(!q.empty()){
            for(auto it = bank_list.begin(); it != bank_list.end(); )
                if(diff(q.front().first, *it) == 1){
                    if(diff(endGene, *it) == 0)
                        return q.front().second + 1;
                    q.push({*it, q.front().second + 1});
                    it = bank_list.erase(it);
                }
                else it++;
            q.pop();
        }
        return -1;
    }
};

int main() {
    while(true) {
        Solution solution;
        string startGene;
        string endGene;
        string bank_s;
        vector<string> bank;

        cout << "startGene = ";
        cin >> startGene;
        cout << "endGene = ";
        cin >> endGene;
        cout << "bank = ";
        cin >> bank_s;
        bank = parse_(bank_s);

        cout << solution.minMutation(startGene, endGene, bank) << endl;
    }
    
    return 0;
}