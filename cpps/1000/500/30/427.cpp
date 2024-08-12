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

vector<vector<int>> parse(string s){
    vector<vector<int>> v;
    int last;
    for(int i = 1; i < s.length() - 1; i++)
        if(s[i] == '[') last = i;
        else if(s[i] == ']') v.push_back(parse_(s.substr(last, i - last + 1)));
    return v;
}

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
    Node* recursion(vector<vector<int>>& grid, int y, int x, int size){
        if(size == 1)
            return new Node(grid[y][x], true);

        size >>= 1;
        Node* ans = new Node();
        ans->topLeft = recursion(grid, y, x, size);
        ans->bottomLeft = recursion(grid, y + size, x, size);
        ans->topRight = recursion(grid, y, x + size, size);
        ans->bottomRight = recursion(grid, y + size, x + size, size);

        if(!ans->topLeft->isLeaf || !ans->bottomLeft->isLeaf 
        || !ans->topRight->isLeaf || !ans->bottomRight->isLeaf 
        || grid[y][x] != grid[y + size][x] 
        || grid[y][x] != grid[y][x + size]
        || grid[y][x] != grid[y + size][x + size])
            return ans;
        return new Node(grid[y][x], true);
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        return recursion(grid, 0, 0, grid.size());
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "grid = ";
        cin >> s;
        auto grid = parse(s);

        auto ans = solution.construct(grid);
        cout << "test" << endl;
    }
    
    return 0;
}