#include <iostream>
#include <vector>

using namespace std;

class Solution {
    string str;
    void justify(vector<string>& words, int maxWidth, int index, int amount, int vacancy) {
        int left = 0, balance = 0;
        if(amount > 1) balance = vacancy % (amount - 1), vacancy /= (amount - 1);

        for(int i = 0; i < amount; i++){
            for(char c : words[index + i]) str[left++] = c;
            if(left == maxWidth) return;
            for(int j = 0; j < vacancy; j++) str[left++] = ' ';
            if(balance) str[left++] = ' ', balance--;
        }
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth){
        str.resize(maxWidth);
        vector<string> ans;
        int vacancy = maxWidth, amount = 0, size = words.size();

        for(int i = 0 ; i < size; i++){
            int len = words[i].length();
            if(amount + len > vacancy){
                justify(words, maxWidth, i - amount, amount, vacancy);
                ans.push_back(str);
                amount = 0, vacancy = maxWidth;
            }
            vacancy -= len;
            amount++;
        }

        int left = 0;
        for(int i = 0; i < amount; i++){
            for(char c : words[size - amount + i]) str[left++] = c;
            str[left++] = ' ';
        }
        while(left < maxWidth) str[left++] = ' ';
        ans.push_back(str);
        
        return ans;
    }
};

vector<string> parse(string input) {
    vector<string> strs;
    input.erase(input.length() - 1, 1);
    input.erase(0, 1);

    if(input.length() == 0) return strs;

    int index = 0;
    for(int i = 0; i <= input.length(); i++) 
        if(input[i] == ',' || i == input.length()) {
            strs.push_back(input.substr(index + 1, i - index - 2));
            index = i + 1;
        }

    return strs;
}

void print(vector<string> v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        cout << "\"" << v[i] << "\"";
        if(i != v.size() - 1) cout << ",";
    }
    cout << "]";
    cout << endl;
}

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "words = ";
        cin >> s;
        auto words = parse(s);
        int maxWidth;
        cout << "maxWidth = ";
        cin >> maxWidth;

        print(solution.fullJustify(words, maxWidth));
    }
    
    return 0;
}