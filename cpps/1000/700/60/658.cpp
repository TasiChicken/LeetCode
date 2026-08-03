#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //find closest element to x
        int l = k - 1, r = arr.size() - 1;
        while(l < r){
            int mid = l + r >> 1;
            if(arr[mid] == x){
                l = r = mid;
                break;
            }

            if(arr[mid] > x) r = mid - 1;
            else l = mid + 1;
        }

        if(arr[l] != x){
            if(l + 1 < arr.size() && abs(arr[l + 1] - x) < abs(arr[l] - x))
                l = r = l + 1;
            else if(l > 0 && abs(arr[l - 1] - x) <= abs(arr[l] - x))
                l = r = l - 1;
        }

        l = max(k - 1, l), r = min(l + k - 1, (int)arr.size() - 1);
        while(l < r){
            int mid = l + r >> 1;
            if(abs(arr[mid + 1] - x) < abs(arr[mid - k + 1] - x))
                l = mid + 1;
            else r = mid;
        }

        return vector<int>(arr.begin() + (l - k + 1), arr.begin() + (l + 1));
    }
};

vector<int> parse_(string s){
    vector<int> v;
    int last = 1;
    for(int i = 2; i < s.length(); i++)
        if(s[i] == ',' || s[i] == ']') {
            v.push_back(stoi(s.substr(last, i - last)));
            last = i + 1;
        }
    return v;
}

void print(vector<int> v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        cout << v[i];
        if(i != v.size() - 1) cout << ",";
    }
    cout << "]";
    cout << endl;
}

int main() {
    while(true) {
        Solution solution;
        string s;
        cin >> s;
        auto arr = parse_(s);
        int k, x;
        cin >> k >> x;


        print(solution.findClosestElements(arr, k, x));
    }
    
    return 0;
}