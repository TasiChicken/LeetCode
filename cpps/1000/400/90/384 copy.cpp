#include <iostream>
#include <vector>

using namespace std;

class NestedInteger {
public:
    // Constructor initializes an empty nested list.
    NestedInteger();
    // Constructor initializes a single integer.
    NestedInteger(int value);
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);
    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class Solution {
    NestedInteger recursion(string& s, int& i) {
        cout << s[i];
        if(s[i] != '['){
            bool neg = s[i] == '-';
            int num = 0;
            i += neg;
            while(i < s.size() && s[i] >= '0' && s[i] <= '9')
                num = num * 10 + s[i++] - '0';
            return NestedInteger(neg ? -num : num);
        }

        NestedInteger ans;
        while(s[i] != ']' && s[++i] != ']')
            ans.add(recursion(s, i));
        ++i;
        return ans;
    }
public:
    NestedInteger deserialize(string s) {
        int i = 0;
        return recursion(s, i);
    }
};