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

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0, size = heights.size(), ptr = -1, h, w;
        vector<int> last(size);

        for(int i = 0; i < size; i++){
            while(ptr >= 0 && heights[i] < (h = heights[last[ptr]])){
                w = i - (ptr-- ? last[ptr] + 1 : 0);
                ans = max(ans, w * h);
            }
            last[++ptr] = i;
        }

        while(ptr >= 0 && 0 < (h = heights[last[ptr]])){
            w = size - (ptr-- ? last[ptr] + 1 : 0);
            ans = max(ans, w * h);
        }
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "heights = ";
        cin >> s;
        auto heights = parse(s);

        cout << solution.largestRectangleArea(heights) << endl;       
    }
    
    return 0;
}