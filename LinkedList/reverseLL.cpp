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

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    LinkedListNode<int> * curr = head;
    LinkedListNode<int> *prev= NULL;
    while(curr){
        LinkedListNode<int>* next_ptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_ptr;
        
    }
    return prev;
}