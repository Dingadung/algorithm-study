class MyQueue {
    stack<int> s1, s2;
public:
    MyQueue() {
    }
    
    void push(int x) {
        if(!s1.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        s1.push(x);
        if(!s2.empty()){ 
            while(!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
        }
    }
    
    
    int pop() {
        int v = s1.top();
        s1.pop();
        return v;
    }
    
    int peek() {
        int v = s1.top();
        return v;
    }
    
    bool empty() {
        if(s1.empty())return true;
        else return false;
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