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
    int index(int num){
        for(int i = 0; i < 5; i++)
            if(!(num & (1 << 7 - i)))
                return i;
        return -1;
    }
    bool find1(vector<int>& data, int i){
        return i < data.size() && index(data[i]) == 1;
    }
public:
    bool validUtf8(vector<int>& data) {
        for(int i = 0; i < data.size(); i++){
            int idx = index(data[i]);
            if(abs(idx) == 1) return false;
            if(idx == 0) continue;

            for(int j = 1; j < idx; j++)
                if(!find1(data, i + j))
                    return false;
            i += idx - 1;
        }
        return true;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "data = ";
        cin >> s;
        auto data = parse_(s);

        cout << solution.validUtf8(data) << endl;

    }
    
    return 0;
}