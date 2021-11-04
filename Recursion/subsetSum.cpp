#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/subset-sums2234

void subsets(vector<int>& arr, int idx, int sum, vector<int>& ans){
    if(idx==arr.size()){
        ans.push_back(sum);
        return;
    }
    subsets(arr,idx+1,sum+arr[idx],ans);
    subsets(arr,idx+1,sum,ans);
}

vector<int> subsetSums(vector<int>& arr){
    vector<int> ans;
    subsets(arr,0,0,ans);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v {2,3,4,5};
    vector<int> ans = subsetSums(v);
    for(auto ai : ans) cout<<ai<<" ";
    return 0;
}