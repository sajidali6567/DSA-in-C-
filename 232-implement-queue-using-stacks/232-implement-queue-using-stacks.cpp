class MyQueue {
public:
    stack<int> st1; stack<int> st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        int front;
        if(!st2.empty()) {
            front = st2.top();st2.pop();
            return front;
        }
        while(!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        front = st2.top();st2.pop();
        return front;
    }
    
    int peek() {
        if(!st2.empty()) {
            return st2.top();
        }
        while(!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        return st2.top();
    }
    
    bool empty() {
        return st2.empty() && st1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */