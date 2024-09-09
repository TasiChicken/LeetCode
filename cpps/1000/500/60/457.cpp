#include <iostream>
#include <vector>

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
    #define next_idx(i) ((((i) + nums[i]) % n + n) % n)
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(next_idx(i) == i) nums[i] = 0;
            if(!nums[i]) continue;

            int pos = nums[i] > 0, slow = next_idx(i), fast = next_idx(next_idx(i));
            while(nums[slow] && !(nums[slow] > 0 ^ pos)){
                if(slow == fast) {
                    do
                        slow = next_idx(slow);
                    while(slow != fast && nums[slow] && !(nums[slow] > 0 ^ pos));
                    if(slow != fast || next_idx(slow) == fast) break;
                    return true;
                }
                slow = next_idx(slow);
                fast = next_idx(next_idx(fast));
            }
            
            slow = i;
            while(nums[slow] && !(nums[slow] > 0 ^ pos)){
                fast = next_idx(slow);
                nums[slow] = 0;
                slow = fast;
            }
        }
        return false;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "nums = ";
        cin >> s;
        auto nums = parse_(s);

        cout << solution.circularArrayLoop(nums) << endl;
    }
    
    return 0;
}