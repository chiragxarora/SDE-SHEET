#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/permutations/

vector<vector<int>> ans;

void fn1(vector<int>& nums, vector<int>& res, unordered_set<int>& s) {
    if(res.size()==nums.size()){
        ans.push_back(res);
        return;
    }
    for(int i=0;i<nums.size();i++){
        if(s.find(i)==s.end()){
            s.insert(i);
            res.push_back(nums[i]);
            fn1(nums,res,s);
            res.pop_back();
            s.erase(i);
        }
    }
}

void fn2(vector<int>& nums, int idx){
    if(idx==nums.size()){
        ans.push_back(nums);
        return;
    }
    for(int i=idx;i<nums.size();i++){
        swap(nums[idx],nums[i]);
        fn2(nums,idx+1);
        swap(nums[idx],nums[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}