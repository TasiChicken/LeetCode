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
public:
    bool isSelfCrossing(vector<int>& distance) {
        for(int i = 3; i < distance.size(); i++)
            if(distance[i - 1] <= distance[i - 3]
                && (distance[i] >= distance[i - 2]
                || i == 4 && distance[i - 1] == distance[i - 3]
                && distance[i] + distance[i - 4] >= distance[i - 2]
                || i > 4 && distance[i - 2] > distance[i - 4] 
                && distance[i - 1] >= distance[i - 3] - distance[i - 5] 
                && distance[i] >= distance[i - 2] - distance[i - 4]))
                return true;
        return false;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "distance = ";
        cin >> s;
        auto distance = parse_(s);

        cout << solution.isSelfCrossing(distance) << endl;
    }
    
    return 0;
}