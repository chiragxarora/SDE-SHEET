#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

void approach1(vector<int> v) {
    set<int> s;
    for(auto vi : v){
        if(s.find(vi)==s.end()){
            s.insert(vi);
        }
    }
    int i = 0;
    for(auto si : s){
        v[i] = si;
        i++;
    }
    for(int i=0;i<s.size();i++) cout<<v[i]<<" ";
}

void approach2(vector<int> v) {
    int i = 0, j = 1;
    for(j;j<v.size();j++){
        if(v[i]!=v[j]){
            i++;
            v[i] = v[j];
        }
    }
    for(int k=0;k<=i;k++) cout<<v[k]<<" ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v {0,0,1,1,1,2,2,3,3,3,4,5};
    approach1(v);
    //cout<<endl;
    approach2(v);
    return 0;
}