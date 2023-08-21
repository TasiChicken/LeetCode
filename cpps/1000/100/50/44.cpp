#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        this->s = s, this->p = p;
        lenS = s.length(), lenP = p.length();
        for(int i = lenP - 1; i >= 0; i--)
            if(p[i] == '*')
                starPos.push(i), starCount++;
        
        if (!lenP) return !lenS;
        if (lenS < lenP - starCount) return lenP == starCount;
        if (starCount == 0) {
            if(lenS != lenP) return false;
            for(int i = 0; i < lenS; i++)
                if(p[i] != s[i] && p[i] != '?') return false;
            return true;
        }

        return recursion();
    }
private:
    string s, p;
    stack<int> starPos;
    int lenS, lenP, starCount;
    bool isEqual(int posS, int posP, int len){
        if(lenS - posS < len) return false;
        for(int i = 0; i < len; i++)
            if(p[posP + i] != '?' && p[posP + i] != s[posS + i]) return false;
        return true;
    }
    bool recursion(int posS = 0, int posP = 0) {
        if (posS < 0) return false;
        if (lenP - posP == starCount) return true;
        if (posS == lenS) return false;

        int next = starPos.top();
        if (next != posP) 
            return isEqual(posS, posP, next - posP) ? recursion(posS + next - posP, next) : false;

        do {
            posP++;
            starCount--;
            starPos.pop();
            if(starCount == 0) {
                int len = lenP - posP;
                return lenS - posS >= len && isEqual(lenS - len, posP, len);
            }
        } while ((next = starPos.top()) == posP);

        int len = next - posP;
        for(int i = posS; i <= lenS - len; i++)
            if(isEqual(i, posP, len)) return recursion(i + len, next);
        return false;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s, p;
        cout << "s = ";
        cin >> s;
        cout << "p = ";
        cin >> p;

        cout << solution.isMatch(s, p) << endl;
    }
    
    return 0;
}