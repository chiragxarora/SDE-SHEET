#include <bits/stdc++.h>
using namespace std;

int kthElement(int ar1[], int ar2[], int n, int m, int k)
    {
        if(n>m){
            return kthElement(ar2,ar1,m,n,k);
        }
        int lo = max(0,k-m), hi = min(k,n);
        while(lo<=hi){
            int mid  = (lo+hi)/2;
            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
            if(mid-1>=0) l1 = ar1[mid-1];
            if(mid<n) r1 = ar1[mid];
            if(k-mid-1>=0) l2 = ar2[k-mid-1];
            if(k-mid<m) r2 = ar2[k-mid];
            if(l1<=r2&&l2<=r1) return max(l1,l2);
            else if(l1>r2) hi = mid-1;
            else lo = mid+1;
        }
        return 0;
    }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}