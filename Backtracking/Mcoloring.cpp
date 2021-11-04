#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1#

int color[22];
int N;

bool isPossible(bool g[101][101], int node, int c){
    for(int i=0;i<N;i++){
        if(g[node][i] && color[i]==c) return false;
    }
    return true;
}

bool solve(bool graph[101][101], int node, int v, int m){
    if(node>=v) return true;
    bool res = false;
    for(int c=1;c<=m;c++){
        if(isPossible(graph,node,c)){
            color[node] = c;
            if(solve(graph, node+1,v,m)) return res = true;
            color[node] = 0;
        }
    }
    return res;
}

bool graphColoring(bool graph[101][101], int m, int v)
{
    N = v;
    memset(color,0,sizeof(color));
    return solve(graph,0,v,m);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}