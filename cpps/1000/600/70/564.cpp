#include <bits/stdc++.h>

using namespace std;

class Solution {
    string make_pal(string n){
        int len = n.size();
        for(int i = 0; i < len / 2; i++)
            n[len - 1 - i] = n [i];
        return n;
    }
    int compare(string a, string b){
        if(a.size() > b.size()) return 1;
        if(a.size() < b.size()) return -1;

        for(int i = 0; i < a.size(); i++){
            if(a[i] > b[i]) return 1;
            if(a[i] < b[i]) return -1;
        }

        return 0;
    }
    string plus(string a, string b){
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        bool carry = 0;
        string s = "";

        for(int i = 0; carry || i < max(a.size(), b.size()); i++){
            s.push_back('0');
            if(i < a.size()) s.back() += a[i] - '0';
            if(i < b.size()) s.back() += b[i] - '0';
            if(carry) s.back() += 1;

            carry = s.back() > '9';
            if(carry) s.back() -= 10;
        }

        reverse(s.begin(), s.end());
        return s;
    }
    // a must be > b
    string sub(string a, string b){
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        bool borrow = 0;
        for(int i = 0; i < a.size(); i++){
            if(i < b.size()) a[i] -= b[i] - '0';
            else if(!borrow) break;

            a[i] -= borrow;

            borrow = a[i] < '0';
            if(borrow) a[i] += 10;
        }

        while(a.back() == '0' && a.size() > 1) 
            a.pop_back();

        reverse(a.begin(), a.end());

        return a;
    }
    string abs_diff(string a, string b){
        int c = compare(a, b);

        if(c == 0) return "0";
        if(c == -1) return sub(b, a);
        return sub(a, b);

    }
public:
    string nearestPalindromic(string n) {
        int len = n.size();

        string offset = "1";
        for(int i = 0; i < len / 2; i++)
            offset += "0";

        string s = sub(n, offset);
        for(int i = 0; i < len / 2; i++)
            s[s.size() - i - 1] = '9';
        string ans = make_pal(s);
        string d = abs_diff(n, ans);

        bool is_pa = true;
        for(int i = 0; i < len / 2; i++)
            if(n[i] != n[len - 1 - i]){
                string ans_temp = make_pal(n);
                string d_temp = abs_diff(n, ans_temp);

                int com = compare(d_temp, d);
                if(com < 0) ans = ans_temp, d = d_temp;

                break;
            }

        s = plus(n, offset);
        for(int i = 0; i < len / 2; i++)
            s[s.size() - i - 1] = '0';
        string ans_temp = make_pal(s);
        string d_temp = abs_diff(n, ans_temp);

        int com = compare(d_temp, d);
        if(com < 0) ans = ans_temp, d = d_temp;

        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string n;
        cin >> n;

        cout << solution.nearestPalindromic(n) << endl;
    }
    
    return 0;
}