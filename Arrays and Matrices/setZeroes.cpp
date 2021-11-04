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

// https://leetcode.com/problems/set-matrix-zeroes/

void approach1(vector<vector<int>>& matrix) {
    int r[202], c[202];
    memset(r,-1,sizeof(r));
    memset(c,-1,sizeof(c));
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[i][j]==0){
                r[i] = 0;
                c[j] = 0;
            }
        }
    }
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            if(r[i]==0||c[j]==0){
                matrix[i][j]=0;
            }
        }
    }
}

void approach2(vector<vector<int>>& matrix) {
    bool col = true;
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[i][j]==0){
                if(j==0) col = false;
                else {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
    }
    for(int i=matrix.size()-1;i>=0;i--){
        for(int j=matrix[0].size()-1;j>=0;j--){
            if(j==0){
                if(!col) matrix[i][j] = 0;
            } else {
                if(matrix[0][j]==0||matrix[i][0]==0){
                    matrix[i][j] = 0;
                }
            }
        }
    }
}

int main() {
    vector<vector<int>> matrix {{1,1,1},{1,0,1},{1,1,1}};
    //approach1(matrix);
    approach2(matrix);
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}