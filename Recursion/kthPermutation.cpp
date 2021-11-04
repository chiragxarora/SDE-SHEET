#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/permutation-sequence/

int num;
int fact[10];
unordered_set<int> s;
string ans = "";

void fn(int n, int k){
    vector<int> res(n);
    int j = 0;
    for(int i=1;i<=num;i++){
        if(s.find(i)==s.end()) res[j++] = i;
    }
    if(n==1){
        ans += to_string(res[0]);
        return;
    }
    int gsize = fact[n-1], pos = (k-1)/gsize, skips = (k-1)/gsize;
    ans += to_string(res[pos]);
    s.insert(res[pos]);
    fn(n-1,k-(skips*gsize));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fact[0] = 1;
    fact[1] = 1;
    for(int i=2;i<10;i++){
        fact[i] = fact[i-1]*i;
    }
    num = 4;
    fn(4,13);
    for(auto a : ans) cout<<a<<" ";
    return 0;
}