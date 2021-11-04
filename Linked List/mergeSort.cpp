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

ListNode* mid(ListNode* head){
    ListNode *fast = head, *slow = head;
    while(fast!=NULL&&fast->next!=NULL){
        fast = fast->next->next;
        if(fast==NULL) return slow;
        slow = slow->next;
    }
    return slow;
}

ListNode* merge(ListNode* l1, ListNode* l2){
    ListNode* head = new ListNode(0);
    ListNode* h = head;
    while(l1!=NULL&&l2!=NULL){
        if(l1->val > l2->val){
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
    return h->next;
}

ListNode* sortList(ListNode* head) {
    if(head==NULL||head->next==NULL) return head;
    ListNode* md = mid(head);
    ListNode* l2 = md->next;
    ListNode* l1 = head;
    md->next = NULL;
    ListNode* h1 = sortList(l1);
    ListNode* h2 = sortList(l2);
    return merge(h1,h2);
}

int main() {

    return 0;
}