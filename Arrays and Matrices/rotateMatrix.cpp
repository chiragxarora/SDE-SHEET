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

// https://leetcode.com/problems/rotate-image

void rotate(vector<vector<int>>& matrix) {
    // take transpose
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<=i;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    // now swap columns
    for(int i=0;i<matrix.size();i++){
        for(int j=0,k=matrix[0].size()-1;j<=k;j++,k--){
            swap(matrix[i][j],matrix[i][k]);
        }
    }
}

int main() {
    vector<vector<int>> v {{1,2,3},{4,5,6},{7,8,9}};
    rotate(v);
    for(auto vi : v){
        for(auto p : vi) cout<<p<<" ";
        cout<<endl;
    }
    return 0;
}