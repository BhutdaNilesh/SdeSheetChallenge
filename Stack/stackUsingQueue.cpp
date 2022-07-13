#include<bits/stdc++.h>
class Stack {
	// Define the data members.
    queue<int>q1,q2;
    int curr_size;
   public:
    Stack() {
        // Implement the Constructor.
        curr_size=0;
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return curr_size;
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        if(curr_size==0) return true;
        else return false;
    }

    void push(int element) {
        // Implement the push() function.
        q2.push(element);
        curr_size++;
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        queue<int>q = q1;
        q1 = q2;
        q2 = q;
    }

    int pop() {
        // Implement the pop() function.
        if(q1.empty()) return -1;
        int x = q1.front();
        q1.pop();
        curr_size--;
        return x;
    }

    int top() {
        // Implement the top() function.
        if(q1.empty()) return -1;
        return q1.front();
    }
};