#include <bits/stdc++.h> 
/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    
    map<LinkedListNode<int>*, LinkedListNode<int>*>mp;
    
    LinkedListNode<int>* temp = head;
    while(temp){
        mp[temp] = new LinkedListNode<int>(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp){
        mp[temp]->next = mp[temp->next];
        mp[temp]->random = mp[temp->random];
        temp= temp->next;
    }
    return mp[head];
}




// Method 2: Space optimised

/*
// Definition for a Node.
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
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        Node* ptr = head;
        Node* front = head;
        
        while(ptr){
            front = ptr->next;
            Node* copy = new Node(ptr->val);
            ptr->next = copy;
            copy->next = front;
            ptr = front;
        }
        
        ptr = head;
        while(ptr){
            if(ptr->random!=NULL){
                ptr->next->random = ptr->random->next;
            }
            ptr = ptr->next->next;
        }
            
        ptr = head;
        Node* dummyHead = new Node(0);
        Node* copy = dummyHead;
            
        while(ptr){
            front = ptr->next->next;
            copy->next = ptr->next;
            ptr->next = front;
            copy = copy->next;
            ptr = front;
        }
        
        return dummyHead->next;
        
    }
};