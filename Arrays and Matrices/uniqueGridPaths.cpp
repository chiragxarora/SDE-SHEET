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

// https://leetcode.com/problems/unique-paths/

int approach1(int m, int n) {
    vector<vector<int>> grid (m, vector<int> (n,0));
    for(int i=0;i<grid.size();i++){
        grid[i][grid[0].size()-1] = 1;
    }
    for(int i=0;i<grid[0].size();i++){
        grid[grid.size()-1][i] = 1;
    }
    int x = grid.size()-2, y = grid[0].size()-2;
    for(int i=x;i>=0;i--){
        for(int j=y;j>=0;j--){
            grid[i][j] = grid[i][j+1] + grid[i+1][j];
        }
    }
    return grid[0][0];
}

int approach2(int m, int n){
    int total = m+n-2;
    int pick = m-1;
    long long ans = 1;
    int k = m+n-2-pick;
    k = min(k,total-n+1);
    for(int i=1;i<=k;i++) {
        ans *= total;
        ans /= i;
        total--;
    }
    return ans;
}

int main() {
    cout<<approach1(3,7)<<endl;
    cout<<approach2(3,7)<<endl;
    return 0;
}