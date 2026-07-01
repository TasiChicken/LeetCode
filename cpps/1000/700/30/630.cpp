#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const auto& a, const auto& b){
            return a[1] < b[1];
        });

        int time = 0;
        priority_queue<int> pq;
        for(const auto& c : courses){
            pq.push(c[0]);
            time += c[0];

            if(time <= c[1]) continue;

            time -= pq.top();
            pq.pop();
        }

        return pq.size();
    }
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

int main() {
    while(true) {
        Solution solution;
        string s;
        cin >> s;
        auto courses = parse(s);

        cout << solution.scheduleCourse(courses) << endl;
    }
    
    return 0;
}