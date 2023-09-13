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

void print(vector<vector<string>> v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        cout << "[";
        for(int j = 0; j < v[i].size(); j++){
            cout << '\'' << v[i][j] << '\'';
            if(j != v[i].size() - 1) cout << ",";    
        }
        cout << "]";
        if(i != v.size() - 1) cout << ",";
    }
    cout << "]";
    cout << endl;
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
    void addAns(vector<vector<string>> &ans, vector<string> &v, vector<string>& wordList, vector<vector<int>>& next, int index){
        v.push_back(wordList[index]);
        if(!next[index].size()) ans.push_back(v);
        else 
            for(int i : next[index])
                addAns(ans, v, wordList, next, i);
        v.pop_back();
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        int n = beginWord.length(), back = wordList.size() - 1, start = back - 1;
        for(int i = 0; i < back; i++) 
            if(wordList[i] == endWord){
                swap(wordList[i], wordList[back]);
                break;
            }
        if(wordList[back] != endWord) return ans;

        vector<vector<int>> next(back + 1, vector<int>());

        vector<string> v;
        v.push_back(beginWord);
        while(start >= -1){
            int s = start;
            for(; back > s; back--){
                if(d1(beginWord, wordList[back], n)){
                    addAns(ans, v, wordList, next, back);
                    continue;
                }
                for(int j = s; j > start; j--)
                    if(d1(wordList[j], wordList[back], n))
                        next[j].push_back(back);
                for(int j = start; j >= 0; j--)
                    if(d1(wordList[j], wordList[back], n))
                        swap(wordList[j], wordList[start]), next[start--].push_back(back);
            }
            if(s == start || ans.size()) return ans;
        }
        return ans;
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

        print(solution.findLadders(beginWord, endWord, wordList));
    }
    
    return 0;
}