#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, maxArea = 0;

        while (left < right)
            maxArea = max(maxArea, (right - left) * (height[left] < height[right] ? height[left++] : height[right--]));

        return maxArea;
    }
};

vector<int> parse_input(string input) {
    vector<int> nums;
    input.erase(input.length() - 1, 1);
    input.erase(0, 1);

    if(input.length() == 0) return nums;

    int index = 0;
    for(int i = 0; i <= input.length(); i++) 
        if(input[i] == ',' || i == input.length()) {
            nums.push_back(stoi(input.substr(index, i - index)));
            index = i + 1;
        }

    return nums;
}

int main()
{
    Solution solution;

    while(true) {
        string input;
        cout << "height = ";
        cin >> input;
        vector<int> height = parse_input(input);
        cout << solution.maxArea(height) << endl;
    }
    
    return 0;
}
