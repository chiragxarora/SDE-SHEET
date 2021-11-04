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

// Maximum Subarray Sum : https://leetcode.com/problems/maximum-subarray/

int kadane(vector<int> v) {
    int sum = 0, maxi = v[0], xi = 0, xj = 0, lastReset = 0;
    for(int i=0;i<v.size();i++){
        sum += v[i];
        if(sum > maxi) {
            xj = i;
            xi = lastReset;
            maxi = sum;
        }
        if(sum < 0){
            lastReset = i+1;
            sum = 0;
        }
    }
    cout<<xi<<" "<<xj<<endl;
    return maxi;
}

int main() {
    vector<int> v {-10,-10,-1};
    cout<<kadane(v);
    return 0;
}