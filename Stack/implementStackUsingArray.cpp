class Stack {
    int *arr;
    int topp;
    int size;
    
public:
    
    Stack(int capacity) {
        this->size = capacity;
        arr = new int[size];
        topp = -1;
    }

    void push(int num) {
        if(topp-1!=size){
            arr[++topp]=num;
        }
    }

    int pop() {
       if(topp!=-1){
           int x = arr[topp];
           topp--;
           return x;
       }else{
           return -1;
       }
    }
    
    int top() {
        if(topp!=-1){
            return arr[topp];
        }else{
            return -1;
        }
    }
    
    int isEmpty() {
        return topp==-1;
    }
    
    int isFull() {
        return (topp-1)==size;
    }
};