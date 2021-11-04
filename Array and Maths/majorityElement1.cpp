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

// https://leetcode.com/problems/majority-element/

int approach1(vector<int>& nums) {
    unordered_map<int,int> map;
    for(int i=0;i<nums.size();i++){
        map[nums[i]] += 1;
    }
    
    for(auto m : map){
        if(m.second>nums.size()/2){
            return m.first;
        }
    }
    return -1;
}

int approach2(vector<int>& nums) {
    int cnt = 0, el = 0;
    for(int i=0;i<nums.size();i++){
        if(cnt==0){
            el = nums[i];
        }
        if(nums[i]==el){
            cnt++;
        }
        else {
            cnt--;
        }
    }
    return el;
}

int main() {
    vector<int> v {7,5,7,5,1,5,7,5,5,7,7,5,5,5,5};
    cout<<approach1(v)<<endl;
    cout<<approach2(v)<<endl;
    return 0;
}