#include <bits/stdc++.h>

using namespace std;

class Solution {
    const string deck = "RYBGW";
public:
    int findMinStep(string board, string hand) {
        string h = "00000";
        for(char c : hand)
            h[deck.find(c)]++;
        unordered_map<string, int> dp;
        return dfs(dp, board, h);
    }
    int dfs(unordered_map<string, int>& dp, string board, string& hand){
        if(board.empty()) return 0;
        if(hand.empty()) return -1;

        string key = board + "_" + hand;
        if(dp.find(key) != dp.end()) return dp[key];

        int ans = -1;
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < hand.size(); j++)
                if(hand[j] != '0'){
                    if(!(i > 0 && i < board.size() && board[i - 1] == board[i]) && 
                    !(i > 0 && board[i - 1] == deck[j] || i < board.size() && board[i] == deck[j])) continue;

                    hand[j]--;
                    
                    auto next_b = board;
                    next_b.insert(i, deck.substr(j, 1));
                    remove(next_b, i);
                    
                    int temp = dfs(dp, next_b, hand);
                    hand[j]++;

                    if(temp++ == -1) continue;

                    if(ans == -1) ans = temp;
                    else ans = min(ans, temp);
                }

        return dp[key] = ans;
    }
    void remove(string& s, int pos){
        int l = pos, r = pos;
        while(l > 0 && s[l - 1] == s[pos]) l--;
        while(r < s.size() - 1 && s[r + 1] == s[pos]) r++;
        if(r - l >= 2) s.erase(l, r - l + 1);
        else return;
        remove(s, l);
    }
};

int main() {
    while(true) {
        Solution solution;
        string board, hand;
        cout << "board = ";
        cin >> board;
        board = board.substr(1, board.size() - 2);
        cout << "hand = ";
        cin >> hand;
        hand = hand.substr(1, hand.size() - 2);

        cout << solution.findMinStep(board, hand) << endl;
    }
    
    return 0;
}