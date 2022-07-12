#include<bits/stdc++.h>
// Implement class for minStack.
class minStack
{
	// Write your code here.
    stack<int>st;
    multiset<int>ms;
	
	public:
		
		// Constructor
		minStack() 
		{ 
			// Write your code here.
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
		    st.push(num);
            ms.insert(num);

		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
            if(!st.empty()){
                int x = st.top();
                st.pop();
                ms.erase(ms.find(x));
                return x;
            }else{
                return -1;
            }
		}

		int top()
		{
			// Write your code here.
            if(!st.empty()){
                return st.top();
            }
            return -1;
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			// Write your code here.
            if(!st.empty()){
                return *(ms.begin());
            }else{
                return -1;
            }
		}
};