#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        cout << v[i];
        if(i != v.size() - 1) cout << ",";
    }
    cout << "]";
    cout << endl;
}

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int mul = rowIndex, div = 1, i;
        vector<int> v;
        v.reserve(rowIndex + 1);
        v.push_back(1);
        if(!rowIndex) return v;

        for(i = 0; i < rowIndex - 1 >> 1; i++)
            v.push_back((long long)v[i] * mul-- / div++);
        if(!(rowIndex & 1)) v.push_back((long long)v[i] * mul-- / div++);
        while(i >= 0) v.push_back(v[i--]);
        return v;
    }
};

int main() {
    while(true) {
        Solution solution;
        int rowIndex;
        cout << "rowIndex = ";
        cin >> rowIndex;
        
        print(solution.getRow(rowIndex));
    }
    
    return 0;
}