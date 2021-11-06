#include <bits/stdc++.h>
using namespace std;

// https://www.interviewbit.com/problems/matrix-median/

int lessOrEqual(vector<vector<int> > &arr, int num){
    int ans = 0, r = arr.size(), c = arr[0].size();
    for(int i=0;i<r;i++){
        int lo = 0, hi = c-1, val = 0;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(arr[i][mid] <=num){
                val = mid+1;
                lo = mid+1;
            }
            else {
                hi = mid-1;
            }
        }
        ans += val;
    }
    return ans;
}

int findMedian(vector<vector<int>> &arr) {
    int r = arr.size(), c = arr[0].size();
    int lo = 1, hi = 1e9;
    int target = ((r*c)/2) + 1;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        int loe = lessOrEqual(arr,mid);
        if(loe>=target){
            hi = mid-1;
        }
        else {
            lo = mid+1;
        }
    }
    return lo;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}