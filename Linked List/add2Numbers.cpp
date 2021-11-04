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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;
    ListNode* last = new ListNode(0);
    ListNode* hh = last;
    while(l1!=NULL && l2!=NULL){
        ListNode* curr = new ListNode();
        int val = l1->val + l2->val + carry;
        curr->val = val%10;
        last->next = curr;
        last = last->next;
        carry = val/10;
        l1 = l1->next;
        l2 = l2->next;
    }
    while(l1!=NULL){
        int val = carry + l1->val;
        ListNode* curr = new ListNode();
        curr->val = val%10;
        carry = val/10;
        last->next = curr;
        last = last->next;
        l1 = l1->next;
    }
    while(l2!=NULL){
        int val = carry + l2->val;
        ListNode* curr = new ListNode();
        curr->val = val%10;
        carry = val/10;
        last->next = curr;
        last = last->next;
        l2 = l2->next;
    }
    while(carry!=0){
        ListNode* curr = new ListNode();
        curr->val = carry%10;
        last->next = curr;
        last = last->next;
        carry /= 10;
    }
    return hh->next;
}

int main() {

    return 0;
}