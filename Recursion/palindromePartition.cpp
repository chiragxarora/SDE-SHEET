#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/palindrome-partitioning

vector<vector<string>> ans;

bool isPalindrome(string& s) {
    for(int i=0,j=s.length()-1;i<=j;i++,j--){
        if(s[i]!=s[j]) {
            return false;
        }
    }
    return true;
}

void pp(string str, vector<string>& res) {
    if(str.length()==0) {
        ans.push_back(res);
        return;
    }
    for(int i=0;i<str.length();i++){
        string s = str.substr(0,i+1);
        if(isPalindrome(s)) {
            res.push_back(s);
            pp(str.substr(i+1),res);
            res.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str = "aabb";
    vector<string> temp;
    pp(str,temp);
    for(auto ai : ans) {
        for(auto a : ai){
            cout<<a<<" ";
        }
        cout<<"\n";
    }
    return 0;
}