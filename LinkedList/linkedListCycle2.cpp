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

Node *firstNode(Node *head)
{
	//    Write your code here.
    set<Node*>mp;
    Node* curr = head;
    while(curr){
        if(mp.find(curr)!=mp.end()){
            return curr;
        }
        mp.insert(curr);
        curr = curr->next;
    }
    return NULL;
}