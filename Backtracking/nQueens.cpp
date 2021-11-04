#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/n-queens/

vector<vector<string>> ans;
int row[10], col[10], diagonal1[21], diagonal2[21];

bool isSafe(vector<vector<bool>>& NNboard, int r, int c) {
    if(row[r]||col[c]||diagonal1[r+c]||diagonal2[NNboard.size()-1+c-r]) return false;
    else return true;
}

void nQueens(vector<vector<bool>>& NNboard, int cr, int qpsf) {
    if(qpsf==NNboard.size()) {
        vector<string> res;
        for(int i=0;i<NNboard.size();i++){
            string str = "";
            for(int j=0;j<NNboard[0].size();j++){
                if(NNboard[i][j]) {
                    str +="Q";
                } else {
                    str +=".";
                }
            }
            res.push_back(str);
        }
        ans.push_back(res);
        return;
    }
    if(cr==NNboard.size()) {
        return;
    }
    for(int i=0;i<NNboard[0].size();i++){
        if(!NNboard[cr][i] && isSafe(NNboard,cr,i)) {
            NNboard[cr][i] = true;
            row[cr] = col[i] = diagonal1[cr+i] = diagonal2[NNboard.size()-1+i-cr] = 1;
            nQueens(NNboard,cr+1,qpsf+1);
            row[cr] = col[i] = diagonal1[cr+i] = diagonal2[NNboard.size()-1+i-cr] = 0;
            NNboard[cr][i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}