#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

void deleteNode(LinkedListNode<int> * node) {
    // Write your code here.
    if(!node) return;
    if(node->next==NULL) return;
    
    LinkedListNode<int>* temp =node->next;
    int v = node->data;
    node->data = temp->data;
    temp->data = v;
    node->next = temp->next;
    delete temp;
    
}