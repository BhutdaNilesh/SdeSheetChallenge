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



// Method 2:

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
    Node* slow = head, *fast = head;
    
    if(head==NULL || head->next==NULL) return NULL;
    
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            fast = head;
            while(slow!=fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}