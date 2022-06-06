class MyQueue {
    //INTUITION: We use stack 1 for pushing elements only. Now as we know in stack, the order is going to get reversed as we pop out the elements
    //So to fix that we use another stack to cut out this reversing effect.
    //in stack 2, the elements will be stored in such a manner that the element popped should be as it would have been popped by a queue(in FIFO).
    //Because the reversing effect is cut out using stack 2.
public:
    stack<int> st1; //used for push 
    stack<int> st2; //used for peeking or popping
    
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x); 
    }
    
    int pop() {
        peek(); //to shift all elements from st1 to st2
        int popped = st2.top();
        st2.pop();
        return popped;
    }
    
    int peek() //shifts all elements from st1 to st2, if st2 is empty
    {
        if(st2.empty())
            while(!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        return st2.top();
    }
    
    bool empty() {
        return st1.empty() && st2.empty();
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