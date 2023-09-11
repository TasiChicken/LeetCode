#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int size = matrix[0].size();
        int left = 0, right = matrix.size() * size - 1;
        while(left <= right){
            int mid = left + right >> 1;
            int num = matrix[mid / size][mid % size];
            if(num == target) return true;
            if(num < target) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
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

vector<vector<int>> parse(string s){
    vector<vector<int>> v;
    int last;
    for(int i = 1; i < s.length() - 1; i++)
        if(s[i] == '[') last = i;
        else if(s[i] == ']') v.push_back(parse(s.substr(last, i - last + 1)));
    return v;
}

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "matrix = ";
        cin >> s;
        auto matrix = parse(s);
        int target;
        cout << "target = ";
        cin >> target;
        
        cout << solution.searchMatrix(matrix, target) << endl;
    }
    
    return 0;
}