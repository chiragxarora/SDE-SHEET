#include <bits/stdc++.h>
using namespace std;

// https://www.interviewbit.com/problems/allocate-books/

bool isPossible(vector<int>& arr, int limit, int students){
    int read = 0, sn = 1;
    for(int i=0;i<arr.size();i++){
        if(read+arr[i]<=limit){
            read+=arr[i];
        }
        else {
            read = arr[i];
            sn++;
        }
    }
    if(sn<=students) return true;
    else return false;
}

int books(vector<int> &arr, int s) {
    if(s>arr.size()) return -1;
    int lo = INT_MIN, hi = 0;
    for(auto a : arr){
        hi += a;
        lo = max(lo,a);
    }
    int ans = -1;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(isPossible(arr,mid,s)){
            ans = mid;
            hi = mid-1;
        }
        else {
            lo = mid+1;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}