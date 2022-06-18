class MyQueue {
public:
    stack<int> st1; stack<int> st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        int sz = st1.size()-1;
        while(sz--) {
            st2.push(st1.top());
            st1.pop();
        }
        int top = st1.top(); st1.pop();
        // push st2 elements into st1
        while(!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
        return top;
    }
    
    int peek() {
        while(!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        int front = st2.top();
        while(!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
        return front;
    }
    
    bool empty() {
        return st1.empty();
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