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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *getIntersectionNode(ListNode *l1, ListNode *l2) {
    ListNode*h1 = l1, *h2 = l2;
    int ll1 = 0, ll2 = 0;
    while(l1!=NULL || l2!=NULL){
        if(l1!=NULL){
            l1 = l1->next;
            ll1++;
        }
        if(l2!=NULL){
            l2 = l2->next;
            ll2++;
        }
    }
    if(ll1>ll2){
        int diff = ll1-ll2;
        int i = 0;
        ListNode*hh1 = h1, *hh2 = h2;
        while(hh1!=NULL&&hh2!=NULL){
            if(i<diff){
                hh1 = hh1->next;
            }
            else {
                if(hh1==hh2) return hh1;
                hh1 = hh1->next;
                hh2 = hh2->next;
                
            }
            i++;
        }
    }
    else {
        int diff = ll2-ll1;
        int i = 0;
        ListNode*hh1 = h1, *hh2 = h2;
        while(hh1!=NULL&&hh2!=NULL){
            if(i<diff){
                hh2 = hh2->next;
            }
            else {
                if(hh1==hh2) return hh1;
                hh1 = hh1->next;
                hh2 = hh2->next;
            }
            i++;
        }
    }
    return NULL;
}

// approach 2 

ListNode *getIntersectionNode2(ListNode *l1, ListNode *l2) {
    if(l1==NULL || l2==NULL) return NULL;
    ListNode *a = l1, *b = l2;
    while(a!=b){
        a = a==NULL ? l1 : a->next;
        b = b==NULL ? l2 : b->next;
    }
    return a;
}   

int main() {

    return 0;
}


