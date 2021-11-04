#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/sudoku-solver/

bool isSafe(vector<vector<char>>& b, int cr, int cc, int val) {
    for(int i=0;i<9;i++){
        int cell = (int)b[cr][i]-48;
        if(cell==val) return false;
    }
    for(int i=0;i<9;i++){
        int cell = (int)b[i][cc]-48;
        if(cell==val) return false;
    }
    int sr = (cr/3)*3, sc = (cc/3)*3;  // starting row and col of the current grid
    for(int i=sr;i<sr+3;i++){
        for(int j=sc;j<sc+3;j++){
            int cell = (int)b[i][j]-48;
            if(cell==val) return false;
        }
    }
    return true;
}

bool solve(vector<vector<char>>& b, vector<vector<int>>& visited, int cr, int cc) {
    if(cr==8&&cc==9){
        return true;
    }
    if(cc==9){
        cr++;
        cc=0;
    }
    if(cr==9) {
        return false;
    }
    if(visited[cr][cc]==-1){
        return solve(b,visited,cr,cc+1); 
    }
    for(int i=1;i<=9;i++){
        if(isSafe(b,cr,cc,i)){
            
            visited[cr][cc]=1;
            b[cr][cc] = to_string(i)[0];
            bool ans = solve(b,visited,cr,cc+1);
            visited[cr][cc]=0;
            if(ans) return true;
            b[cr][cc] = '.';
        }
        
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}