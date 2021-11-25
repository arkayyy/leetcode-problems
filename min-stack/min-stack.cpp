class MinStack {
public:
    
    struct node{
        node* next;
        int val;
        
        node()
        {
          next = NULL;  
        }
        node(int v)
        {
            next=NULL; val = v;
        }
    };
    
    node* head;

    
    MinStack() {
        head = new node();
    }
    
    void push(int val) {
        node* newNode = new node(val);
        newNode->next = head;
        head = newNode;
    }
    
    void pop() {
        
        head = head->next;
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() { int mini=INT_MAX;
        node* curr = head;
        while(curr->next) {mini=min(mini,curr->val);curr=curr->next;}
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */