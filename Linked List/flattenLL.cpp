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

// https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

Node *merge(Node* first, Node* second){
    Node* head = new Node(0);
    Node* curr = head;
    while(first!=NULL && second!=NULL){
        if(first->data < second->data){
            curr->bottom = first;
            first = first->bottom;
            curr = curr->bottom;
        }
        else {
            curr->bottom = second;
            second = second->bottom;
            curr = curr->bottom;
        }
    }
    if(first!=NULL){
        curr->bottom = first;
    }
    if(second!=NULL){
        curr->bottom = second;
    }
    head->bottom->next = NULL;
    return head->bottom;
}

Node *flatten(Node *root)
{
    Node* ans = new Node(0);
    while(root!=NULL&&root->next!=NULL){
        Node* tmp = root->next->next;
        Node* res = merge(root,root->next);
        root = res;
        root->next = tmp;
    }
    return root;
}

int main() {

    return 0;
}