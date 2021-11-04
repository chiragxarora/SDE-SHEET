#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/combination-sum-ii/

vector<vector<int>> ans;

void combination(vector<int>& nums, int idx, int sum, int target, vector<int>& res) {
    if(sum == target) {
        ans.push_back(res);
        return;
    }
    if(sum>target || idx==nums.size()){
        return;
    }
    int last = -1;
    for(int i = idx;i<nums.size();i++){
        if(nums[i]!=last){
            last = nums[i];
            res.push_back(nums[i]);
            combination(nums,i+1,sum+nums[i],target,res);
            res.pop_back();  
        }  
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> arr = {10,1,2,7,6,1,5};
    sort(arr.begin(),arr.end());
    int target = 8;
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