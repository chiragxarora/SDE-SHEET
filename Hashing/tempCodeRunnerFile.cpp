#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <climits>
#include <utility>
#include <iomanip>

using namespace std;

// https://leetcode.com/problems/3sum/

void approach1(vector<int> num){
    int len = num.size(), target = 0;
    vector<vector<int>> fn;
    if(len<3) return;
    unordered_map<int,int> map,freq;
    for(int i=0;i<len;i++){
        freq[num[i]]++;
    }
    vector<int> n;
    for(auto f : freq) {
        for(int i=1;i<=min(3,f.second);i++){
            n.push_back(f.first);
        }
    }
    len = n.size();
    for(int i=0;i<len;i++){
        map[n[i]] = i;
    }
    for(int i=0;i<len;i++){
        for(int j=i+1;j<len;j++){
            if(map.find(target-n[i]-n[j])!=map.end()&&map[target-n[i]-n[j]]!=i&&map[target-n[i]-n[j]]!=j){
                vector<int> xx(3);
                xx[0] = n[i];
                xx[1] = n[j];
                xx[2] = target-n[i]-n[j];
                sort(xx.begin(),xx.end());
                fn.push_back(xx);
            }
        }
    }
    set<vector<int>> set;
    for(auto f : fn){
        set.insert(f);
    }
    vector<vector<int>> ans;
    for(auto s : set){
        for(auto si : s) cout<<si<<" ";
        cout<<endl;
    }
}

int main() {
    vector<int> v {-1,0,1,2,-1,-4};
    approach1(v);
    return 0;
}