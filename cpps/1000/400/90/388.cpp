#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        vector<pair<int, int>> dict(1, {0, 0});
        for(int i = 0; i < input.size(); i++){
            int layer = 0, name = 0, dot = false;
            while(input[i] == '\t')
                layer++, i++;

            while(dict.size() > layer + 1){
                auto back = dict.back();
                dict.pop_back();
                if(back.second)
                    dict.back().second = max(dict.back().second, back.first + 1 + back.second);
                    // + 1 for dir '/' sub
            }

            while(i < input.size() && input[i] != '\n')
                name++, i++, dot = dot || input[i] == '.';

            if(dot) dict.back().second = max(dict.back().second, name);
            else dict.push_back({name, 0});

            cout << endl;
        }

        while(dict.size() > 1){
            auto back = dict.back();
            dict.pop_back();
            if(back.second)
                dict.back().second = max(dict.back().second, back.first + 1 + back.second);
        }

        return dict[0].second;
    }
};