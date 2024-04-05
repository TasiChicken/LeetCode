#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> parse_(string s){
    vector<int> v;
    int last = 1;
    for(int i = 2; i < s.length(); i++)
        if(s[i] == ',' || s[i] == ']') {
            v.push_back(stoi(s.substr(last, i - last)));
            last = i + 1;
        }
    return v;
}

vector<vector<int>> parse(string s){
    vector<vector<int>> v;
    int last;
    for(int i = 1; i < s.length() - 1; i++)
        if(s[i] == '[') last = i;
        else if(s[i] == ']') v.push_back(parse_(s.substr(last, i - last + 1)));
    return v;
}

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i < m; i++)
            for(int j = 1; j < n; j++)
                matrix[i][j] += matrix[i][j - 1];
        
        int ans = INT_MIN;
        set<int> st;

        for(int i = 0; i < n; i++)
            for(int j = i; j < n; j++){
                st.clear();
                int sum = 0;
                for(int x = 0; x < m; x++){
                    sum += matrix[x][j];
                    if(i) sum -= matrix[x][i - 1];

                    if(sum <= k) ans = max(ans, sum);

                    auto it = st.upper_bound(sum - k - 1);
                    if(it != st.end()) ans = max(ans, sum - *it);

                    st.insert(sum);
                }
            }
        
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "matrix = ";
        cin >> s;
        auto matrix = parse(s);
        int k;
        cout << "k = ";
        cin >> k;

        cout << solution.maxSumSubmatrix(matrix, k) << endl;
    }
    
    return 0;
}