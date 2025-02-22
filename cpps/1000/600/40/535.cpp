#include <bits/stdc++.h>

using namespace std;

class Solution {
    const string domain = "https://tinyurl.com/";
    unordered_map<string, string> l2t, t2l;
    string i2base62(int num){
        if(num == 0) return "0";
        
        string ans;
        while(num){
            int temp = num % 62;
            num /= 62;
            
            if(temp < 10) ans.push_back('0' + temp);
            else if(temp < 36) ans.push_back('a' + temp - 10);
            else ans.push_back('A' + temp - 36);
        }

        return ans;
    }
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(l2t.find(longUrl) == l2t.end()) {
            string temp = i2base62(l2t.size());
            l2t[longUrl] = temp;
            t2l[temp] = longUrl;
        }
        return domain + l2t[longUrl];
    }
    
    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return t2l[shortUrl.substr(domain.size())];
    }
};