#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        len1 = nums1.size();
        len2 = nums2.size();
        len = len1 + len2;
        boundCount = (len - 1) / 2;
        found = false;

        nums1Left = nums2Left = 0;
        nums1Right = len1 - 1;
        nums2Right = len2 - 1;
        
        int counter = 0;
        while(!found){
            if(counter-- == 0)
                binarySearch(nums1, nums2, nums1Left, nums1Right);
            else if((counter = counter + 2) == 0)
                binarySearch(nums2, nums1, nums2Left, nums2Right);
        }

        return (leftAns + rightAns) / 2.0;
    }
private:
    int len1, len2, len;
    int boundCount;
    int leftAns, rightAns;
    int nums1Left, nums1Right, nums2Left, nums2Right;
    bool found;

    void binarySearch(vector<int>& main, vector<int>& branch, int& left, int& right){
        if(left > right) return;
        
        int index = (left + right) / 2;
        switch (median(main, branch, index))
        {
        case 0:
            found = true;

            leftAns = main[index];
            if(len % 2 == 0){
                int a = inRange(main, index + 1) ? main[index + 1] : INT_MAX;
                int b = inRange(branch, boundCount - index) ? branch[boundCount - index] : INT_MAX;
                rightAns = a < b ? a : b;
            }
            else rightAns = leftAns;

            break;
        case 1:
            left = index + 1;
            break;
        case -1:
            right = index - 1;
            break;
        };
    }

    int median(vector<int>& main, vector<int>& branch, int index){
        int num = main[index];
        int branchIndex = boundCount - index;
        int maxIndex = branch.size();

        if(branchIndex > maxIndex || branchIndex > 0 && branch[branchIndex - 1] > num) return 1;
        if(branchIndex < 0 || branchIndex < maxIndex && branch[branchIndex] < num) return -1;

        return 0;
    }

    bool inRange(vector<int>& nums, int index){
        return index >= 0 && index < nums.size();
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
        vector<int> nums1, nums2;

        cout << "nums1 = ";
        cin >> input;
        nums1 = parse_input(input);
        cout << "nums2 = ";
        cin >> input;
        nums2 = parse_input(input);

        cout << solution.findMedianSortedArrays(nums1, nums2) << endl;
    }
    return 0;
}
