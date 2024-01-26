#include <iostream>

using namespace std;

class Solution {
    string ones[19] = {" One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine", " Ten", " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen"};
    string tens[8] = {" Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy", " Eighty", " Ninety"};
    string thousands[3] = {" Thousand", " Million", " Billion"};

    string part(int num, int i){
        if(!num) return "";

        string s = "";
        if(num >= 100) s += ones[num / 100 - 1] + " Hundred", num %= 100;
        if(num >= 20) s += tens[num / 10 - 2], num %= 10;
        if(num) s += ones[num - 1];
        if(i) s += thousands[i - 1];
        
        return s;
    }
public:
    string numberToWords(int num) {
        if(!num) return "Zero";

        string ans = "";
        
        int i = 0;
        while(num) ans = part(num % 1000, i++) + ans, num /= 1000;

        return ans.substr(1);
    }
};

int main() {
    while(true) {
        Solution solution;
        int num;
        cout << "num = ";
        cin >> num;
        cout << solution.numberToWords(num) << endl;
    }
    
    return 0;
}