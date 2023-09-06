#include <iostream>
#include <vector>

using namespace std;

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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = m; i-- > 0;) nums1[n + i] = nums1[i];
        
        int p1 = 0, p2 = 0;
        for(int i = 0; p2 < n && i < m + n; i++){

            if(p1 < m && nums1[n + p1] < nums2[p2]) nums1[i] = nums1[n + p1++];
            else nums1[i] = nums2[p2++];
        }
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "num1 = ";
        cin >> s;
        auto nums1 = parse(s);
        int n, m;
        cout << "m = ";
        cin >> m;
        cout << "num2 = ";
        cin >> s;
        auto nums2 = parse(s);
        cout << "n = ";
        cin >> n;

        solution.merge(nums1, m, nums2, n);
        print(nums1);
    }
    
    return 0;
}