#include <iostream>

using namespace std;

class WordDictionary {
    WordDictionary* dic[26];
    bool end = false;
    
    void addWord(string &word, int start){
        if(start == word.length()){
            end = true;
            return;
        } 

        int index = word[start] - 'a';
        if(!dic[index]) dic[index] = new WordDictionary();
        dic[index]->addWord(word, start + 1);
    }

    bool search(string& word, int start){
        if(start == word.length()) return end;
        if(word[start] != '.'){
            int index = word[start] - 'a';
            return dic[index] && dic[index]->search(word, start + 1);
        }

        for(int index = 0; index < 26; index++)
            if(dic[index] && dic[index]->search(word, start + 1))
                return true;
        return false;
    }
public:
    WordDictionary() {
        for(int i = 0; i < 26; i++) 
            dic[i] = nullptr;
    }

    void addWord(string word) {
        addWord(word, 0);
    }
    
    bool search(string word) {
        return search(word, 0);
    }
};