#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <utility>
#include <iomanip>

using namespace std;

// https://leetcode.com/problems/merge-intervals/

bool cmp(vector<int>& v1, vector<int>& v2) {
    return v1[0]<v2[0];
}

int main() {
    vector<vector<int>> iv = {{1,3},{2,6},{8,10},{15,18}};
    sort(iv.begin(),iv.end(),cmp);
    vector<vector<int>> ans;
    ans.push_back(iv[0]);
    int lastEnd = iv[0][1];
    for(int i=1;i<iv.size();i++){
        if(iv[i][0]<=lastEnd){
            ans[ans.size()-1][1] = max(ans[ans.size()-1][1],iv[i][1]);
            lastEnd = ans[ans.size()-1][1];
        } else {
            ans.push_back(iv[i]);
            lastEnd = iv[i][1];
        }
    }
    for(auto a : ans) cout<<a[0]<<" "<<a[1]<<endl;
    return 0;
}