#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/max-consecutive-ones/

int approach1(vector<int>& nums){
    int cnt = 0, ans = 0;
    for(auto n : nums){
        if(n==1){
            cnt++;
            ans = max(ans,cnt);
        }
        else {
            cnt = 0;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v {1,1,0,1,1,1};
    cout<<approach1(v);
    return 0;
}