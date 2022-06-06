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

int findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    unordered_set<Node*>mp;
    Node* temp1 = firstHead;
    Node* temp2 = secondHead;
    while(temp1){
        mp.insert(temp1);
        temp1 = temp1->next;
    }
    
    while(temp2){
        if(mp.find(temp2)!=mp.end()) return temp2->data;
        temp2 = temp2->next;
    }
    return -1;
}