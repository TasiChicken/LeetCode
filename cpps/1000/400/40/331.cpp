#include <iostream>

using namespace std;

class Solution {
    bool recursion(string& preorder, int& index){
        if(index >= preorder.size()) return false;
        
        if(preorder[index] == '#'){
            index += 2;
            return true;
        }

        while(preorder[index++] != ',')
            if(index >= preorder.size()) return false;

        return recursion(preorder, index) && recursion(preorder, index);
    }
public:
    bool isValidSerialization(string preorder) {
        int index = 0;
        return recursion(preorder, index) && index >= preorder.size();
    }
};

int main() {
    while(true) {
        Solution solution;
        string preorder;
        cout << "preorder = ";
        cin >> preorder;

        cout << solution.isValidSerialization(preorder) << endl;
    }
    
    return 0;
}