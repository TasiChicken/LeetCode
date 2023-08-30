#include <iostream>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        short steps[len2 + 1], temp;
        for(int i = 0; i <= len2; i++) steps[i] = i;
        for(int j = 0; j < len1; steps[0] = ++j)
            for(int i = 1; i <= len2; i++){
                temp = steps[i];
                steps[i] = word1[j] == word2[i - 1] ? steps[0] : 1 + min(steps[0], min(steps[i - 1], steps[i]));
                steps[0] = temp;
            }
        return steps[len2];
    }
};

int main() {
    while(true) {
        Solution solution;
        string word1, word2;
        cout << "word1 = ";
        cin >> word1;
        cout << "word2 = ";
        cin >> word2;

        cout << solution.minDistance(word1, word2) << endl;
    }
    
    return 0;
}