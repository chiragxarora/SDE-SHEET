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

// https://leetcode.com/problems/two-sum/

void twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> map;
    for(int i=0;i<nums.size();i++){
        map[nums[i]] = i;
    }
    for(int i=0;i<nums.size();i++){
        if(map.find(target-nums[i])!=map.end()&&map[target-nums[i]]!=i){
            cout<<i<<" "<<map[target-nums[i]]<<endl;
            break;
        }
    }
}

int main() {
    vector<int> v {1,3,7,2,77};
    twoSum(v,9);
    return 0;
}