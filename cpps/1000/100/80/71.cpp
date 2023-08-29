#include <iostream>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string ans = "/";
        int len = path.length();
        ans.reserve(len);

        for(int i = 1; i < len; i++){
            if(path[i] == '/' && ans.back() == '/') continue;
            if(path[i - 1] == '/' && path[i] == '.')
                if(i == len - 1 || path[i + 1] == '/') continue;
                else if(path[i - 1] == '/' && path[i + 1] == '.' && (i == len - 2 || path[i + 2] == '/')){
                    do 
                        if(ans.length() > 1) ans.pop_back();
                        else break;
                    while (ans.back() != '/');
                    i++;
                    continue;
                }
            ans.push_back(path[i]);
        }
        if(ans.length() > 1 && ans.back() == '/') ans.pop_back();
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string path;
        cout << "path = ";
        cin >> path;

        cout << solution.simplifyPath(path) << endl;
    }
    
    return 0;
}