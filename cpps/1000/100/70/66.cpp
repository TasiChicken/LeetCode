#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        digits[size - 1] += 1;
        for(int i = size - 1; i >= 0; i--)
            if(digits[i] < 10) break;
            else {
                int carry = digits[i] / 10;
                digits[i] %= 10;
                if(i == 0) digits.insert(digits.begin(), carry);
                else digits[i - 1] += carry;
            }
        return digits;
    }
};

vector<int> parse(string s){
    vector<int> v;
    int last = 1;
    for(int i = 2; i < s.length(); i++)
        if(s[i] == ',' || s[i] == ']') {
            v.push_back(stoi(s.substr(last, i - last)));
            last = i + 1;
        }
    return v;
}

void print(vector<int> v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        cout << v[i];
        if(i != v.size() - 1) cout << ",";
    }
    cout << "]";
    cout << endl;
}

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "digits = ";
        cin >> s;
        auto digits = parse(s);

        print(solution.plusOne(digits));
    }
    
    return 0;
}