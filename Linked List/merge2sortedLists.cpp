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

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode(0);
    ListNode* hh = head;
    while(l1!=NULL && l2!=NULL){
        if(l1->val > l2->val) {
            head->next = l2;
            l2 = l2->next;
            head = head->next;
        }
        else {
            head->next = l1;
            l1 = l1->next;
            head = head->next;
        }
    }
    if(l1!=NULL){
        head->next = l1;
    }
    if(l2!=NULL){
        head->next = l2;
    }
    return hh->next;
}

int main() {

    return 0;
}



