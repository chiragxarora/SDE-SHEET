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

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* newHead;
    ListNode* mainHead;
    ListNode* ptr = head;
    ListNode* newTail;
    ListNode* prevTail = new ListNode(0,head);
    int size = 0;
    while(ptr!=NULL){
        ptr = ptr->next;
        size++;
    }
    ListNode* curr = head;
    for(int i=1;i<=size/k;i++){
        ListNode *prev;
        for(int j=1;j<=k;j++){
            if(j==1) newTail = curr;
            if(j==k) newHead = curr;
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        if(i==1){
            mainHead = prev;
        }
        prevTail->next = newHead;
        prevTail = newTail; 
        newTail->next = NULL;
    }
    if(curr!=NULL) newTail->next = curr;
    return mainHead;
}

int main() {

    return 0;
}