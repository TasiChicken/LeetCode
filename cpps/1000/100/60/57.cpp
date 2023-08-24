#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    int search(vector<vector<int>>& intervals, int time, int left, int right){
        if(left >= right) return left;
        int center = (left + right) / 2;
        if(intervals[center][1] < time) return search(intervals, time, center + 1, right);
        if(intervals[center][0] > time) return search(intervals, time, left, center - 1);
        return center;
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int last = intervals.size() - 1;
        if(last == -1) {
            intervals.push_back(newInterval);
            return intervals;
        }

        int begin = search(intervals, newInterval[0], 0, last), end = search(intervals, newInterval[1], begin, last);
        if(begin == end){
            if(newInterval[0] > intervals[end][1]) intervals.insert(intervals.begin() + end + 1, newInterval);
            else if(newInterval[1] < intervals[end][0]) intervals.insert(intervals.begin() + end, newInterval);
            else intervals[end][0] = min(intervals[end][0], newInterval[0]), intervals[end][1] = max(intervals[end][1], newInterval[1]);
        }
        else{
            if(newInterval[0] > intervals[begin][1]) begin++;
            if(newInterval[1] < intervals[end][0]) end--;
            intervals[begin][0] = min(intervals[begin][0], newInterval[0]), intervals[begin][1] = max(intervals[end][1], newInterval[1]);
            intervals.erase(intervals.begin() + begin + 1, intervals.begin() + end + 1);
        }

        return intervals;
    }
/* Worse Solution (Use the same idea with last problem [56. Merge Intervals])
    int search(vector<vector<int>>& intervals, int time, int left, int right){
        if(left >= right) return left;
        int center = (left + right) / 2;
        if(intervals[center][0] < time) return search(intervals, time, center + 1, right);
        if(intervals[center][0] > time) return search(intervals, time, left, center - 1);
        return center;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++)
            if(intervals[i][0] <= ans.back()[1]) ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            else ans.push_back(intervals[i]);
        return ans;
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int last = intervals.size() - 1;
        if(last == -1) {
            intervals.push_back(newInterval);
            return intervals;
        }
        int index = search(intervals, newInterval[0], 0, intervals.size() - 1);
        if(index <= last && intervals[index][0] < newInterval[0]) index++;
        intervals.insert(intervals.begin() + index, newInterval);
        return merge(intervals);
    }
*/
};

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

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "intervals = ";
        cin >> s;
        auto intervals = parse(s);
        cout << "newInterval = ";
        cin >> s;
        auto newInterval = parse_(s);

        print(solution.insert(intervals, newInterval));
    }
    
    return 0;
}