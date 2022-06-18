class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {

    }
    
    void push(int x) {
        q1.push(x);
    }

    void clearQueue(queue<int>& q) {
        while(!q.empty()) {
            q.pop();
        }
    }
    
    int pop() {
        int sz = q1.size()-1;
        while(sz--) {
            q2.push(q1.front());
            q1.pop();
        }
        int top = q1.front();
        q1.pop();
        q1 = q2;
        clearQueue(q2);
        return top;
    }
    
    int top() {
        return q1.back();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */