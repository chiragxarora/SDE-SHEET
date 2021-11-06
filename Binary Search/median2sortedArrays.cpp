#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& ar1, vector<int>& ar2) {
    if(ar1.size()>ar2.size()){
        return findMedianSortedArrays(ar2,ar1);
    }
    int n = ar1.size(), m = ar2.size(), total = (n+m+1)/2;
    // total = number of elements in the left part
    int lo = 0, hi = n;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
        if(mid-1>=0) l1 = ar1[mid-1];
        if(mid<n) r1 = ar1[mid];
        // we need to pick (total-mid) elements from ar2
        if(total-mid-1>=0) l2 = ar2[total-mid-1];
        if(total-mid<m) r2 = ar2[total-mid];
        if(l1<=r2&&l2<=r1){
            if((n+m)%2==1){
                return max(l1,l2);
            }
            else {
                return (max(l1,l2) + min(r1,r2))/2.0;
            }
        }
        else if(l1>r2){
            // move left in ar1
            hi = mid-1;
        }
        else {
            // move right in ar1
            lo = mid+1;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}