#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
    string str_add(string a, string b){
        if(a.size() < b.size()) swap(a, b);

        reverse(a.begin(), a.end());
        for(int i = 0; i < a.size(); i++){
            if(i < b.size()) a[i] += b[b.size() - i - 1] - '0';
            if(a[i] > '9'){
                if(i + 1 == a.size()) a.push_back('0');
                a[i + 1] += (a[i] - '0') / 10;
                a[i] = (a[i] - '0') % 10 + '0';
            }
        }
        reverse(a.begin(), a.end());
        return a;
    }
public:
    bool isAdditiveNumber(string num) {
        for(int i = 1; i < num.size(); i++)
            for(int j = i + 1; j < num.size() && (num[i] != '0' || j == i + 1); j++){
                string a = num.substr(0, i), b = num.substr(i, j - i);
                int ind = j;
                while(ind < num.size()){
                    auto temp = str_add(a, b);
                    for(int k = 0; k < temp.size(); k++)
                        if(temp[k] != num[ind + k]){
                            ind = -1;
                            break;
                        }
                    if(ind == -1) break;

                    ind += temp.size();
                    a = b;
                    b = temp;
                }
                if(ind != -1) 
                return true;
            }

        return false;
    }
};

int main() {
    while(true) {
        Solution solution;
        string num;
        cout << "num = ";
        cin >> num;

        cout << solution.isAdditiveNumber(num) << endl;
    }
    
    return 0;
}