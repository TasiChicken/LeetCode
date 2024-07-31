#include <iostream>
#include <vector>

using namespace std;

void print(vector<string> v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        cout << '\"' << v[i] << '\"';
        if(i != v.size() - 1) cout << ",";
    }
    cout << "]";
    cout << endl;
}

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans(n);
        for(int i = 1; i <= n; i++){
            if(i % 15 == 0)
                ans[i - 1] = "FizzBuzz";
            else if(i % 5 == 0)
                ans[i - 1] = "Buzz";
            else if(i % 3 == 0)
                ans[i - 1] = "Fizz";
            else ans[i - 1] = to_string(i);
        }
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        int n;
        cout << "n = ";
        cin >> n;

        print(solution.fizzBuzz(n));
    }
    
    return 0;
}