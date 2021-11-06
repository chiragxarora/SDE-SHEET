#include <bits/stdc++.h>
using namespace std;

// https://www.spoj.com/problems/AGGRCOW/

bool possible(vector<long long> barn, long long k, long long c){
    long long current = 1, lastPlaced = barn[0];
    for(long long i=1;i<barn.size();i++){
        if(barn[i]-lastPlaced >= k){
            current++;
            lastPlaced = barn[i];
        }
        if(current==c) return true;
    }
    return false;
}

int main() {
    long long t;
    cin>>t;
    while(t--){
        long long n,c;
        cin>>n>>c;
        vector<long long> barn(n);
        for(long long i=0;i<n;i++){
            cin>>barn[i];
        }
        sort(barn.begin(),barn.end());
        long long lo = 0, hi = barn[barn.size()-1] - barn[0], ans = 0;
        while(lo<=hi){
            long long mid = (lo+hi)/2;
            if(possible(barn,mid,c)){
                ans = mid;
                lo = mid+1;
            } else {
                hi = mid-1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}