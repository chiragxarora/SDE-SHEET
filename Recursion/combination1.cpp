#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/combination-sum/

vector<vector<int>> ans;

void combination(vector<int>& nums, int idx, int sum, int target, vector<int>& temp) {
    if(sum == target) {
        ans.push_back(temp);
        return;
    }
    if(sum>target || idx==nums.size()){
        return;
    }
    temp.push_back(nums[idx]);
    combination(nums,idx,sum+nums[idx],target,temp);
    temp.pop_back();
    combination(nums,idx+1,sum,target,temp);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> arr = {2,3,6,7};
    int target = 7;
    vector<int> res;
    combination(arr,0,0,target,res);
    for(auto ai : ans) {
        for(auto a : ai){
            cout<<a<<" ";
        }
        cout<<"\n";
    }
    return 0;
}