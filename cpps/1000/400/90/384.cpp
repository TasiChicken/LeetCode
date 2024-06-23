#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<int> nums, deck;
public:
    Solution(vector<int>& nums) {
        this->nums = deck = nums;
    }
    
    vector<int> reset() {
        return nums;
    }
    
    vector<int> shuffle() {
        int s = deck.size();
        for(int i = 0; i < s; i++)
            swap(deck[rand() % s], deck[rand() % s]);
        return deck;
    }
};