#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int i, n, j, k;
        int size = nums.size();
        for(n = i = 1; i < size;) n *= ++i;
        int fac = n;
        vector<vector<int>> ans(fac, nums);

        for(n = i = 1; i < size; n *= ++i)
            for(j = n; j < fac; j += n)
                if(j / n % (i + 1) != 0)
                    for(k = 0; k < n; k++)
                        swap(ans[j + k][i], ans[j + k][i - j / n % (i + 1)]);
        return ans;
    }
/* Optimized Solution(Maybe)
    vector<vector<int>> permute(vector<int>& nums) {
        int i, n, j, k;
        int size = nums.size();
        for(n = i = 1; i < size;) n *= ++i;
        int fac = n;
        vector<vector<int>> ans;
        ans.reserve(fac);
        ans.push_back(nums);

        for(n = 1, i = 0; i < size; n *= (size - i++))
            for(j = 0; j < n; j++)
                for(k = i + 1; k < size; k++){
                    ans.push_back(ans[j]);
                    swap(ans.back()[i], ans.back()[k]);
                }
            
        return ans;
    }
*/
};

vector<int> parse(string s){
    vector<int> v;
    int last = 1;
    for(int i = 2; i < s.length(); i++)
        if(s[i] == ',' || s[i] == ']') {
            v.push_back(stoi(s.substr(last, i - last)));
            last = i + 1;
        }
    return v;
}

void print(vector<vector<int>> v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        cout << "[";
        for(int j = 0; j < v[i].size(); j++){
            cout <<v[i][j];
            if(j != v[i].size() - 1) cout << ",";    
        }
        cout << "]";
        if(i != v.size() - 1) cout << ",";
    }
    cout << "]";
    cout << endl;
}

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "nums = ";
        cin >> s;
        vector<int> nums = parse(s);

        print(solution.permute(nums));
    }
    
    return 0;
}