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
    int compress(vector<char>& chars) {
        int tail = 0, head = 0;
        for(int i = 1; i < chars.size(); i++)
            if(chars[i] == chars[head]){
                if(tail == head) tail = head + 1, chars[tail] = '2';
                else chars[tail]++;

                for(int j = tail; j > head; j--)
                    if(chars[j] <= '9') break;
                    else if(j != head + 1)
                        chars[j] -= 10, chars[j - 1]++;
                    else{
                        for(int k = tail; k > head; k--)
                            chars[k + 1] = chars[k];
                        chars[j + 1] -= 10, chars[j] = '1';
                        tail++;
                    }
            }
            else head = ++tail, chars[tail] = chars[i];
        chars.resize(tail + 1);
        return tail + 1;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "chars = ";
        cin >> s;
        auto chars = parse_(s);

        cout << solution.compress(chars) << endl;
        print(chars);
    }
    
    return 0;
}