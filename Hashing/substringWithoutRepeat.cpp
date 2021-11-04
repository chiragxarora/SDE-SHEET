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

// https://leetcode.com/problems/longest-substring-without-repeating-characters/

int approach2(string s) {
    int i=0,j=0,ans=0;
    unordered_map<char,int> map;
    while(j<s.size()){
        map[s[j]]++;
        while(map[s[j]]>1){
            map[s[i]]--;
            i++;
        }
        ans = max(ans,j-i+1);
        j++;
    }
    return ans;
    return 0;
}

int approach3(string s) {
    int i=0,j=0,ans=0;
    unordered_map<char,int> map;
    while(j<s.size()){
        if(map.find(s[j])==map.end()){
            map[s[j]] = j;   
        }
        else {
            if(map[s[j]]>=i){
                i = map[s[j]]+1;
            }
            map[s[j]] = j;
        }
        ans = max(ans,j-i+1);
        j++;
    }
    return ans;
}

int main() {
    string str = "abcabcbb";
    cout<<approach2(str)<<endl;
    cout<<approach3(str)<<endl;
    return 0;
}