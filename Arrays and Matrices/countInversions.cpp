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

// https://www.geeksforgeeks.org/counting-inversions/

int approach1(vector<int>& arr) {
    int cnt = 0;
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[i]>arr[j]){
                cnt++;
            }
        }
    }
    return cnt;
}

long long merge(vector<int>& arr, int i1, int j1, int i2, int j2){
    vector<int> temp (arr.size());
    long long i=i1,j=i2,k=i1,cnt=0;
    while(i<=j1&&j<=j2){
        if(arr[i] > arr[j]){
            temp[k++] = arr[j++];
            cnt += j1-i+1;
        }
        else {
            temp[k++] = arr[i++];
        }
    }
    while(i<=j1){
        temp[k++] = arr[i++];
    }
    while(j<=j2){
        temp[k++] = arr[j++];
    }
    for(int i=i1;i<=j2;i++){
        arr[i] = temp[i];
    }
    return cnt;
}

long long help(vector<int>& arr, int i, int j) {
    if(i>=j) return 0;
    int mid = i+(j-i)/2;
    long long leftInversions = help(arr,i,mid);
    long long rightInversions = help(arr,mid+1,j);
    long long crossInversions = merge(arr,i,mid,mid+1,j);
    return leftInversions + rightInversions + crossInversions;
}

int approach2(vector<int>& arr){
    return help(arr,0,arr.size()-1);
}

int main() {
    vector<int> v {8,4,2,1};
    cout<<approach1(v)<<endl;
    cout<<approach2(v)<<endl;
    return 0;
}