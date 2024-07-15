#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void print(vector<string> v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        cout << '\"' << v[i] << '\"';
        if(i != v.size() - 1) cout << ",";
    }
    cout << "]";
    cout << endl;
}

class Solution {
    void recursion(vector<string>& ans, int time, int start, int turnedOn){
        if(!turnedOn){
            int mini = time & 0x3f;
            int hr = time >> 6;

            if(mini < 60 && hr < 12){
                stringstream sstream;
                sstream << hr << ':';
                if(mini < 10)
                    sstream << 0;
                sstream << mini;
                ans.push_back(sstream.str());
            }

            return;
        }

        for(int i = start; i + turnedOn <= 10; i++)
            recursion(ans, time + (1 << i), i + 1, turnedOn - 1);
    }
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        recursion(ans, 0, 0, turnedOn);
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        int turnedOn;
        cout << "turnedOn = ";
        cin >> turnedOn;

        print(solution.readBinaryWatch(turnedOn));
    }
    
    return 0;
}