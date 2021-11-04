#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/

int approach1(int arr[], int dep[], int n) {
    sort(arr,arr+n);
    sort(dep,dep+n);
    int start = 1, end = 0, plat = 1, mx = 1;
    while(start<n){
        if(arr[start]<=dep[end]){
            plat++;
            mx = max(mx,plat);
        }
        else {
            while(dep[end]<arr[start]){
                end++;
                plat--;
            }
            plat++;
        }
        start++;
    }
    return mx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}