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

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

int approach1(vector<int>& prices) {
    vector<int> rmax(prices.size());
    rmax[prices.size()-1] = prices[prices.size()-1];
    for(int i=prices.size()-2;i>=0;i--){
        rmax[i] = max(rmax[i+1],prices[i]);
    }
    int ans =  0;
    for(int i=0;i<prices.size()-1;i++){
        ans = max(ans,rmax[i+1]-prices[i]);
    }
    if(ans<0) ans = 0;
    return ans;
}

int approach2(vector<int>& prices){
    int ans = 0, prevMin = prices[0];
    for(int i=1;i<prices.size();i++){
        if(prices[i]-prevMin > ans){
            ans = prices[i]-prevMin;
        }
        prevMin = min(prevMin,prices[i]);
    }
    return ans;
}

int main() {
    vector<int> v {7,1,5,3,6,4};
    cout<<approach1(v)<<endl;
    cout<<approach2(v)<<endl;
    return 0;
}