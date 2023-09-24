#include <iostream>
#include <vector>
#include <algorithm>

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
    void s1(vector<int>& nums, int k, int n){
        int temp, index, g = __gcd(k, n);
        for(int i = 0; i < g; i++){
            temp = nums[i], index = i;
            do swap(temp, nums[index = (index + k) % n]);
            while(index != i);
        }
    }
    void s2(vector<int>& nums, int k, int n, int start = 0){
        if(k < 1) return;
        for(int i = 0; i < k; i++)
            swap(nums[start + i], nums[n - k + i]);
        s2(nums, min(k, k % (n - start - k)), n, start + k);
    }
    void s3(vector<int>& nums, int k, int n){
        auto point = nums.begin() + (n - k);
        reverse(nums.begin(), point);
        reverse(point, nums.end());
        reverse(nums.begin(), nums.end());
    }
    void s4(vector<int>& nums, int k, int n){
        vector<int> ans;
        ans.reserve(n);
        for(int i = n - k; i < n; i++)
            ans.push_back(nums[i]);
        for(int i = 0; i < n - k; i++)
            ans.push_back(nums[i]);
        nums = ans;
    }
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        s1(nums, k, n);
        //s2(nums, k, n);
        //s3(nums, k, n);
        //s4(nums, k, n);
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "nums = ";
        auto nums = parse(s);
        cin >> s;
        int k;
        cout << "k = ";
        cin >> k;

        solution.rotate(nums, k);
        print(nums);
    }
    
    return 0;
}