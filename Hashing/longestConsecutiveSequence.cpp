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

// https://leetcode.com/problems/longest-consecutive-sequence

int approach2(vector<int>& nums){
    if(nums.size()==0) return 0;
    unordered_set<int> set;
    for(auto i : nums){
        set.insert(i);
    }
    int ans = 1;
    for(int i=0;i<nums.size();i++){
        if(set.find(nums[i]-1)==set.end()){
            int nextNum = nums[i]+1;
            int currentLen = 1;
            while(set.find(nextNum)!=set.end()){
                //set.erase(nextNum); {why this line reduces time taken???}
                currentLen++;
                nextNum++;
            }
            ans = max(ans,currentLen);
        }
    }
    return ans;
}

int main() {
    vector<int> arr {100,4,200,1,3,2};
    cout<<approach2(arr)<<endl;
    return 0;
}