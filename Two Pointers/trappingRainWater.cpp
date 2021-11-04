#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/trapping-rain-water/

int approach1(vector<int>& v) {
    vector<int> lmax(v.size()), rmax(v.size());
    lmax[0] = v[0], rmax[v.size()-1] = v[v.size()-1];
    for(int i=1;i<v.size();i++){
        lmax[i] = max(lmax[i-1],v[i]);
    }
    for(int i=v.size()-2;i>=0;i--){
        rmax[i] = max(rmax[i+1],v[i]);
    }
    int ans = 0;
    for(int i=1;i<v.size()-1;i++){
        int val = min(lmax[i],rmax[i]) - v[i];
        ans += val;
    }
    return ans;
}

int approach2(vector<int>& v){
    int ans = 0;
    int left = 0, right = v.size()-1, lmax = 0, rmax = 0;
    while(left<=right) {
        rmax = max(rmax,v[right]);
        if(v[left]<=v[right]){
            if(v[left]>=lmax){
                lmax = max(lmax,v[left]);
            } 
            else {
                ans += lmax-v[left];    
            }
            left++;
        }
        else {
            if(v[right]>=rmax){
                rmax = max(rmax,v[right]);
            } 
            else {
                ans += rmax-v[right];
            }
            right--;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v {4,2,0,3,2,5};
    cout<<approach1(v)<<endl;
    return 0;
}