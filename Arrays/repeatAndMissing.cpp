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

// https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/

void approach3(vector<int> v) {
    int rep = -1, miss = 0;
    for(int i=0;i<v.size();i++){
        if(rep!=-1&&v[i]==rep) continue;
        if(v[i]==i+1) continue;
        while(v[i]!=i+1){
            if(v[i]==v[v[i]-1]){
                rep = v[i];
                break;
            }
            swap(v[i],v[v[i]-1]);
        }
    }
    for(int i=0;i<v.size();i++){
        if(v[i]!=i+1){
            miss = i+1;
            break;
        }
    }
    cout<<rep<<" "<<miss<<endl;
}

void approach4(vector<int> v){
    long long givenSum = 0, actualSum = 0, n = v.size(), givenSqSum = 0, actualSqSum = 0;
    for(auto vi : v) {
        givenSum += vi;
        givenSqSum += vi*vi;
    }
    actualSum = (n*(n+1))/2;
    actualSqSum = (n*(n+1)*(2*n+1))/6;
    long long diff = abs(actualSum-givenSum), sqDiff = abs(actualSqSum-givenSqSum);
    long long sum = sqDiff/diff;
    int a,b;
    a = (diff+sum)/2;
    b = sum - a;
    int rep = 0, miss = 0;
    for(auto vi : v){
        if(vi==a){
            rep = vi;
            miss = b;
            break;
        }
        if(vi==b){
            rep = vi;
            miss = a;
            break;
        }
    }
    cout<<rep<<" "<<miss<<endl;
}

int main() {
    vector<int> v{1,2,7,5,5,4,3};
    approach3(v);  // modifies the input array
    approach4(v);  // doesnt work for bigger test cases
    return 0;
}