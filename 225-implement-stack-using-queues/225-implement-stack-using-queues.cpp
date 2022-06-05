class MyStack {
    private:
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        //the logic is that the newly added element should always reside at the front of the queue, so it can be popped first (like in a stack)
        q.push(x);
        int len = q.size()-1;
        for(int i = 0; i<len; i++)
            q.push(q.front()), q.pop();
    }
    
    int pop() {
        int t = q.front();
        q.pop();
        return t;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.size()==0;
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