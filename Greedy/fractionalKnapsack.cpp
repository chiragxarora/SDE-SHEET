#include <bits/stdc++.h>
using namespace std;

// 

bool cmp(pair<int,int> i1, pair<int,int> i2){
    return (double)(1.0*i1.first / i1.second) > (double)(1.0*i2.first / i2.second);
}

double knapsack(vector<pair<int,int>> v, int w, int n){
    sort(v.begin(),v.end(),cmp);
    //for(auto vi : v) cout<<vi.first<<" "<<vi.second<<" ";
    double profit = 0.0;
    for(int i=0;i<n;i++){
        if(w >= v[i].second){
            profit += v[i].first;
            w -= v[i].second;
        }
        else {
            profit += (double)((double)v[i].first / (double)v[i].second)*(double)(w);
            break;
        }
    }
    return profit;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}