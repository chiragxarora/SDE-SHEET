#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {
    unordered_map<Node*, Node*> map;
    Node* curr = head;
    while(curr!=NULL){
        Node* copy = new Node(curr->val);
        map[curr] = copy;
        curr = curr->next;
    }
    Node* hh = map[head];
    curr = head;
    while(curr!=NULL){
        Node* cr = map[curr];
        cr->next = map[curr->next];
        cr->random = map[curr->random];
        curr = curr->next;
    }
    return hh;
}

Node* copyRandomList2(Node* head) {
    if(head==NULL) return head;
    Node* curr = head;
    while(curr!=NULL){
        Node* next = curr->next;
        Node* nn = new Node(curr->val);
        curr-> next = nn;
        nn->next = next;
        curr = next;
    }
    curr = head;
    while(curr!=NULL&&curr->next!=NULL){
        Node* random = curr->random;
        if(random!=NULL){
            curr->next->random = random->next;
        }
        curr = curr->next->next;
    }
    Node* hh = head, *ans = head->next;
    curr = hh;
    while(curr!=NULL&&curr->next!=NULL&&curr->next->next!=NULL){
        Node* nxtCopy = curr->next;
        curr->next = curr->next->next;
        nxtCopy->next = nxtCopy->next->next;
        curr = curr->next;
    }
    curr->next = NULL;
    return ans;
}

int main() {

    return 0;
}