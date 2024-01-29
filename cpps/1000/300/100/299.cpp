#include <iostream>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int bucket[10] = { 0 };
        for(char d : secret) bucket[d - '0']++;

        int a = 0, b = 0;
        for(int i = 0; i < secret.size(); i++)
            if(guess[i] == secret[i]) a++, bucket[guess[i] - '0']--;
            else if(bucket[guess[i] - '0'] > 0) b++, bucket[guess[i] - '0']--;
        
        for(int d : bucket) if(d < 0) b += d;
        return to_string(a) + "A" + to_string(b) + "B";
    }
};

int main() {
    while(true) {
        Solution solution;
        string secret, guess;
        cout << "secret = ";
        cin >> secret;
        cout << "guess = ";
        cin >> guess;
        
        cout << solution.getHint(secret, guess) << endl;
    }
    
    return 0;
}