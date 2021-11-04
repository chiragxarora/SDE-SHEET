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

// https://www.geeksforgeeks.org/efficiently-merging-two-sorted-arrays-with-o1-extra-space/

void approach1(vector<int>& v1, vector<int>& v2) {
    int a = 0;
    while(a<v1.size()) {
        if(v1[a]>v2[0]){
            // swap
            swap(v1[a],v2[0]);
            // rearrange
            int val = v2[0], i=0;
            while(i<v2.size()-1&&v2[i+1]<val) {
                v2[i] = v2[i+1];
                i++;
            }
            v2[i] = val;
        }
        a++;
    }
}

void approach2(vector<int>& v1, vector<int>& v2) {
    int i = 0, j = 0, k = v1.size()-1;
    while(i<=k && j<v2.size()){
        if(v1[i]>v2[j]){
            swap(v1[k],v2[j]);
            k--;
            j++;
        }
        i++;
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
}

void approach3(vector<int>& v1, vector<int>& v2) {
    int gap = ceil((v1.size() + v2.size())/2);
    int i = 0, j = gap;
    while(1) {
        i = 0;
        j = gap;
        while(j<v1.size() + v2.size()){
            int ii = i, jj = j;
            if(i>=v1.size()){
                ii -= v1.size();
                jj -= v1.size();
                if(v2[ii] > v2[jj]) swap(v2[ii],v2[jj]);
            }
            else {
                if(j>=v1.size()){
                    jj -= v1.size();
                    if(v1[ii] > v2[jj]) swap(v1[ii],v2[jj]);
                }
                else {
                    if(v1[ii] > v1[jj]) swap(v1[ii],v1[jj]);
                }
            }
            i++;
            j++;
        }
        if(gap==1) break;
        gap = ceil(gap/2);
    }
    for(auto v : v1) cout<<v<<" ";
    cout<<endl;
    for(auto v : v2) cout<<v<<" ";
    cout<<endl;
}

int main() {
    vector<int> v1 {1,4,7,8};
    vector<int> v2 {2,3,9};
    // approach1(v1,v2);
    // approach2(v1,v2);
    approach3(v1,v2);
    return 0;
}