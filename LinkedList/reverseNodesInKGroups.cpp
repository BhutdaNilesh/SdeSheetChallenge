#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	// Write your code here.
    int len = 0;
    Node* dummy = new Node(0);
    dummy->next = head;
    Node* prev = dummy;
    Node* curr = dummy; 
    Node* next = dummy;
    
    Node* temp = head;
    while(temp){
        len++;
        temp = temp->next;
    }
    
    
    int j=0;
    while(len>0 && j<n){
        curr = prev->next;
        next = curr->next;
        int k = (b[j]<=len) ? b[j] : len;
        if(k==0){
            j++;
            continue;
        }
        for(int i=1;i<k;i++){
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
            next = curr->next;
        }
        prev = curr;
        len-=b[j];
        j++;
    }
    
    return dummy->next;
}