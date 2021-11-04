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

// https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum

int approach2(vector<int>& a){
    unordered_map<int,int> map;
    map[a[0]] = 0;
    int ans = 0;
    for(int i=1;i<a.size();i++){
        a[i] += a[i-1];
        if(a[i]==0) ans = max(ans,i+1);
        if(map.find(a[i])==map.end()){
            map[a[i]] = i;
        }
        else {
            ans = max(ans,i-map[a[i]]);
        }
    }
    return ans;
}

int main() {
    vector<int> v {15,-2,2,-8,1,7,10,23};
    cout<<approach2(v);
    return 0;
}