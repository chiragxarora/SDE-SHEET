#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <utility>
#include <iomanip>

using namespace std;

// https://leetcode.com/problems/next-permutation/

void approach2(vector<int>& nums){
    int firstDecreaseFromRight = -1;
    for(int i=nums.size()-1;i>=1;i--){
        if(nums[i]>nums[i-1]){
            firstDecreaseFromRight = i-1;
            break;
        }
    }
    if(firstDecreaseFromRight==-1){
        reverse(nums.begin(),nums.end());
        return;
    }
    int nextJustGreaterIdx = 0, nextJustGreaterVal = INT_MAX;
    for(int i=firstDecreaseFromRight+1;i<nums.size();i++){
        if(nums[i]>nums[firstDecreaseFromRight]){
            if(nums[i]<nextJustGreaterVal){
                nextJustGreaterVal = nums[i];
                nextJustGreaterIdx = i;
            }
        }
    }
    swap(nums[firstDecreaseFromRight],nums[nextJustGreaterIdx]);
    sort(nums.begin()+firstDecreaseFromRight+1,nums.end());
}

int main() {
    vector<int> v {1,1,5};
    approach2(v);
    for(auto vi : v) cout<<vi<<" ";
    return 0;
}