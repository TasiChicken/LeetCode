#include <iostream>
#include <vector>

using namespace std;

vector<string> parse(string s){
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
    bool d1(string& a, string& b, int len){
        bool f = true;
        while(len)
            if(a[--len] != b[len]) 
                if(f) f = false;
                else return false;
        return true;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = beginWord.length(), back = wordList.size() - 1, start = back - 1;
        for(int i = 0; i < back; i++) 
            if(wordList[i] == endWord){
                swap(wordList[i], wordList[back]);
                break;
            }
        if(wordList[back] != endWord) return 0;

        int ans = 1;
        while(start >= -1){
            int s = start;
            ans++;
            for(; back > s; back--){
                if(d1(beginWord, wordList[back], n)) return ans;
                for(int j = start; j >= 0; j--)
                    if(d1(wordList[j], wordList[back], n))
                        swap(wordList[j], wordList[start--]);
            }
            if(s == start) return 0;
        }
        return 0;
    }
};

int main() {
    while(true) {
        Solution solution;
        string beginWord, endWord, s;
        cout << "beginWord = ";
        cin >> beginWord;
        cout << "endWord = ";
        cin >> endWord;
        cout << "wordList = ";
        cin >> s;
        auto wordList = parse(s);

        cout << solution.ladderLength(beginWord, endWord, wordList) << endl;
    }
    
    return 0;
}