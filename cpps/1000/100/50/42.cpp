#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        const int size = height.size();

        int ans = 0;
        for(int i = 0; i < size - 2; i++){
            int h = height[i + 1];
            if(height[i] <= h) continue;

            for(int j = i + 2; j < size; j++)
                if (height[j] >= height[i]) {
                    ans += (height[i] - h) * (j - i - 1);
                    break;
                }
                else if (height[j] > h){
                    ans += (height[j] - h) * (j - i - 1);
                    h = height[j];
                }
        }

        return ans;
    }
/* Optimized Solution
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1, point;

        int ans = 0;
        while(left < right)
            if(height[left] < height[right]) {
                point = left + 1;
                while (height[point] <= height[left])
                    ans += height[left] - height[point++];
                left = point;
            }
            else {
                point = right - 1;
                while (left < point && height[point] <= height[right])
                    ans += height[right] - height[point--];
                right = point;
            }

        return ans;
    }
*/
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

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "height = ";
        cin >> s;
        vector<int> height = parse(s);

        cout << solution.trap(height) << endl;
    }
    
    return 0;
}