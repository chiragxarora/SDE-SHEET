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

ListNode* reverseList(ListNode* head) {
    ListNode* curr = head;
    ListNode* last = NULL;
    while(curr!=NULL){
        ListNode* next = curr->next;
        curr->next = last;
        last = curr;
        curr = next;
    }
    return last;
}

ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast!=NULL&&fast->next!=NULL){
        fast = fast->next->next;
        if(fast==NULL) break;
        slow = slow->next;
    }
    return slow;
}

bool isPalindrome(ListNode* head) {
    if(head==NULL || head->next==NULL) return head;
    ListNode* mid = middleNode(head);
    ListNode* right = reverseList(mid->next);
    while(right!=NULL){
        if(head->val!=right->val) return false;
        head = head->next;
        right = right->next;
    }
    reverseList(mid->next);
    return true;
}

int main() {

    return 0;
}


