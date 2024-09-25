#include <iostream>

using namespace std;

class Solution {
    bool isIPv4(const string& s){
        int seg = 0, num = -1;
        for(int i = 0; i < s.size(); i++)
            if(s[i] == '.')
                if(num == -1 || ++seg >= 4) return false;
                else num = -1;
            else if(s[i] >= '0' && s[i] <= '9'){
                if(num == 0) return false;
                if(num == -1) num = 0;
                num = num * 10 + s[i] - '0';
                if(num > 255) return false;
            }
            else return false;
        return seg == 3 && num != -1;
    }
    bool isIPv6(const string& s){
        int seg = 0, num = 0;
        for(int i = 0; i < s.size(); i++)
            if(s[i] == ':')
                if(num == 0 || ++seg >= 8) return false;
                else num = 0;
            else if(s[i] >= '0' && s[i] <= '9' ||
                s[i] >= 'a' && s[i] <= 'f' ||
                s[i] >= 'A' && s[i] <= 'F'){
                    if(++num > 4) return false;
                }
            else return false;
        return seg == 7 && num > 0;
    }
public:
    string validIPAddress(string queryIP) {
        if(isIPv4(queryIP)) return "IPv4";
        if(isIPv6(queryIP)) return "IPv6";
        return "Neither";
    }
};

int main() {
    while(true) {
        Solution solution;
        string queryIP;
        cout << "queryIP = ";
        cin >> queryIP;
        queryIP = queryIP.substr(1, queryIP.size() - 2);

        cout << solution.validIPAddress(queryIP) << endl;
    }
    
    return 0;
}