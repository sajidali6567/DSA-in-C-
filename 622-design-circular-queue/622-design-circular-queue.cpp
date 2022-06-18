class MyCircularQueue {
public:
    vector<int> arr;
    int front, rear, size, cap;
    MyCircularQueue(int k) {
        arr.resize(k);
        front =0; rear = 0;
        size = 0; cap = k;
    }
    
    bool enQueue(int value) {
        if(size == cap) return false;
        arr[rear%cap] = value;
        size++; rear++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        front++; size-=1;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return arr[front%cap];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return arr[(rear-1)%cap];
    }
    
    bool isEmpty() {
        return (front == rear);
    }
    
    bool isFull() {
        return (size == cap);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */