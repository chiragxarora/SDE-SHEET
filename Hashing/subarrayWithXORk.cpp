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

// https://www.geeksforgeeks.org/count-number-subarrays-given-xor/

int approach2(vector<int> v, int k) {
    /* at any index in preXOR say preXOR is XR,
        now if we do partition of it in 2 parts, say A and B
        if XOR of A is x, and XOR of B is y
        then x ^ y = XR
        now putting y = k => x ^ k = XR
        taking XOR both sides, x = XR ^ k;
        for every partition we know XR, and we know k (target) already
        we need to find number of subarrays starting from 0th index with XOR equal to x;
        This will be the number of subarrays with XOR = k and those subarrays
        will be ending at current index in preXOR array.
    */
    vector<int> preXOR(v.size());
    int xr = 0, cnt = 0;
    unordered_map<int,int> map;
    for(int i=0;i<v.size();i++){
        xr = xr ^ v[i];
        preXOR[i] = xr;
        map[preXOR[i]]++;
        if(preXOR[i]==k) cnt++;
        // calculating XR ^ k
        int target = preXOR[i] ^ k;
        cnt += map[target];
    }
    return cnt;
}

int main() {
    vector<int> v {5, 6, 7, 8, 9};
    int targetXOR = 5;
    cout<<approach2(v,targetXOR)<<endl;
    return 0;
}