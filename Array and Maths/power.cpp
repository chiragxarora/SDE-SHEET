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

// https://leetcode.com/problems/powx-n/

double power(double x, int N) {
    bool minus = false;
    if(N<0) minus = true;
    long long n = abs(N);
    double ans = 1.0;
    while(n!=0){
        if(n%2==1){
            ans *= x;
            n -= 1;
        }
        else {
            x *= x;
            n /= 2;
        }
    }
    if(minus){
        ans = 1 / ans ;
    }
    return ans;
}

int main() {
    cout<<power(5,-3)<<endl;
    return 0;
}