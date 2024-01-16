#include <iostream>
#include <vector>
#include <queue>

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

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        int count = 0;
        for(auto num : nums){
            pq.push(num);
            if(++count > k) pq.pop(), count--;
        }
        return pq.top();
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "nums = ";
        cin >> s;
        int k;
        cout << "k = ";
        cin >> k;
        auto nums = parse_(s);
        cout << solution.findKthLargest(nums, k) << endl;
    }
    
    return 0;
}