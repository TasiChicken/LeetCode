#include <iostream>
#include <vector>

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
    int rank_minus(vector<vector<int>>& matrix, int num){
        int j = 0, ans = 0;
        while(j < matrix[0].size() - 1 && matrix[0][j] < num) j++;
        for(int i = 0; i < matrix.size(); i++){
            while(j >= 0 && matrix[i][j] >= num) j--;
            if(j < 0) break;
            ans += j + 1;
        }
        return ans;
    }
    int rank_plus(vector<vector<int>>& matrix, int num){
        int j = 0, ans = 0;
        while(j < matrix[0].size() - 1 && matrix[0][j] <= num) j++;
        for(int i = 0; i < matrix.size(); i++){
            while(j >= 0 && matrix[i][j] > num) j--;
            if(j < 0) break;
            ans += j + 1;
        }
        return ans;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int l = matrix[0][0], r = matrix.back().back();
        while(l < r){
            int mid = l + r >> 1;
            int rm = rank_minus(matrix, mid), rp = rank_plus(matrix, mid);

            if(rm < k && k <= rp) return mid;
            if(k <= rm) r = mid - 1;
            else l = mid + 1;
        }
        return l;
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

        cout << solution.kthSmallest(matrix, k) << endl;
    }
    
    return 0;
}