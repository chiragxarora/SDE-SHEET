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

// https://leetcode.com/problems/reverse-pairs

int merge(vector<int>& nums, int i, int j){
    int tmp[j-i+1];
    int mid = (i+j)/2;
    int i1 = i, i2 = mid+1, k = 0;
    int cnt = 0;
    while(i1<=mid&&i2<=j){
        if(nums[i1]>(long long)2*nums[i2]){
            cnt += mid-i1+1;
            i2++;
        }
        else {
            i1++;
        }
    }
    i1 = i;
    i2 = mid+1;
    k = 0;
    while(i1<=mid&&i2<=j){
        if(nums[i1]>nums[i2]){
            tmp[k++] = nums[i2++];
        }
        else {
            tmp[k++] = nums[i1++];
        }
    }
    while(i1<=mid){
        tmp[k++] = nums[i1++];
    }
    while(i2<=j){
        tmp[k++] = nums[i2++];
    }
    int p = 0;
    for(int x=i;x<=j;x++){
        nums[x] = tmp[p];
        p++;
    }
    return cnt;
}

int ms(vector<int>& nums, int i, int j){
    if(i>=j) return 0;
    int mid = (i+j)/2;
    int left = ms(nums,i,mid);
    int right = ms(nums,mid+1,j);
    int cross = merge(nums,i,j);
    return left+right+cross;
}

int main() {
    vector<int> nums {2,4,3,5,1};
    cout<<ms(nums,0,nums.size()-1);
    return 0;
}