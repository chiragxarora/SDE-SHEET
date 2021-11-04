#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620

struct Job {
    int id;
    int profit;
    int dead;
};

bool cmp(Job j1, Job j2) {
    return j1.profit > j2.profit;
}

bool dojob(int order[], int deadline, int id){
    for(int i=deadline;i>=1;i--){
        if(order[i]==-1){
            order[i] = id;
            return true;
        }
    }
    return false;
}

vector<int> JobScheduling(Job arr[], int n) 
{ 
    int order[102];
    memset(order,-1,sizeof(order));
    int profit = 0, cnt = 0;
    sort(arr, arr+n, cmp);
    for(int i=0;i<n;i++){
        if(dojob(order,arr[i].dead,arr[i].id)){
            cnt++;
            profit += arr[i].profit;
        }
    }
    vector<int> ans(2);
    ans[0] = cnt;
    ans[1] = profit;
    return ans;
} 



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}