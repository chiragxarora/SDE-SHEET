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

ListNode* removeNthFromEnd(ListNode* head, int n) {
    int i=0;
    ListNode* dummy = new ListNode(0,head);
    ListNode* fast = dummy;
    ListNode* slow = dummy;
    while(fast!=NULL){
        if(i>n){
            slow = slow->next;
        }
        fast = fast->next;
        i++;
    }
    slow->next = slow->next->next;
    return dummy->next;
}

int main() {

    return 0;
}