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

void print(vector<vector<int>> v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        cout << "[";
        for(int j = 0; j < v[i].size(); j++){
            cout << v[i][j];
            if(j != v[i].size() - 1) cout << ",";    
        }
        cout << "]";
        if(i != v.size() - 1) cout << ",";
    }
    cout << "]";
    cout << endl;
}

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int num : nums1)
            pq.push({num + nums2[0], 0});

        vector<vector<int>> ans;
        for(int i = 0; i < k; i++){
            int sum = pq.top().first, i2 = pq.top().second, num1 = sum - nums2[i2];
            pq.pop();

            ans.push_back({num1, nums2[i2]});
            if(++i2 < nums2.size())
                pq.push({num1 + nums2[i2], i2});
        }
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "nums1 = ";
        cin >> s;
        auto nums1 = parse_(s);
        cout << "nums = ";
        cin >> s;
        auto nums2 = parse_(s);
        int k;
        cout << "k = ";
        cin >> k;

        print(solution.kSmallestPairs(nums1, nums2, k));
    }
    
    return 0;
}