#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/

bool cmp(pair<int,int> p1, pair<int,int> p2){
    return p1.second<p2.second;
}

int nMeetings(vector<pair<int,int>> intervals){
    sort(intervals.begin(),intervals.end(),cmp);
    int cnt = 1, lastEnd = intervals[0].second;
    for(int i=1;i<intervals.size();i++){
        if(intervals[i].first>lastEnd){
            cnt++;
            lastEnd = intervals[i].second;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}