#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/search-in-rotated-sorted-array/

int bs(vector<int> &arr, int lo, int hi, int target){
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(arr[mid]==target) return mid;
        else if(arr[mid]<target) lo = mid+1;
        else hi = mid-1;
    }
    return -1;
}

int search(vector<int>& arr, int target) {
    int lo = 0, hi = arr.size()-1;
    while(lo<=hi){
        if(lo==hi){
            if(arr[lo]==target) return lo;
            else return -1;
        }
        int mid = (lo+hi)/2;
        // check if left is sorted or not
        if(arr[lo]<=arr[mid]){
            if(arr[lo]<=target&&target<=arr[mid]) return bs(arr,lo,mid,target);
            else lo = mid+1;
        }
        else {
            if(arr[mid+1]<=target&&target<=arr[hi]) return bs(arr,mid+1,hi,target);
            else hi = mid;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}