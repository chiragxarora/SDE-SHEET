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

// https://leetcode.com/problems/find-the-duplicate-number/

int approach1(vector<int>& nums) {
    int i = 0;
    while(i<nums.size()){
        if(nums[i]==i+1){
            i++;
        }
        else if(nums[i]==nums[nums[i]-1]){
            return nums[i];
        }
        else {
            swap(nums[i],nums[nums[i]-1]);
        }
    }
    return 1;
}

// Linked List cycle detection algorithm

int approach2(vector<int>& nums) {
    int fast = nums[0], slow = nums[0];
    while(1){
        slow = nums[slow];
        fast = nums[nums[fast]];
        if(fast==slow){
            break;
        }
    }
    fast = nums[0];
    while(fast!=slow){
        slow = nums[slow];
        fast = nums[fast];
    }
    return fast;
}

int main() {
    vector<int> v {1,4,2,7,4,3,5,6};
    cout<<approach1(v)<<endl;
    cout<<approach2(v)<<endl;
    return 0;
}