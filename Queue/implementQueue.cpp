class Queue {
    int *arr;
    int frontt;
    int rear;
    int size;
    int cnt;
public:
    Queue() {
        // Implement the Constructor
        cnt=0;
        size = 100001;
        arr = new int[size];
        frontt=0;
        rear=0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(cnt==0) return true;
        else return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(cnt==size) return;
        arr[rear%size] = data;
        rear++;
        cnt++;
    }

    int dequeue() {
        // Implement the dequeue() function
        if(cnt==0) return -1;
        int x = arr[frontt%size];
        arr[frontt%size]=-1;
        frontt++;
        if(frontt==rear){
            frontt=0;
            rear=0;
        }
        cnt--;
        return x;
        
    }

    int front() {
        // Implement the front() function
        if(cnt==0) return -1;
        return arr[frontt%size];
    }
};