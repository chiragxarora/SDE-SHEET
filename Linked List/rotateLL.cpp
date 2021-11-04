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

ListNode* rotateRight(ListNode* head, int k) {
    if(head==NULL||k==0||head->next==NULL){
        return head;
    }
    ListNode *tail = head;
    int size = 1;
    while(tail->next!=NULL){
        tail = tail->next;
        size++;
    }
    if(k%size==0) return head;
    k = size - k%size - 1;
    ListNode* curr = head;
    while(k--){
        curr = curr->next;
    }
    ListNode* h = curr->next;
    curr->next = NULL;
    tail->next = head;
    return h;
}

int main() {

    return 0;
}