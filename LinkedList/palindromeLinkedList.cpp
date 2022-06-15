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

bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    
    LinkedListNode<int>* temp = head;
    stack<int>st;
    while(temp){
        st.push(temp->data);
        temp = temp->next;
    }
    LinkedListNode<int>* curr = head;
    while(!st.empty()){
        if(curr->data!=st.top()){
            return false;
        }
        st.pop();
        curr = curr->next;
    }
    return true;

}