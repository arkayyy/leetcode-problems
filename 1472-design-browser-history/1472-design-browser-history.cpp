class BrowserHistory {
    private:
    stack<string> backs;
    stack<string> forwards;
public:
    BrowserHistory(string homepage) {
       backs.push(homepage);
    }
    
    void visit(string url) {
        while(!forwards.empty())
            forwards.pop();
        backs.push(url);
    }
    
    string back(int steps) {
        int c = steps;
        while(c && backs.size()>1)
            {forwards.push(backs.top()); backs.pop(); c--;}
        return backs.top();
    }
    
    string forward(int steps) {
        int c = steps;
        while(c && !forwards.empty())
        {
            backs.push(forwards.top()); forwards.pop(); c--;
        }
        return backs.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */