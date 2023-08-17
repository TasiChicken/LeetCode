#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int wordLen = words[0].length(), wordsSize = words.size(), targetLen = wordLen * wordsSize;
        unordered_map<string, int> mp;
        for(int i = 0; i < wordsSize; i++) 
            mp[words[i]]++;

        int len = s.length();

        for(int i = 0; i < wordLen; i++){
            int left = i, right = i;
            while(left + targetLen <= len){
                auto it = mp.find(s.substr(right, wordLen));
                if(it == mp.end()){
                    left = right += wordLen;
                    continue;
                }

                string lost;
                while(it != mp.end() && it->second > 0){
                    it->second--;
                    right += wordLen;
                    if(right - left == targetLen)
                        ans.push_back(left);

                    it = mp.find(lost = s.substr(right, wordLen));
                }
                
                while(left < right){
                    string sub = s.substr(left, wordLen);
                    mp[sub]++;
                    left += wordLen;
                    
                    if(sub == lost) break;
                }
            }
        }

        return ans;
    }
};

vector<string> parse_input(string input) {
    vector<string> strs;
    input.erase(input.length() - 1, 1);
    input.erase(0, 1);

    if(input.length() == 0) return strs;

    int index = 0;
    for(int i = 0; i <= input.length(); i++) 
        if(input[i] == ',' || i == input.length()) {
            strs.push_back(input.substr(index + 1, i - index - 2));
            index = i + 1;
        }

    return strs;
}

string print_output(vector<int> output) {
    string output_string = "[";
    for(int i = 0; i < output.size(); i++) {
        output_string += to_string(output[i]);
        if(i != output.size() - 1)
            output_string += ",";
    }
    output_string += "]";

    return output_string;
}

int main()
{
    Solution solution;

    while(true) {
        string input, s;
        cout << "s = ";
        cin >> s;
        cout << "words = ";
        cin >> input;
        vector<string> words = parse_input(input);


        cout << print_output(solution.findSubstring(s, words)) << endl;
    }
    
    return 0;
}