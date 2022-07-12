#include<bits/stdc++.h>

void SortedInsert(stack<int>& stack, int x){
    if(stack.empty() || stack.top()<x){
        stack.push(x);
        return;
    }
    int num = stack.top();
    stack.pop();
    SortedInsert(stack, x);
    stack.push(num);
}
void sortStack(stack<int> &stack)
{
	// Write your code here
    if(stack.empty()) return;
    int num = stack.top();
    stack.pop();
    sortStack(stack);
    SortedInsert(stack,num);
}