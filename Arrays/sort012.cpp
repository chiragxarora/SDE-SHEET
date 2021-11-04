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

// Sort an array of 0’s 1’s 2’s without using extra space or sorting algo

/*
    We will take three pointers lo, mid, hi
    we will make sure that all the elements on left of lo are ZERO 0
    and all the elements on right of hi are TWO 2
    and in the middle we have mixed elements
    Now we will do appropriate swapping and make the middle elements all ONE 1
*/

int main() {
    vector<int> v{0,2,1,2,1,0,0,1,2,1,2,0,1};
    int lo = 0, mid = 0, hi = v.size()-1;
    while(mid<=hi){
        if(v[mid]==0){
            swap(v[mid],v[lo]);
            lo++;
            mid++;
        }
        else if(v[mid]==2){
            swap(v[mid],v[hi]);
            hi--;
        }
        else {
            mid++;
        }
    }
    for(auto vi : v) cout<<vi<<" ";
    cout<<endl;
    return 0;
}