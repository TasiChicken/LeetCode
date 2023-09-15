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
    void recursion(vector<int>& ratings, int i, int n, int& ans, int num){
        if(i != n - 1){
            int next = ratings[i + 1];
            recursion(ratings, i + 1, n, ans, 1 + (ratings[i] < next ? num : 0));
            if(ratings[i] > next && num <= ratings[i + 1]) num = ratings[i + 1] + 1;
        }

        ans += ratings[i] = num;
    }
public:
    int candy(vector<int>& ratings) {
        int ans = 0;
        recursion(ratings, 0, ratings.size(), ans, 1);
        return ans;
    }
/*Optimized Solution
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), ans = n, up = 0, peak = 0, down = 0;
        for(int i = 1; i < n; i++)
            if(ratings[i] == ratings[i - 1]) up = peak = down = 0;
            else if(ratings[i] > ratings[i - 1]) ans += peak = ++up, down = 0;
            else ans += down++ + (peak < down), up = 0;
        return ans;
    }
*/
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "ratings = ";
        cin >> s;
        auto ratings = parse(s);

        cout << solution.candy(ratings) << endl;
    }
    
    return 0;
}