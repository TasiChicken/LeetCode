#include <iostream>
#include <vector>

using namespace std;

vector<char> parse_(string s){
    vector<char> v;
    int last = 1;
    for(int i = 2; i < s.length(); i++)
        if(s[i] == ',' || s[i] == ']') {
            v.push_back(s[last + 1]);
            last = i + 1;
        }
    return v;
}

void print(vector<char> v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        cout << '\'' << v[i] << '\'';
        if(i != v.size() - 1) cout << ",";
    }
    cout << "]";
    cout << endl;
}

class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i = 0; i < s.size() >> 1; i++)
            swap(s[i], s[s.size() - i - 1]);
    }
};

int main() {
    while(true) {
        Solution solution;
        string ss;
        cout << "s = ";
        cin >> ss;
        auto s = parse_(ss);
        solution.reverseString(s);

        print(s);
    }
    
    return 0;
}