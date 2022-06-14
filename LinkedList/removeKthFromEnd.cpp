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

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int k)
{
    // Write your code here.
    int len=0;
    if(k==0) return head;
    if(head==NULL || head->next==NULL) return NULL;
    
    LinkedListNode<int>* curr = head;
    
    
    while(curr){
        len++;
        curr = curr->next;
    }
    if(len==k) return head->next;
    
    int front = len - k;
    LinkedListNode<int>* temp = head;
    while(front>1){
        front--;
        temp = temp->next;
    }
    
    LinkedListNode<int>* to_delete = temp->next;
    temp->next = temp->next->next;
    delete to_delete;
    
    return head;
}


// using slow and fast pointer

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

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
    // Write your code here.
    LinkedListNode<int>* start = new LinkedListNode<int>(-1);
    start->next = head;
    LinkedListNode<int>* slow = start;
    LinkedListNode<int>* fast = start;
    if(K==0) return head;
    
    
    for(int i=0;i<K;i++){
        fast = fast->next;
    }
    
    while(fast->next!=NULL && fast){
        fast = fast->next;
        slow = slow->next;
    }
    
    slow->next = slow->next->next;
    return start->next;
}