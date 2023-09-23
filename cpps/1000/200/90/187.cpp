#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void print(vector<string> v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        cout << '\'' << v[i] << '\'';
        if(i != v.size() - 1) cout << ",";
    }
    cout << "]";
    cout << endl;
}

class Solution {
    int getHash(char c){
        if(c == 'A') return 0;
        if(c == 'C') return 1;
        if(c == 'G') return 2;
        return 3;
    }
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<unsigned int> hashCodes;
        vector<string> ans;
        unsigned int c = 0, i;
        for(i = 0; i < 10; i++)
            c <<= 2, c += getHash(c);
        hashCodes.insert(c);
        for(; i < s.length(); i++){
            c -= getHash(s[i - 10]) << 18, c <<= 2, c += getHash(s[i]);
            if(hashCodes.count(c + (1 << 31))) continue;

            if(hashCodes.count(c)) ans.push_back(s.substr(i - 9, 10)), hashCodes.erase(c), hashCodes.insert(c + (1 << 31));
            else hashCodes.insert(c);
        }
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "s = ";
        cin >> s;

        print(solution.findRepeatedDnaSequences(s));
    }
    
    return 0;
}