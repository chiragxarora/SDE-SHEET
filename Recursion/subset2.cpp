#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/subsets-ii/

vector<vector<int>> ans;

void subsets(vector<int>& arr, int idx, vector<int>& res) {
    if(idx==arr.size()){
        return;
    }
    int last = -11;
    for(int i=idx;i<arr.size();i++){
        if(arr[i]!=last){
            res.push_back(arr[i]);
            ans.push_back(res);
            subsets(arr,i+1,res);
            res.pop_back();
            last = arr[i];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v {1,2,2};
    vector<int> res;
    subsets(v,0,res);
    for(auto ai : ans) {
        for(auto a : ai){
            cout<<a<<" ";
        }
        cout<<"\n";
    }
    return 0;
}