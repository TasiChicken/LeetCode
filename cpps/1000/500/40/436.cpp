#include <iostream>
#include <vector>
#include <algorithm>

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
    int binary_search(vector<vector<int>>& order, int num){
        int l = 0, r = order.size();
        while(l < r){
            int mid = l + r >> 1;
            if(order[mid][0] == num)
                return order[mid][2];
            else if(order[mid][0] > num)
                r = mid;
            else l = mid + 1;
        }
        return order[l][2];
    }
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        auto order = intervals;
        for(int i = 0; i < order.size(); i++)
            order[i].push_back(i);
        sort(order.begin(), order.end());
        
        vector<int> ans;
        for(auto& interval : intervals){
            if(interval[1] > order.back()[0])
                ans.push_back(-1);
            else ans.push_back(binary_search(order, interval[1]));
        }
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "intervals = ";
        cin >> s;
        auto intervals = parse(s);

        print(solution.findRightInterval(intervals));
    }
    
    return 0;
}