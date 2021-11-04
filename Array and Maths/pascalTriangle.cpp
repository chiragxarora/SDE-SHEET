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

// https://leetcode.com/problems/pascals-triangle/

void pascal(int num) {
    vector<vector<int>> ans;
    vector<int> v {1};
    ans.push_back(v);
    for(int i=1;i<num;i++){
        vector<int> a(i+1);
        a[0] = 1;
        a[a.size()-1]=1;
        for(int j=1;j<a.size()-1;j++){
            a[j] = ans[i-1][j-1] + ans[i-1][j];
        }
        ans.push_back(a);
    }
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    pascal(5);
    return 0;
}