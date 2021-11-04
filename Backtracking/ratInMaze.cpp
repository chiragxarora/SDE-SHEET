#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

vector<string>ans;

void solve(vector<vector<int>>& grid, int cr, int cc, string res){
    if(cr==grid.size()-1&&cc==grid[0].size()-1&&grid[cr][cc]==1){
        ans.push_back(res);
        return;
    }
    if(cr<0||cc<0||cr>=grid.size()||cc>=grid[0].size()||grid[cr][cc]==0||grid[cr][cc]==-1) return;
    grid[cr][cc] = -1;  // marking as visited
    solve(grid,cr+1,cc,res+"D");
    solve(grid,cr,cc-1,res+"L");
    solve(grid,cr,cc+1,res+"R");
    solve(grid,cr-1,cc,res+"U");
    grid[cr][cc] = 1;  // undo the changes
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}