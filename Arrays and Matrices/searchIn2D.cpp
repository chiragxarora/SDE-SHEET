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


// https://leetcode.com/problems/search-a-2d-matrix

int getRow (vector<vector<int>>& matrix, int target){
    int lo=0,hi=matrix.size()-1,ans=0;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(matrix[mid][0]<=target){
            ans = mid;
            lo = mid+1;
        }
        else {
            hi = mid-1;
        }
    }
    return ans;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = getRow(matrix,target);
    int lo = 0, hi = matrix[0].size()-1;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        int val = matrix[row][mid];
        if(val==target){
            return true;
        }
        else if(val<target){
            lo = mid+1;
        }
        else {
            hi = mid-1;
        }
    }
    return false;
}

// https://leetcode.com/problems/search-a-2d-matrix-ii/

 bool searchMatrix2(vector<vector<int>>& matrix, int target) {
    int i = 0, j = matrix[0].size()-1;
    while(i<matrix.size()&&j>=0){
        int val = matrix[i][j];
        if(val==target) return true;
        else if(val<target) i++;
        else j--;
    }
    return false;
}

int main() {

    // function call

    return 0;
}