#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/single-element-in-a-sorted-array/

int singleNonDuplicate(vector<int>& arr) {
    int lo = 0, hi = arr.size()-1;
    while(lo<=hi){
        if(lo==hi) return arr[lo];
        int mid = (lo+hi)/2;
        if(arr[mid]!=arr[mid-1]&&arr[mid]!=arr[mid+1]){
            return arr[mid];
        }
        int pairEnds, left, right;
        if(arr[mid]==arr[mid-1]) pairEnds = mid;
        else pairEnds = mid+1;
        left = pairEnds - lo+1; right = hi - pairEnds;
        if(left%2==1){
            hi = pairEnds-2;
        }
        else if(right%2==1){
            lo = pairEnds+1;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}