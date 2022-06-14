#include <bits/stdc++.h> 
/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    Node<int>* dummy = new Node<int>(-1);
    Node<int>* temp = dummy;
    while(first && second){
        if(first->data<second->data){
            temp->next = new Node<int>(first->data);
            temp = temp->next;
            first = first->next;
        }else{
            temp->next = new Node<int>(second->data);
            temp = temp->next;
            second = second->next;
        }
    }
    
    while(first){
        temp->next = new Node<int>(first->data);
        temp = temp->next;
        first = first->next;
    }
    while(second){
        temp->next = new Node<int>(second->data);
        temp = temp->next;
        second = second->next;
    }
    
    return dummy->next;
}



// Better Approcach


#include <bits/stdc++.h> 
/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    if(first==NULL) return second;
    if(second==NULL) return first;
    
    if(first->data<second->data){
        first->next = sortTwoLists(first->next,second);
        return first;
    }else{
        second->next = sortTwoLists(second->next,first);
        return second;
    }
}
