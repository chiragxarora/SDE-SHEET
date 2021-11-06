#include <bits/stdc++.h>
using namespace std;

// Given two integers n and m, find nth real root of m

double multiply(double num, int n){
    double ans = 1.0;
    for(int i=1;i<=n;i++){
        ans *= num;
    }
    return ans;
}

double nthRoot(int n, double m){
    double lo = 1, hi = m, ans = 0;
    if(m < 1) swap(lo,hi);
    while((hi-lo)>1e-9){
        double mid = (lo + hi)/2.0;
        double mul = multiply(mid,n);
        if(mul==m){
            return mid;
        }
        else if(mul<m){
            ans = mid;
            lo = mid;
        }
        else {
            hi = mid;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<nthRoot(11,1372478474164);
    return 0;
}